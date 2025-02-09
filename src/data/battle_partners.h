//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/battle_partners.h' to remove #line markers.
//

#line 1 "src/data/battle_partners.party"

#line 1
    [PARTNER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 8
    [PARTNER_STEVEN] =
    {
#line 9
        .trainerName = _("STEVEN"),
#line 10
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender = 
#line 13
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15
            .species = SPECIES_DURALUDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15
            .heldItem = ITEM_EVIOLITE,
#line 19
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 17
            .ability = ABILITY_LIGHT_METAL,
#line 18
            .lvl = 48,
#line 16
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 19
                MOVE_REFLECT,
                MOVE_LIGHT_SCREEN,
                MOVE_DRAGON_TAIL,
                MOVE_METAL_BURST,
            },
            },
            {
#line 24
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 24
            .heldItem = ITEM_CHOICE_SPECS,
#line 28
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 26
            .ability = ABILITY_CLEAR_BODY,
#line 27
            .lvl = 49,
#line 25
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 28
                MOVE_STEEL_BEAM,
                MOVE_PSYCHIC,
                MOVE_FLASH_CANNON,
                MOVE_HYPER_BEAM,
            },
            },
            {
#line 33
            .species = SPECIES_PAWNIARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 33
            .heldItem = ITEM_FOCUS_SASH,
#line 37
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 35
            .ability = ABILITY_SUPREME_OVERLORD,
#line 36
            .lvl = 50,
#line 34
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 37
                MOVE_FOUL_PLAY,
                MOVE_IRON_HEAD,
                MOVE_X_SCISSOR,
                MOVE_BRICK_BREAK,
            },
            },
        },
    },
#line 42
    [PARTNER_BRENDAN_SNIVY] =
    {
#line 43
        .trainerName = _("BRENDAN"),
#line 44
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 45
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 47
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 48
        .doubleBattle = FALSE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 50
            .species = SPECIES_WOOPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 50
            .heldItem = ITEM_MYSTIC_WATER,
#line 54
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 52
            .ability = ABILITY_UNAWARE,
#line 51
            .lvl = 43,
#line 53
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 54
                MOVE_YAWN,
                MOVE_BULLDOZE,
                MOVE_AQUA_TAIL,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 59
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 59
            .heldItem = ITEM_FOCUS_SASH,
#line 63
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 61
            .ability = ABILITY_CHLOROPHYLL,
#line 60
            .lvl = 44,
#line 62
            .nature = NATURE_SASSY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 63
                MOVE_BULLET_SEED,
                MOVE_SYNTHESIS,
                MOVE_GROWTH,
                MOVE_SUNNY_DAY,
            },
            },
            {
#line 68
            .species = SPECIES_SCORBUNNY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 68
            .heldItem = ITEM_LIFE_ORB,
#line 72
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 70
            .ability = ABILITY_LIBERO,
#line 69
            .lvl = 45,
#line 71
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 72
                MOVE_ELECTRO_BALL,
                MOVE_HEAT_WAVE,
                MOVE_AGILITY,
                MOVE_SUPER_FANG,
            },
            },
        },
    },
#line 77
    [PARTNER_BRENDAN_SCORBUNNY] =
    {
#line 78
        .trainerName = _("BRENDAN"),
#line 79
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 80
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 82
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 83
        .doubleBattle = FALSE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 85
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 85
            .heldItem = ITEM_FOCUS_SASH,
#line 89
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 87
            .ability = ABILITY_CHLOROPHYLL,
#line 86
            .lvl = 43,
#line 88
            .nature = NATURE_SASSY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 89
                MOVE_BULLET_SEED,
                MOVE_SYNTHESIS,
                MOVE_GROWTH,
                MOVE_SUNNY_DAY,
            },
            },
            {
#line 94
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 94
            .heldItem = ITEM_SITRUS_BERRY,
#line 98
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 96
            .ability = ABILITY_UNNERVE,
#line 95
            .lvl = 44,
#line 97
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 98
                MOVE_FIRE_SPIN,
                MOVE_SWIFT,
                MOVE_SUNNY_DAY,
                MOVE_NOBLE_ROAR,
            },
            },
            {
#line 103
            .species = SPECIES_SQUIRTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 103
            .heldItem = ITEM_EVIOLITE,
#line 107
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 105
            .ability = ABILITY_TORRENT,
#line 104
            .lvl = 45,
#line 106
            .nature = NATURE_LONELY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 107
                MOVE_SHELL_SMASH,
                MOVE_WAVE_CRASH,
                MOVE_ICE_SPINNER,
                MOVE_DOUBLE_EDGE,
            },
            },
        },
    },
#line 112
    [PARTNER_BRENDAN_SQUIRTLE] =
    {
#line 113
        .trainerName = _("BRENDAN"),
#line 114
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 115
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 117
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 118
        .doubleBattle = FALSE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 120
            .species = SPECIES_LITLEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 120
            .heldItem = ITEM_SITRUS_BERRY,
#line 124
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 122
            .ability = ABILITY_UNNERVE,
#line 121
            .lvl = 43,
#line 123
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 124
                MOVE_FIRE_SPIN,
                MOVE_SWIFT,
                MOVE_SUNNY_DAY,
                MOVE_NOBLE_ROAR,
            },
            },
            {
#line 129
            .species = SPECIES_WOOPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 129
            .heldItem = ITEM_MYSTIC_WATER,
#line 133
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 131
            .ability = ABILITY_UNAWARE,
#line 130
            .lvl = 44,
#line 132
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 133
                MOVE_YAWN,
                MOVE_BULLDOZE,
                MOVE_AQUA_TAIL,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 138
            .species = SPECIES_SNIVY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 138
            .heldItem = ITEM_LEFTOVERS,
#line 142
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 140
            .ability = ABILITY_OVERGROW,
#line 139
            .lvl = 45,
#line 141
            .nature = NATURE_QUIET,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 142
                MOVE_SUBSTITUTE,
                MOVE_LEECH_SEED,
                MOVE_SYNTHESIS,
                MOVE_GIGA_DRAIN,
            },
            },
        },
    },
