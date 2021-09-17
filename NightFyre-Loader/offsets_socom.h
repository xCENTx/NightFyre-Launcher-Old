#pragma once
#include "stdafx.h"
//SOCOM 1
extern uintptr_t _S1playerPTR;				// Player Object
extern uintptr_t _S1framerate1_ADDR;
extern uintptr_t _S1framerate2_ADDR;
extern uintptr_t _S1nofog_ADDR;
extern uintptr_t _S1nopulse1_ADDR;
extern uintptr_t _S1nvgmod_ADDR;
extern uintptr_t _S1perfectshot1_ADDR;
extern uintptr_t _S1perfectshot2_ADDR;
extern uintptr_t _S1perfectshot3_ADDR;
extern uintptr_t _S1perfectshot4_ADDR;

//SOCOM 2
extern uintptr_t _S2playerPTR;				// Player Object
extern uintptr_t _S2fps1_ADDR;
extern uintptr_t _S2fps2_ADDR;
extern uintptr_t _S2fog_ADDR;
extern uintptr_t _S2forcestart_ADDR;
extern uintptr_t _S2mapBrightness1;
extern uintptr_t _S2mapBrightness2;
extern uintptr_t _S2mapBrightness3;
extern uintptr_t _S2nvgFIX;
extern uintptr_t _S2crosshairR;
extern uintptr_t _S2crosshairG;
extern uintptr_t _S2crosshairB;
extern uintptr_t _S2widescreen1;
extern uintptr_t _S2widescreen2;
extern uintptr_t _S2widescreen3;
extern uintptr_t _S2widescreen4;

//SOCOM 3     
extern uintptr_t _S3playerPTR;				// Player Object
extern uintptr_t _S3fps1_ADDR;
extern uintptr_t _S3fps2_ADDR;

//COMBINED ASSAULT
extern uintptr_t _CAplayerPtr_ADDR;        // Player Object
extern uintptr_t _CAforcestart_ADDR;       // ONLINE / LAN Force Start Match
extern uintptr_t _CAfps1_ADDR;             // Frame Rate
extern uintptr_t _CAfps2_ADDR;             // ""

///POINTER CHAINS
//SOCOM 2 PERFECT SHOT 
void _S2_POINTERS(uintptr_t& a, uintptr_t& b, uintptr_t& c, HANDLE process);
void _S2_POINTERS_2(uintptr_t& a, uintptr_t& b, uintptr_t& c, uintptr_t& d, uintptr_t& e, HANDLE& process);

//SOCOM 3 PERFECT SHOT
void _S3_POINTERS(uintptr_t& a, uintptr_t& b, HANDLE process);
void _S3_POINTERS2(uintptr_t& a, uintptr_t& b, uintptr_t& c, HANDLE process);

//SOCOM CA PERFECT SHOT
void _CA_POINTERS(uintptr_t& a, uintptr_t& b, uintptr_t& c, HANDLE& process);

//SOCOM CA STEADY AIM
void _CA_POINTERS_2(uintptr_t& a, uintptr_t& b, uintptr_t& c, uintptr_t& d, uintptr_t& e, HANDLE process);
///END POINTER CHAINS


//SOCOM 1 PERFECT SHOT
void SOCOM1_PERFECTSHOT_ON(bool& GameMenu, string& ACTIVE, HANDLE& process);
void SOCOM1_PERFECTSHOT_OFF(bool& GameMenu, string& INACTIVE, HANDLE& process);

//PERFECT SHOT
void _PS_ON(bool& GameMenu, bool& loop, string& ACTIVE);
void _PS_OFF(bool& LOOP, bool& bPS, bool& GameMenu, string& INACTIVE);

//FPS HACK
void _FPS_ON(string& ACTIVE, bool& MENU, uintptr_t& address, HANDLE& process);

void _FPS_OFF(string& ACTIVE, bool& MENU, uintptr_t& address, HANDLE& process);

//FORCE START
void _FORCESTART_S2_ON(string& ACTIVE, bool& MENU, HANDLE& process);
void _FORCESTART_S2_OFF(string& ACTIVE, bool& MENU, HANDLE& process);

void _FORCESTART_CA_ON(string& ACTIVE, bool& MENU, HANDLE& process);
void _FORCESTART_CA_OFF(string& ACTIVE, bool& MENU, HANDLE& process);

//CROSSHAIR COLOR
void _COLORCROSSHAIR1_S2(string& COLOR, bool& oldCOLOR, bool& newCOLOR, bool& gameMENU, bool& CCOLOR, HANDLE& process);
void _COLORCROSSHAIR2_S2(string& COLOR, bool& oldCOLOR, bool& newCOLOR, bool& gameMENU, bool& CCOLOR, HANDLE& process);
void _COLORCROSSHAIR3_S2(string& COLOR, bool& oldCOLOR, bool& newCOLOR, bool& gameMENU, bool& CCOLOR, HANDLE& process);
void _COLORCROSSHAIR4_S2(string& COLOR, bool& oldCOLOR, bool& newCOLOR, bool& gameMENU, bool& CCOLOR, HANDLE& process);
void _COLORCROSSHAIR5_S2(string& COLOR, bool& oldCOLOR, bool& newCOLOR, bool& gameMENU, bool& CCOLOR, HANDLE& process);

//WIDESCREEN HACKS
void _WIDESCREEN_S2_ON(string& ACTIVE, bool& MENU, HANDLE& process);
void _WIDESCREEN_S2_OFF(string& ACTIVE, bool& MENU, HANDLE& process);

//CLEAR
void _clear_FPS(uintptr_t& address, HANDLE& process, bool& gameFPS, string& FPS);
void _clear_FORCESTART_S2(string& ACTIVE, bool& gameFORCESTART, HANDLE& process);
void _clear_FORCESTART_CA(string& ACTIVE, bool& gameFORCESTART, HANDLE& process);
void _clear_WIDESCREEN(string& ACTIVE, bool& gameWIDESCREEN, HANDLE& process);

void _return_MAIN(bool& gameFPS, bool& gamePERFSHOT, bool& gameFORCE,
    bool& LOOP, HANDLE& process, string& SgameFPS,
    string& SgameFORCE, string& SgamePERFSHOT, bool& gameMENU, bool& game, bool& mMENU);

void _QUITfromSOCOM_2(bool& gameFPS, string& FPS, bool& gamePerfectShot, bool& LOOP, string& PSHOT,
    bool& gameFOG, string& FOG, bool& gameBRIGHTNESS, string& BRIGHTNESS, bool& gameFORCE,
    string& FORCE, bool& gameNVG, string& NVG, bool& bcolor0, bool& bcolor1, bool& bcolor2,
    bool& bcolor3, bool& bcolor4, bool& mainCOLOR, string& COLOR, bool& gameWIDESCREEN,
    string& WIDESCREEN, HANDLE& process);

namespace SOCOM
{
    void _return(HANDLE& PROCESS, bool& MENU, bool& HACK1, string& sHACK1, bool& HACK2, string& sHACK2, bool LOOP,
        bool& HACK3, string& sHACK3, bool& HACK4, bool& HACK5, string& sHACK5,
        bool& HACK6, string& sHACK6, bool& HACK7, string& sHACK7);
}