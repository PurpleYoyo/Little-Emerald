#ifndef GUARD_MAIN_MENU_H
#define GUARD_MAIN_MENU_H

extern EWRAM_DATA bool8 gNormalMode;
extern EWRAM_DATA bool8 gSandboxMode;
extern EWRAM_DATA bool8 gMonotype;

void CB2_InitMainMenu(void);
void CreateYesNoMenuParameterized(u8 x, u8 y, u16 baseTileNum, u16 baseBlock, u8 yesNoPalNum, u8 winPalNum);
void NewGameBirchSpeech_SetDefaultPlayerName(u8);

#endif // GUARD_MAIN_MENU_H
