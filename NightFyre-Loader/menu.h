#pragma once
#include "stdafx.h"

void _MAINMENU();
void select_S1();
void select_S2();
void select_S3();
void select_CA();
void select_FC3();
void select_DEATHLY_STILLNESS();

#pragma region  //ASSAULT CUBE
void select_ASSAULT_CUBE();
void _artASSAULTCUBE();
void MENU_ASSAULT_CUBE(string& HEALTH, string& AMMO, string& RECOIL, string& NOCLIP);
#pragma endregion

#pragma region //BINDING OF ISAAC
void select_ISAAC();
void _artISAAC();
void MENU_ISAAC(string& HEALTH, string& BOMBS, string& DAMAGE, string& FIRERATE, string& COINS);
#pragma endregion

#pragma region  //FINAL FANTASY 7
void select_FF7();
void _artFF7();
void MENU_FF7(string& HP, string& MP, string& GIL);
#pragma endregion

#pragma region //Call of Duty Series
void MENU_COD_SELECT();
void selectCODwaw();
void _artCODwaw();
void MENU_CODwaw(string& HEALTH, string& AMMO, string& rFIRE, string& FLY, string& LASER, string& PROMOD, string& FPS, string& xCENTx, string& POINTS);
#pragma endregion

//MAIN
void _clearConsole();
void _setConsole();
void _ReturnToMainMenu(bool& currentMENU, bool& currentGAME, bool& mainMENU);

//ART
void _artS1();
void _artS2();
void _artS3();
void _artCA();
void _artFC3();
void _artDEATHLYSTILLNESS();

//MENUS
void MENU_SOCOM_SELECT();
void MENU_SOCOM1(string& FPS, string& PERFECTSHOT/*, bool& GAME, bool& MENU*/);
void MENU_SOCOM2(string& FPS, string& PERFECTSHOT, string& FORCESTART, string& FOG, string& NVG, string& COLOR, string& WIDESCREEN, string& BRIGHTNESS/*, bool& GAME, bool& MENU*/);
void MENU_SOCOM3(string& FPS, string& PERFECTSHOT, string& NOSWAY);
void MENU_SOCOMCA(string& FPS, string& PERFECTSHOT, string& DEBUG, string& FORCESTART/*, bool& GAME, bool& MENU*/);
void MENU_FARCRY_3(string& money, string& ammo/*, bool& GAME, bool& MENU*/);
void MENU_DEATHLY_STILLNESS(string& ammo, string& yPOS);

//TOGGLES
void select_S1(bool& MENU, bool& TITLE_MENU, bool& gameMENU);
void select_S2(bool& MENU, bool& TITLE_MENU, bool& gameMENU);
void select_S3(bool& MENU, bool& TITLE_MENU, bool& gameMENU);
void select_CA(bool& MENU, bool& TITLE_MENU, bool& gameMENU);