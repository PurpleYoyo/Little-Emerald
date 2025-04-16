#include "global.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "starter_choose.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "event_data.h"
#include "random.h"

#define STARTER_MON_COUNT   3

// Position of the sprite of the selected starter Pokémon
#define STARTER_PKMN_POS_X (DISPLAY_WIDTH / 2)
#define STARTER_PKMN_POS_Y 64

#define TAG_POKEBALL_SELECT 0x1000
#define TAG_STARTER_CIRCLE  0x1001

static void CB2_StarterChoose(void);
static void ClearStarterLabel(void);
static void Task_StarterChoose(u8 taskId);
static void Task_HandleStarterChooseInput(u8 taskId);
static void Task_WaitForStarterSprite(u8 taskId);
static void Task_AskConfirmStarter(u8 taskId);
static void Task_HandleConfirmStarterInput(u8 taskId);
static void Task_DeclineStarter(u8 taskId);
static void Task_MoveStarterChooseCursor(u8 taskId);
static void Task_CreateStarterLabel(u8 taskId);
static void CreateStarterPokemonLabel(u8 selection);
static u8 CreatePokemonFrontSprite(u16 species, u8 x, u8 y);
static void SpriteCB_SelectionHand(struct Sprite *sprite);
static void SpriteCB_Pokeball(struct Sprite *sprite);
static void SpriteCB_StarterPokemon(struct Sprite *sprite);
static void GetMonotypeStarters(void);

EWRAM_DATA u16 sStarterMon[STARTER_MON_COUNT] = {0};

static u16 sStarterLabelWindowId;

const u16 gBirchBagGrass_Pal[] = INCBIN_U16("graphics/starter_choose/tiles.gbapal");
static const u16 sPokeballSelection_Pal[] = INCBIN_U16("graphics/starter_choose/pokeball_selection.gbapal");
static const u16 sStarterCircle_Pal[] = INCBIN_U16("graphics/starter_choose/starter_circle.gbapal");
const u32 gBirchBagTilemap[] = INCBIN_U32("graphics/starter_choose/birch_bag.bin.lz");
const u32 gBirchGrassTilemap[] = INCBIN_U32("graphics/starter_choose/birch_grass.bin.lz");
const u32 gBirchBagGrass_Gfx[] = INCBIN_U32("graphics/starter_choose/tiles.4bpp.lz");
const u32 gPokeballSelection_Gfx[] = INCBIN_U32("graphics/starter_choose/pokeball_selection.4bpp.lz");
static const u32 sStarterCircle_Gfx[] = INCBIN_U32("graphics/starter_choose/starter_circle.4bpp.lz");

static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 15,
        .width = 24,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 0x0200
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate sWindowTemplate_ConfirmStarter =
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 14,
    .baseBlock = 0x0260
};

static const struct WindowTemplate sWindowTemplate_StarterLabel =
{
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 13,
    .height = 4,
    .paletteNum = 14,
    .baseBlock = 0x0274
};

static const u8 sPokeballCoords[STARTER_MON_COUNT][2] =
{
    {60, 64},
    {120, 88},
    {180, 64},
};

static const u8 sStarterLabelCoords[STARTER_MON_COUNT][2] =
{
    {0, 9},
    {16, 10},
    {8, 4},
};

static const struct BgTemplate sBgTemplates[3] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 6,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
};

static const u8 sTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY};

static const struct OamData sOam_Hand =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_Pokeball =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_StarterCircle =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const u8 sCursorCoords[][2] =
{
    {60, 32},
    {120, 56},
    {180, 32},
};