#line 147
    [PARTNER_MAY_SNIVY] =
    {
#line 148
        .trainerName = _("MAY"),
#line 149
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 150
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender = 
#line 151
F_TRAINER_FEMALE | 
#line 152
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 153
        .doubleBattle = FALSE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 155
            .species = SPECIES_DUCKLETT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 155
            .heldItem = ITEM_SHARP_BEAK,
#line 159
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 157
            .ability = ABILITY_BIG_PECKS,
#line 156
            .lvl = 43,
#line 158
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 159
                MOVE_AERIAL_ACE,
                MOVE_AQUA_JET,
                MOVE_FACADE,
                MOVE_FEATHER_DANCE,
            },
            },
            {
#line 164
            .species = SPECIES_CHERUBI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 164
            .heldItem = ITEM_FOCUS_SASH,
#line 168
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 166
            .ability = ABILITY_CHLOROPHYLL,
#line 165
            .lvl = 44,
#line 167
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 168
                MOVE_GIGA_DRAIN,
                MOVE_DRAINING_KISS,
                MOVE_GRASSWHISTLE,
                MOVE_SUNNY_DAY,
            },
            },
            {
#line 173
            .species = SPECIES_SCORBUNNY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 173
            .heldItem = ITEM_LIFE_ORB,
#line 177
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 175
            .ability = ABILITY_LIBERO,
#line 174
            .lvl = 45,
#line 176
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 177
                MOVE_ELECTRO_BALL,
                MOVE_HEAT_WAVE,
                MOVE_AGILITY,
                MOVE_SUPER_FANG,
            },
            },
        },
    },
#line 182
    [PARTNER_MAY_SCORBUNNY] =
    {
#line 183
        .trainerName = _("MAY"),
#line 184
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 185
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender = 
#line 186
F_TRAINER_FEMALE | 
#line 187
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 188
        .doubleBattle = FALSE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 190
            .species = SPECIES_CHERUBI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 190
            .heldItem = ITEM_FOCUS_SASH,
#line 194
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 192
            .ability = ABILITY_CHLOROPHYLL,
#line 191
            .lvl = 43,
#line 193
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 194
                MOVE_GIGA_DRAIN,
                MOVE_DRAINING_KISS,
                MOVE_GRASSWHISTLE,
                MOVE_SUNNY_DAY,
            },
            },
            {
#line 199
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 199
            .heldItem = ITEM_SITRUS_BERRY,
#line 203
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 201
            .ability = ABILITY_FLAME_BODY,
#line 200
            .lvl = 44,
#line 202
            .nature = NATURE_RELAXED,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 203
                MOVE_FLAME_CHARGE,
                MOVE_BODY_SLAM,
                MOVE_DOUBLE_TEAM,
                MOVE_SWAGGER,
            },
            },
            {
#line 208
            .species = SPECIES_SQUIRTLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 208
            .heldItem = ITEM_EVIOLITE,
#line 212
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 210
            .ability = ABILITY_TORRENT,
#line 209
            .lvl = 45,
#line 211
            .nature = NATURE_LONELY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 212
                MOVE_SHELL_SMASH,
                MOVE_WAVE_CRASH,
                MOVE_ICE_SPINNER,
                MOVE_DOUBLE_EDGE,
            },
            },
        },
    },
#line 217
    [PARTNER_MAY_SQUIRTLE] =
    {
#line 218
        .trainerName = _("MAY"),
#line 219
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 220
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender = 
#line 221
F_TRAINER_FEMALE | 
#line 222
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 223
        .doubleBattle = FALSE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 225
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 225
            .heldItem = ITEM_SITRUS_BERRY,
#line 229
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 227
            .ability = ABILITY_FLAME_BODY,
#line 226
            .lvl = 43,
#line 228
            .nature = NATURE_RELAXED,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 229
                MOVE_FLAME_CHARGE,
                MOVE_BODY_SLAM,
                MOVE_DOUBLE_TEAM,
                MOVE_SWAGGER,
            },
            },
            {
#line 234
            .species = SPECIES_DUCKLETT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 234
            .heldItem = ITEM_SHARP_BEAK,
#line 238
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 236
            .ability = ABILITY_BIG_PECKS,
#line 235
            .lvl = 44,
#line 237
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 238
                MOVE_AERIAL_ACE,
                MOVE_AQUA_JET,
                MOVE_FACADE,
                MOVE_FEATHER_DANCE,
            },
            },
            {
#line 243
            .species = SPECIES_SNIVY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 243
            .heldItem = ITEM_LEFTOVERS,
#line 247
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 245
            .ability = ABILITY_OVERGROW,
#line 244
            .lvl = 45,
#line 246
            .nature = NATURE_QUIET,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 247
                MOVE_SUBSTITUTE,
                MOVE_LEECH_SEED,
                MOVE_SYNTHESIS,
                MOVE_GIGA_DRAIN,
            },
            },
        },
    },