static const union AnimCmd sAnim_Hand[] =
{
    ANIMCMD_FRAME(48, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pokeball_Still[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pokeball_Moving[] =
{
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_StarterCircle[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd * const sAnims_Hand[] =
{
    sAnim_Hand,
};

static const union AnimCmd * const sAnims_Pokeball[] =
{
    sAnim_Pokeball_Still,
    sAnim_Pokeball_Moving,
};

static const union AnimCmd * const sAnims_StarterCircle[] =
{
    sAnim_StarterCircle,
};

static const union AffineAnimCmd sAffineAnim_StarterPokemon[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 0),
    AFFINEANIMCMD_FRAME(16, 16, 0, 15),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_StarterCircle[] =
{
    AFFINEANIMCMD_FRAME(20, 20, 0, 0),
    AFFINEANIMCMD_FRAME(20, 20, 0, 15),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd * const sAffineAnims_StarterPokemon = {sAffineAnim_StarterPokemon};
static const union AffineAnimCmd * const sAffineAnims_StarterCircle[] = {sAffineAnim_StarterCircle};

static const struct CompressedSpriteSheet sSpriteSheet_PokeballSelect[] =
{
    {
        .data = gPokeballSelection_Gfx,
        .size = 0x0800,
        .tag = TAG_POKEBALL_SELECT
    },
    {}
};

static const struct CompressedSpriteSheet sSpriteSheet_StarterCircle[] =
{
    {
        .data = sStarterCircle_Gfx,
        .size = 0x0800,
        .tag = TAG_STARTER_CIRCLE
    },
    {}
};

static const struct SpritePalette sSpritePalettes_StarterChoose[] =
{
    {
        .data = sPokeballSelection_Pal,
        .tag = TAG_POKEBALL_SELECT
    },
    {
        .data = sStarterCircle_Pal,
        .tag = TAG_STARTER_CIRCLE
    },
    {},
};

static const struct SpriteTemplate sSpriteTemplate_Hand =
{
    .tileTag = TAG_POKEBALL_SELECT,
    .paletteTag = TAG_POKEBALL_SELECT,
    .oam = &sOam_Hand,
    .anims = sAnims_Hand,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SelectionHand
};

static const struct SpriteTemplate sSpriteTemplate_Pokeball =
{
    .tileTag = TAG_POKEBALL_SELECT,
    .paletteTag = TAG_POKEBALL_SELECT,
    .oam = &sOam_Pokeball,
    .anims = sAnims_Pokeball,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Pokeball
};

static const struct SpriteTemplate sSpriteTemplate_StarterCircle =
{
    .tileTag = TAG_STARTER_CIRCLE,
    .paletteTag = TAG_STARTER_CIRCLE,
    .oam = &sOam_StarterCircle,
    .anims = sAnims_StarterCircle,
    .images = NULL,
    .affineAnims = sAffineAnims_StarterCircle,
    .callback = SpriteCB_StarterPokemon
};

u16 GetStarterPokemon(u16 chosenStarterId)
{
    if (chosenStarterId > STARTER_MON_COUNT)
        chosenStarterId = 0;
    return sStarterMon[chosenStarterId];
}

static void VblankCB_StarterChoose(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

// Data for Task_StarterChoose
#define tStarterSelection   data[0]
#define tPkmnSpriteId       data[1]
#define tCircleSpriteId     data[2]

// Data for sSpriteTemplate_Pokeball
#define sTaskId data[0]
#define sBallId data[1]

void GetMonotypeStarters(void)
{
    static const u16 sFire[] = {
        SPECIES_SUNKERN,
        SPECIES_DEERLING_SUMMER,
        SPECIES_CAPSAKID,
        SPECIES_SIZZLIPEDE,
        SPECIES_LARVESTA,
        SPECIES_LITLEO,
        SPECIES_CHIMCHAR,
        SPECIES_HOUNDOUR,
        SPECIES_LITTEN,
        SPECIES_TORCHIC,
        SPECIES_VULPIX,
        SPECIES_CYNDAQUIL,
        SPECIES_DARUMAKA,
        SPECIES_FUECOCO,
        SPECIES_FLETCHLING,
        SPECIES_GROWLITHE,
        SPECIES_PONYTA,
        SPECIES_TEPIG,
        SPECIES_SCORBUNNY,
        SPECIES_NUMEL,
        SPECIES_GROWLITHE_HISUI,
        SPECIES_ROLYCOLY,
        SPECIES_CHARMANDER,
        SPECIES_SLUGMA,
        SPECIES_SALANDIT,
        SPECIES_PANSEAR,
        SPECIES_FENNEKIN,
        SPECIES_DARUMAKA_GALAR,
        SPECIES_LITWICK,
        SPECIES_CHARCADET,
        SPECIES_MAGBY
    };

    static const u16 sDark[] = {
        SPECIES_NYMBLE,
        SPECIES_ZIGZAGOON_GALAR,
        SPECIES_RATTATA_ALOLA,
        SPECIES_SCRAGGY,
        SPECIES_IMPIDIMP,
        SPECIES_POOCHYENA,
        SPECIES_PURRLOIN,
        SPECIES_MASCHIFF,
        SPECIES_NICKIT,
        SPECIES_MEOWTH_ALOLA,
        SPECIES_CARVANHA,
        SPECIES_INKAY,
        SPECIES_VULLABY,
        SPECIES_STUNKY,
        SPECIES_SANDILE,
        SPECIES_HOUNDOUR,
        SPECIES_LARVITAR,
        SPECIES_DEINO,
        SPECIES_ZORUA,
        SPECIES_GRIMER_ALOLA,
        SPECIES_PAWNIARD,
        SPECIES_LITTEN,
        SPECIES_MURKROW,
        SPECIES_QWILFISH_HISUI,
        SPECIES_SNEASEL
    };

    static const u16 sGrass[] = {
        SPECIES_GOSSIFLEUR,
        SPECIES_CHERUBI,
        SPECIES_SUNKERN,
        SPECIES_ODDISH,
        SPECIES_BELLSPROUT,
        SPECIES_CHIKORITA,
        SPECIES_HOPPIP,
        SPECIES_LOTAD,
        SPECIES_SEEDOT,
        SPECIES_SEWADDLE,
        SPECIES_COTTONEE,
        SPECIES_PETILIL,
        SPECIES_SMOLIV,
        SPECIES_BOUNSWEET,
        SPECIES_DEERLING_AUTUMN,
        SPECIES_DEERLING_WINTER,
        SPECIES_DEERLING_SUMMER,
        SPECIES_DEERLING_SPRING,
        SPECIES_BUDEW,
        SPECIES_SKIDDO,
        SPECIES_SPRIGATITO,
        SPECIES_VOLTORB_HISUI,
        SPECIES_CACNEA,
        SPECIES_BRAMBLIN,
        SPECIES_PARAS,
        SPECIES_BULBASAUR,
        SPECIES_LILEEP,
        SPECIES_TREECKO,
        SPECIES_SHROOMISH,
        SPECIES_EXEGGCUTE,
        SPECIES_TURTWIG,
        SPECIES_BURMY_PLANT,
        SPECIES_POLTCHAGEIST,
        SPECIES_SNIVY,
        SPECIES_PANSAGE,
        SPECIES_FOONGUS,
        SPECIES_CHESPIN,
        SPECIES_PHANTUMP,
        SPECIES_PUMPKABOO,
        SPECIES_ROWLET,
        SPECIES_CAPSAKID,
        SPECIES_TOEDSCOOL,
        SPECIES_FOMANTIS,
        SPECIES_MORELULL,
        SPECIES_GROOKEY,
        SPECIES_APPLIN,
        SPECIES_SNOVER,
        SPECIES_FERROSEED,
        SPECIES_TANGELA
    };

    static const u16 sWater[] = {
        SPECIES_LOTAD,
        SPECIES_SURSKIT,
        SPECIES_WIMPOD,
        SPECIES_DEWPIDER,
        SPECIES_BIDOOF,
        SPECIES_CLOBBOPUS,
        SPECIES_POPPLIO,
        SPECIES_CARVANHA,
        SPECIES_BUIZEL,
        SPECIES_WOOPER,
        SPECIES_MUDKIP,
        SPECIES_SHELLOS,        
        SPECIES_TYMPOLE,
        SPECIES_SOBBLE,
        SPECIES_WINGULL,
        SPECIES_KRABBY,
        SPECIES_WIGLETT,
        SPECIES_MAREANIE,
        SPECIES_TENTACOOL,
        SPECIES_FRILLISH,
        SPECIES_HORSEA,
        SPECIES_STARYU,
        SPECIES_REMORAID,
        SPECIES_WAILMER,
        SPECIES_CORPHISH,
        SPECIES_CLAMPERL,
        SPECIES_BINACLE,
        SPECIES_SKRELP,
        SPECIES_CLAUNCHER,
        SPECIES_FINIZEN,        
        SPECIES_ARROKUDA,
        SPECIES_SPHEAL,
        SPECIES_SEEL,
        SPECIES_SHELLDER,
        SPECIES_SQUIRTLE,
        SPECIES_PSYDUCK,
        SPECIES_POLIWAG,
        SPECIES_SLOWPOKE,
        SPECIES_GOLDEEN,
        SPECIES_MAGIKARP,
        SPECIES_TOTODILE,
        SPECIES_BARBOACH,
        SPECIES_FEEBAS,
        SPECIES_FINNEON,
        SPECIES_OSHAWOTT,
        SPECIES_DUCKLETT,
        SPECIES_FROAKIE,
        SPECIES_QUAXLY,
        SPECIES_CHEWTLE,
        SPECIES_PANPOUR,
        SPECIES_PIPLUP,
        SPECIES_CHINCHOU,
        SPECIES_BASCULIN_WHITE_STRIPED,
        SPECIES_OMANYTE,
        SPECIES_KABUTO,
        SPECIES_TIRTOUGA,
        SPECIES_MANTYKE
    };

    static const u16 sPoison[] = {
        SPECIES_ODDISH,
        SPECIES_BELLSPROUT,
        SPECIES_BUDEW,
        SPECIES_BULBASAUR,
        SPECIES_FOONGUS,
        SPECIES_SKORUPI,
        SPECIES_VENONAT,
        SPECIES_SPINARAK,
        SPECIES_VENIPEDE,
        SPECIES_SHROODLE,
        SPECIES_CROAGUNK,
        SPECIES_SNEASEL_HISUI,
        SPECIES_STUNKY,
        SPECIES_GRIMER_ALOLA,
        SPECIES_QWILFISH_HISUI,
        SPECIES_SALANDIT,
        SPECIES_MAREANIE,
        SPECIES_TENTACOOL,
        SPECIES_SKRELP,
        SPECIES_WOOPER_PALDEA,
        SPECIES_POIPOLE,
        SPECIES_ZUBAT,
        SPECIES_EKANS,
        SPECIES_NIDORAN_F,
        SPECIES_NIDORAN_M,
        SPECIES_GULPIN,
        SPECIES_TOXEL,
        SPECIES_SLOWPOKE_GALAR,
        SPECIES_VAROOM,
        SPECIES_TRUBBISH,
        SPECIES_GLIMMET,
        SPECIES_KOFFING,
        SPECIES_GRIMER,
        SPECIES_GASTLY
    };

    static const u16 sFlying[] = {
        SPECIES_HOPPIP,
        SPECIES_ROWLET,
        SPECIES_COMBEE,
        SPECIES_LEDYBA,
        SPECIES_SCYTHER,
        SPECIES_PIDGEY,
        SPECIES_SPEAROW,
        SPECIES_HOOTHOOT,
        SPECIES_TAILLOW,
        SPECIES_STARLY,
        SPECIES_PIDOVE,
        SPECIES_RUFFLET,
        SPECIES_PIKIPEK,
        SPECIES_VULLABY,
        SPECIES_FLETCHLING,
        SPECIES_WINGULL,
        SPECIES_DUCKLETT,
        SPECIES_MANTYKE,
        SPECIES_WATTREL,
        SPECIES_DODUO,
        SPECIES_GLIGAR,
        SPECIES_NOIBAT,
        SPECIES_NATU,
        SPECIES_ROOKIDEE,
        SPECIES_ZUBAT,
        SPECIES_WOOBAT,
        SPECIES_DRIFLOON,
        SPECIES_ARCHEN
    };

    static const u16 sRock[] = {
        SPECIES_ANORITH,
        SPECIES_DWEBBLE,
        SPECIES_LARVITAR,
        SPECIES_GROWLITHE_HISUI,
        SPECIES_ROLYCOLY,
        SPECIES_BINACLE,
        SPECIES_CHEWTLE,
        SPECIES_OMANYTE,
        SPECIES_KABUTO,
        SPECIES_TIRTOUGA,
        SPECIES_RHYHORN,
        SPECIES_GEODUDE,
        SPECIES_ONIX,
        SPECIES_TYRUNT,
        SPECIES_LILEEP,
        SPECIES_ARCHEN,
        SPECIES_GLIMMET,
        SPECIES_ARON,
        SPECIES_SHIELDON,
        SPECIES_CRANIDOS,
        SPECIES_NOSEPASS,
        SPECIES_BONSLY
    };

    static const u16 sGhost[] = {
        SPECIES_BRAMBLIN,
        SPECIES_POLTCHAGEIST,
        SPECIES_PHANTUMP,
        SPECIES_PUMPKABOO,
        SPECIES_ZORUA_HISUI,
        SPECIES_FRILLISH,
        SPECIES_BASCULIN_WHITE_STRIPED,
        SPECIES_SANDYGAST,
        SPECIES_GOLETT,
        SPECIES_YAMASK_GALAR,
        SPECIES_DREEPY,
        SPECIES_DRIFLOON,
        SPECIES_GASTLY,
        SPECIES_HONEDGE,
        SPECIES_SHUPPET,
        SPECIES_DUSKULL,
        SPECIES_YAMASK,
        SPECIES_SINISTEA,
        SPECIES_GREAVARD,
        SPECIES_GIMMIGHOUL,
        SPECIES_MISDREAVUS,
        SPECIES_CORSOLA_GALAR
    };

    static const u16 sPsychic[] = {
        SPECIES_EXEGGCUTE,
        SPECIES_BLIPBUG,
        SPECIES_GIRAFARIG,
        SPECIES_MEDITITE,
        SPECIES_RALTS,
        SPECIES_PONYTA_GALAR,
        SPECIES_MIME_JR,
        SPECIES_INKAY,
        SPECIES_FENNEKIN,
        SPECIES_SLOWPOKE,
        SPECIES_PSYDUCK,
        SPECIES_BALTOY,
        SPECIES_NATU,
        SPECIES_WOOBAT,
        SPECIES_BRONZOR,
        SPECIES_BELDUM,
        SPECIES_SPOINK,
        SPECIES_DROWZEE,
        SPECIES_MUNNA,
        SPECIES_GOTHITA,
        SPECIES_SOLOSIS,
        SPECIES_HATENNA,
        SPECIES_ELGYEM,
        SPECIES_ABRA,
        SPECIES_ESPURR,
        SPECIES_FLITTLE,
        SPECIES_COSMOG,
        SPECIES_WYNAUT,
        SPECIES_CHINGLING
    };

    static const u16 sSteel[] = {
        SPECIES_BURMY_TRASH,
        SPECIES_FERROSEED,
        SPECIES_SHELMET,
        SPECIES_TINKATINK,
        SPECIES_PAWNIARD,
        SPECIES_PIPLUP,
        SPECIES_MAGNEMITE,
        SPECIES_DIGLETT_ALOLA,
        SPECIES_DURALUDON,
        SPECIES_SANDSHREW_ALOLA,
        SPECIES_ROOKIDEE,
        SPECIES_VAROOM,
        SPECIES_MELTAN,
        SPECIES_CUFANT,
        SPECIES_ARON,
        SPECIES_BRONZOR,
        SPECIES_BELDUM,
        SPECIES_HONEDGE,
        SPECIES_KLINK,
        SPECIES_MEOWTH_GALAR,
        SPECIES_SHIELDON
    };

    static const u16 sIce[] = {
        SPECIES_DEERLING_WINTER,
        SPECIES_SNOVER,
        SPECIES_SNOM,
        SPECIES_VULPIX_ALOLA,
        SPECIES_DARUMAKA_GALAR,
        SPECIES_SPHEAL,
        SPECIES_SEEL,
        SPECIES_SWINUB,
        SPECIES_FRIGIBAX,
        SPECIES_BERGMITE,
        SPECIES_SNORUNT,
        SPECIES_VANILLITE,
        SPECIES_CETODDLE,
        SPECIES_SANDSHREW_ALOLA,
        SPECIES_CUBCHOO,
        SPECIES_AMAURA,
        SPECIES_SMOOCHUM
    };

    static const u16 sDragon[] = {
        SPECIES_APPLIN,
        SPECIES_YANMA,
        SPECIES_SWABLU,
        SPECIES_DEINO,
        SPECIES_CHARMANDER,
        SPECIES_HORSEA,
        SPECIES_GIBLE,
        SPECIES_GOOMY,
        SPECIES_DREEPY,
        SPECIES_DRATINI,
        SPECIES_JANGMO_O,
        SPECIES_BAGON,
        SPECIES_AXEW,
        SPECIES_NOIBAT,
        SPECIES_FRIGIBAX,
        SPECIES_POIPOLE,
        SPECIES_DURALUDON,
        SPECIES_TYRUNT
    };

    static const u16 sGround[] = {
        SPECIES_TURTWIG,
        SPECIES_BURMY_SANDY,
        SPECIES_TOEDSCOOL,
        SPECIES_NINCADA,
        SPECIES_BUNNELBY,
        SPECIES_SANDILE,
        SPECIES_NUMEL,
        SPECIES_WOOPER,
        SPECIES_MUDKIP,
        SPECIES_BARBOACH,
        SPECIES_WOOPER_PALDEA,
        SPECIES_SANDYGAST,
        SPECIES_DODUO,
        SPECIES_SANDSHREW,
        SPECIES_RHYHORN,
        SPECIES_PHANPY,
        SPECIES_HIPPOPOTAS,
        SPECIES_MUDBRAY,
        SPECIES_TRAPINCH,
        SPECIES_SILICOBRA,
        SPECIES_DRILBUR,
        SPECIES_DIGLETT_ALOLA,
        SPECIES_SWINUB,
        SPECIES_DIGLETT,
        SPECIES_GEODUDE,
        SPECIES_ONIX,
        SPECIES_CUBONE,
        SPECIES_BALTOY,
        SPECIES_GIBLE,
        SPECIES_GOLETT,
        SPECIES_YAMASK_GALAR,
        SPECIES_GLIGAR
    };

    static const u16 sElectric[] = {
        SPECIES_VOLTORB_HISUI,
        SPECIES_GRUBBIN,
        SPECIES_JOLTIK,
        SPECIES_HELIOPTILE,
        SPECIES_CHINCHOU,
        SPECIES_PAWMI,
        SPECIES_TADBULB,
        SPECIES_WATTREL,
        SPECIES_MAREEP,
        SPECIES_ELECTRIKE,
        SPECIES_SHINX,
        SPECIES_BLITZLE,
        SPECIES_TYNAMO,
        SPECIES_GEODUDE_ALOLA,
        SPECIES_MAGNEMITE,
        SPECIES_VOLTORB,
        SPECIES_YAMPER,
        SPECIES_TOXEL,
        SPECIES_PICHU,
        SPECIES_ELEKID
    };

    static const u16 sBug[] = {
        SPECIES_SEWADDLE,
        SPECIES_PARAS,
        SPECIES_BURMY_PLANT,
        SPECIES_BURMY_TRASH,
        SPECIES_BURMY_SANDY,
        SPECIES_COMBEE,
        SPECIES_KRICKETOT,
        SPECIES_LEDYBA,
        SPECIES_SURSKIT,
        SPECIES_KARRABLAST,
        SPECIES_SHELMET,
        SPECIES_GRUBBIN,
        SPECIES_CUTIEFLY,
        SPECIES_TAROUNTULA,
        SPECIES_NYMBLE,
        SPECIES_CATERPIE,
        SPECIES_WEEDLE,
        SPECIES_WURMPLE,
        SPECIES_SCATTERBUG,
        SPECIES_BLIPBUG,
        SPECIES_SIZZLIPEDE,
        SPECIES_SKORUPI,
        SPECIES_WIMPOD,
        SPECIES_DWEBBLE,
        SPECIES_RELLOR,
        SPECIES_DEWPIDER,
        SPECIES_VENONAT,
        SPECIES_SPINARAK,
        SPECIES_PINECO,
        SPECIES_NINCADA,
        SPECIES_VENIPEDE,
        SPECIES_SNOM,
        SPECIES_SCYTHER,
        SPECIES_YANMA,
        SPECIES_ANORITH
    };

    static const u16 sNormal[] = {
        SPECIES_SMOLIV,
        SPECIES_DEERLING_AUTUMN,
        SPECIES_RATTATA,
        SPECIES_MEOWTH,
        SPECIES_EEVEE,
        SPECIES_SENTRET,
        SPECIES_TEDDIURSA,
        SPECIES_ZIGZAGOON,
        SPECIES_WHISMUR,
        SPECIES_SKITTY,
        SPECIES_BIDOOF,
        SPECIES_GLAMEOW,
        SPECIES_PATRAT,
        SPECIES_LILLIPUP,
        SPECIES_MINCCINO,
        SPECIES_BUNNELBY,
        SPECIES_YUNGOOS,
        SPECIES_SHROODLE,
        SPECIES_TANDEMAUS,
        SPECIES_LECHONK,
        SPECIES_SKWOVET,
        SPECIES_ZIGZAGOON_GALAR,
        SPECIES_RATTATA_ALOLA,
        SPECIES_WOOLOO,
        SPECIES_PIDGEY,
        SPECIES_SPEAROW,
        SPECIES_HOOTHOOT,
        SPECIES_TAILLOW,
        SPECIES_STARLY,
        SPECIES_PIDOVE,
        SPECIES_RUFFLET,
        SPECIES_PIKIPEK,
        SPECIES_LICKITUNG,
        SPECIES_DUNSPARCE,
        SPECIES_LITLEO,
        SPECIES_HELIOPTILE,
        SPECIES_SLAKOTH,
        SPECIES_BUNEARY,
        SPECIES_STUFFUL,
        SPECIES_ZORUA_HISUI,
        SPECIES_PORYGON,
        SPECIES_AIPOM,
        SPECIES_GIRAFARIG,
        SPECIES_STANTLER,
        SPECIES_TYPE_NULL,
        SPECIES_HAPPINY,
        SPECIES_MUNCHLAX,
        SPECIES_IGGLYBUFF,
        SPECIES_AZURILL
    };

    static const u16 sFighting[] = {
        SPECIES_STUFFUL,
        SPECIES_MANKEY,
        SPECIES_MACHOP,
        SPECIES_TIMBURR,
        SPECIES_SCRAGGY,
        SPECIES_MIENFOO,
        SPECIES_PANCHAM,
        SPECIES_CROAGUNK,
        SPECIES_CRABRAWLER,
        SPECIES_CLOBBOPUS,
        SPECIES_MAKUHITA,
        SPECIES_CHIMCHAR,
        SPECIES_MEDITITE,
        SPECIES_SNEASEL_HISUI,
        SPECIES_FARFETCHD_GALAR,
        SPECIES_KUBFU,
        SPECIES_TYROGUE,
        SPECIES_RIOLU
    };

    static const u16 sFairy[] = {
        SPECIES_CHIKORITA,
        SPECIES_COTTONEE,
        SPECIES_DEERLING_SPRING,
        SPECIES_MORELULL,
        SPECIES_CUTIEFLY,
        SPECIES_IGGLYBUFF,
        SPECIES_AZURILL,
        SPECIES_SNUBBULL,
        SPECIES_RALTS,
        SPECIES_POPPLIO,
        SPECIES_FLABEBE,
        SPECIES_SPRITZEE,
        SPECIES_SWIRLIX,
        SPECIES_PONYTA_GALAR,
        SPECIES_VULPIX_ALOLA,
        SPECIES_IMPIDIMP,
        SPECIES_SWABLU,
        SPECIES_FIDOUGH,
        SPECIES_TINKATINK,
        SPECIES_MILCERY,
        SPECIES_CLEFFA,
        SPECIES_TOGEPI,
        SPECIES_MIME_JR
    };

    u16 species1Id = SPECIES_SNIVY;
    u16 species2Id = SPECIES_SCORBUNNY;
    u16 species3Id = SPECIES_SQUIRTLE;
    u16 length;

    switch (VarGet(VAR_MONOTYPE))
    {
        default:
        case MONOTYPE_NONE:
            break;
        case MONOTYPE_FIRE:
            length = 31;
            do {
                species1Id = sFire[Random() % length];
            } while (species1Id == species2Id);
            do {
                species3Id = sFire[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_GRASS:
            length = 50;
            do {
                species2Id = sGrass[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sGrass[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_WATER:
            length = 57;
            do {
                species1Id = sWater[Random() % length];
            } while (species1Id == species3Id);
            do {
                species2Id = sWater[Random() % length];
            } while (species2Id == species1Id || species2Id == species3Id);
            break;
        case MONOTYPE_DARK:
            length = 25;
            species1Id = sDark[Random() % length];
            do {
                species2Id = sDark[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sDark[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_POISON:
            length = 34;
            species1Id = sPoison[Random() % length];
            do {
                species2Id = sPoison[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sPoison[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_FLYING:
            length = 28;
            species1Id = sFlying[Random() % length];
            do {
                species2Id = sFlying[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sFlying[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_ROCK:
            length = 22;
            species1Id = sRock[Random() % length];
            do {
                species2Id = sRock[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sRock[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_GHOST:
            length = 22;
            species1Id = sGhost[Random() % length];
            do {
                species2Id = sGhost[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sGhost[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_PSYCHIC:
            length = 29;
            species1Id = sPsychic[Random() % length];
            do {
                species2Id = sPsychic[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sPsychic[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_STEEL:
            length = 21;
            species1Id = sSteel[Random() % length];
            do {
                species2Id = sSteel[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sSteel[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_ICE:
            length = 17;
            species1Id = sIce[Random() % length];
            do {
                species2Id = sIce[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sIce[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_DRAGON:
            length = 18;
            species1Id = sDragon[Random() % length];
            do {
                species2Id = sDragon[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sDragon[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_GROUND:
            length = 32;
            species1Id = sGround[Random() % length];
            do {
                species2Id = sGround[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sGround[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_ELECTRIC:
            length = 20;
            species1Id = sElectric[Random() % length];
            do {
                species2Id = sElectric[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sElectric[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_BUG:
            length = 35;
            species1Id = sBug[Random() % length];
            do {
                species2Id = sBug[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sBug[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_NORMAL:
            length = 49;
            species1Id = sNormal[Random() % length];
            do {
                species2Id = sNormal[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sNormal[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_FIGHTING:
            length = 18;
            species1Id = sFighting[Random() % length];
            do {
                species2Id = sFighting[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sFighting[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
        case MONOTYPE_FAIRY:
            length = 23;
            species1Id = sFairy[Random() % length];
            do {
                species2Id = sFairy[Random() % length];
            } while (species2Id == species1Id);
            do {
                species3Id = sFairy[Random() % length];
            } while (species3Id == species1Id || species3Id == species2Id);
            break;
    }
    sStarterMon[0] = species1Id;
    sStarterMon[1] = species2Id;
    sStarterMon[2] = species3Id;
}

void CB2_ChooseStarter(void)
{
    u8 taskId;
    u8 spriteId;

    SetVBlankCallback(NULL);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);

    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);

    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);

    LZ77UnCompVram(gBirchBagGrass_Gfx, (void *)VRAM);
    LZ77UnCompVram(gBirchBagTilemap, (void *)(BG_SCREEN_ADDR(6)));
    LZ77UnCompVram(gBirchGrassTilemap, (void *)(BG_SCREEN_ADDR(7)));

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    InitWindows(sWindowTemplates);

    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x2A8, BG_PLTT_ID(13));
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetAllPicSprites();

    LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    LoadPalette(gBirchBagGrass_Pal, BG_PLTT_ID(0), sizeof(gBirchBagGrass_Pal));
    LoadCompressedSpriteSheet(&sSpriteSheet_PokeballSelect[0]);
    LoadCompressedSpriteSheet(&sSpriteSheet_StarterCircle[0]);
    LoadSpritePalettes(sSpritePalettes_StarterChoose);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);

    EnableInterrupts(DISPSTAT_VBLANK);
    SetVBlankCallback(VblankCB_StarterChoose);
    SetMainCallback2(CB2_StarterChoose);

    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 7);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(2);
    ShowBg(3);

    GetMonotypeStarters();

    taskId = CreateTask(Task_StarterChoose, 0);
    gTasks[taskId].tStarterSelection = 1;

    // Create hand sprite
    spriteId = CreateSprite(&sSpriteTemplate_Hand, 120, 56, 2);
    gSprites[spriteId].data[0] = taskId;

    // Create three Poké Ball sprites
    spriteId = CreateSprite(&sSpriteTemplate_Pokeball, sPokeballCoords[0][0], sPokeballCoords[0][1], 2);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].sBallId = 0;

    spriteId = CreateSprite(&sSpriteTemplate_Pokeball, sPokeballCoords[1][0], sPokeballCoords[1][1], 2);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].sBallId = 1;

    spriteId = CreateSprite(&sSpriteTemplate_Pokeball, sPokeballCoords[2][0], sPokeballCoords[2][1], 2);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].sBallId = 2;

    sStarterLabelWindowId = WINDOW_NONE;
}

static void CB2_StarterChoose(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Task_StarterChoose(u8 taskId)
{
    CreateStarterPokemonLabel(gTasks[taskId].tStarterSelection);
    DrawStdFrameWithCustomTileAndPalette(0, FALSE, 0x2A8, 0xD);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_BirchInTrouble, 0, 1, 0, NULL);
    PutWindowTilemap(0);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_HandleStarterChooseInput;
}

static void Task_HandleStarterChooseInput(u8 taskId)
{
    u8 selection = gTasks[taskId].tStarterSelection;

    if (JOY_NEW(A_BUTTON))
    {
        u8 spriteId;

        ClearStarterLabel();

        // Create white circle background
        spriteId = CreateSprite(&sSpriteTemplate_StarterCircle, sPokeballCoords[selection][0], sPokeballCoords[selection][1], 1);
        gTasks[taskId].tCircleSpriteId = spriteId;

        // Create Pokémon sprite
        spriteId = CreatePokemonFrontSprite(GetStarterPokemon(gTasks[taskId].tStarterSelection), sPokeballCoords[selection][0], sPokeballCoords[selection][1]);
        gSprites[spriteId].affineAnims = &sAffineAnims_StarterPokemon;
        gSprites[spriteId].callback = SpriteCB_StarterPokemon;

        gTasks[taskId].tPkmnSpriteId = spriteId;
        gTasks[taskId].func = Task_WaitForStarterSprite;
    }
    else if (JOY_NEW(DPAD_LEFT) && selection > 0)
    {
        gTasks[taskId].tStarterSelection--;
        gTasks[taskId].func = Task_MoveStarterChooseCursor;
    }
    else if (JOY_NEW(DPAD_RIGHT) && selection < STARTER_MON_COUNT - 1)
    {
        gTasks[taskId].tStarterSelection++;
        gTasks[taskId].func = Task_MoveStarterChooseCursor;
    }
}

static void Task_WaitForStarterSprite(u8 taskId)
{
    if (gSprites[gTasks[taskId].tCircleSpriteId].affineAnimEnded &&
        gSprites[gTasks[taskId].tCircleSpriteId].x == STARTER_PKMN_POS_X &&
        gSprites[gTasks[taskId].tCircleSpriteId].y == STARTER_PKMN_POS_Y)
    {
        gTasks[taskId].func = Task_AskConfirmStarter;
    }
}

static void Task_AskConfirmStarter(u8 taskId)
{
    PlayCry_Normal(GetStarterPokemon(gTasks[taskId].tStarterSelection), 0);
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_ConfirmStarterChoice, 0, 1, 0, NULL);
    ScheduleBgCopyTilemapToVram(0);
    CreateYesNoMenu(&sWindowTemplate_ConfirmStarter, 0x2A8, 0xD, 0);
    gTasks[taskId].func = Task_HandleConfirmStarterInput;
}

static void Task_HandleConfirmStarterInput(u8 taskId)
{
    u8 spriteId;

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:  // YES
        // Return the starter choice and exit.
        gSpecialVar_Result = gTasks[taskId].tStarterSelection;
        ResetAllPicSprites();
        SetMainCallback2(gMain.savedCallback);
        break;
    case 1:  // NO
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        spriteId = gTasks[taskId].tPkmnSpriteId;
        FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
        FreeAndDestroyMonPicSprite(spriteId);

        spriteId = gTasks[taskId].tCircleSpriteId;
        FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
        DestroySprite(&gSprites[spriteId]);
        gTasks[taskId].func = Task_DeclineStarter;
        break;
    }
}

static void Task_DeclineStarter(u8 taskId)
{
    gTasks[taskId].func = Task_StarterChoose;
}

static void CreateStarterPokemonLabel(u8 selection)
{
    u8 categoryText[32];
    struct WindowTemplate winTemplate;
    const u8 *speciesName;
    s32 width;
    u8 labelLeft, labelRight, labelTop, labelBottom;

    u16 species = GetStarterPokemon(selection);
    CopyMonCategoryText(species, categoryText);
    speciesName = GetSpeciesName(species);

    winTemplate = sWindowTemplate_StarterLabel;
    winTemplate.tilemapLeft = sStarterLabelCoords[selection][0];
    winTemplate.tilemapTop = sStarterLabelCoords[selection][1];

    sStarterLabelWindowId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(sStarterLabelWindowId, PIXEL_FILL(0));

    width = GetStringCenterAlignXOffset(FONT_NARROW, categoryText, 0x68);
    AddTextPrinterParameterized3(sStarterLabelWindowId, FONT_NARROW, width, 1, sTextColors, 0, categoryText);

    width = GetStringCenterAlignXOffset(FONT_NORMAL, speciesName, 0x68);
    AddTextPrinterParameterized3(sStarterLabelWindowId, FONT_NORMAL, width, 17, sTextColors, 0, speciesName);

    PutWindowTilemap(sStarterLabelWindowId);
    ScheduleBgCopyTilemapToVram(0);

    labelLeft = sStarterLabelCoords[selection][0] * 8 - 4;
    labelRight = (sStarterLabelCoords[selection][0] + 13) * 8 + 4;
    labelTop = sStarterLabelCoords[selection][1] * 8;
    labelBottom = (sStarterLabelCoords[selection][1] + 4) * 8;
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(labelLeft, labelRight));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(labelTop, labelBottom));
}

static void ClearStarterLabel(void)
{
    FillWindowPixelBuffer(sStarterLabelWindowId, PIXEL_FILL(0));
    ClearWindowTilemap(sStarterLabelWindowId);
    RemoveWindow(sStarterLabelWindowId);
    sStarterLabelWindowId = WINDOW_NONE;
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    ScheduleBgCopyTilemapToVram(0);
}

static void Task_MoveStarterChooseCursor(u8 taskId)
{
    ClearStarterLabel();
    gTasks[taskId].func = Task_CreateStarterLabel;
}

static void Task_CreateStarterLabel(u8 taskId)
{
    CreateStarterPokemonLabel(gTasks[taskId].tStarterSelection);
    gTasks[taskId].func = Task_HandleStarterChooseInput;
}

static u8 CreatePokemonFrontSprite(u16 species, u8 x, u8 y)
{
    u8 spriteId;

    spriteId = CreateMonPicSprite_Affine(species, FALSE, 0, MON_PIC_AFFINE_FRONT, x, y, 14, TAG_NONE);
    gSprites[spriteId].oam.priority = 0;
    return spriteId;
}

static void SpriteCB_SelectionHand(struct Sprite *sprite)
{
    // Float up and down above selected Poké Ball
    sprite->x = sCursorCoords[gTasks[sprite->data[0]].tStarterSelection][0];
    sprite->y = sCursorCoords[gTasks[sprite->data[0]].tStarterSelection][1];
    sprite->y2 = Sin(sprite->data[1], 8);
    sprite->data[1] = (u8)(sprite->data[1]) + 4;
}

static void SpriteCB_Pokeball(struct Sprite *sprite)
{
    // Animate Poké Ball if currently selected
    if (gTasks[sprite->sTaskId].tStarterSelection == sprite->sBallId)
        StartSpriteAnimIfDifferent(sprite, 1);
    else
        StartSpriteAnimIfDifferent(sprite, 0);
}

static void SpriteCB_StarterPokemon(struct Sprite *sprite)
{
    // Move sprite to upper center of screen
    if (sprite->x > STARTER_PKMN_POS_X)
        sprite->x -= 4;
    if (sprite->x < STARTER_PKMN_POS_X)
        sprite->x += 4;
    if (sprite->y > STARTER_PKMN_POS_Y)
        sprite->y -= 2;
    if (sprite->y < STARTER_PKMN_POS_Y)
        sprite->y += 2;
}
