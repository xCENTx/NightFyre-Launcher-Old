#include "stdafx.h"

uintptr_t _S1playerPTR = 0x2048D548;
uintptr_t _S1nofog_ADDR = 0x201E5AC0;
uintptr_t _S1nopulse1_ADDR = 0x202B3BD0;
uintptr_t _S1nopulse2_ADDR = 0x202B3BD4;
uintptr_t _S1framerate1_ADDR = 0x2048CF60;
uintptr_t _S1framerate2_ADDR = 0x2048CF64;
uintptr_t _S1nvgmod_ADDR = 0x202B9950;
uintptr_t _S1perfectshot1_ADDR = 0x202B62F4;
uintptr_t _S1perfectshot2_ADDR = 0x202B62F8;
uintptr_t _S1perfectshot3_ADDR = 0x202B62FC;
uintptr_t _S1perfectshot4_ADDR = 0x202B7B64;
uintptr_t _S2playerPTR = 0x2044D648;
uintptr_t _S2BaseEntityPointer = 0x20442CEC;
uintptr_t _S2fps1_ADDR = 0x2040C638;
uintptr_t _S2fps2_ADDR = 0x2040C640;
uintptr_t _S2fog_ADDR = 0x204093D0;
uintptr_t _S2forcestart_ADDR = 0x20408868;
uintptr_t _S2mapBrightness1 = 0x204B858C;
uintptr_t _S2mapBrightness2 = 0x204B859C;
uintptr_t _S2mapBrightness3 = 0x204B85AC;
uintptr_t _S2nvgFIX = 0x202169D8;
uintptr_t _S2crosshairR = 0x20407720;
uintptr_t _S2crosshairG = 0x20407728;
uintptr_t _S2crosshairB = 0x20407730;
uintptr_t _S2widescreen1 = 0x204A1DB0;
uintptr_t _S2widescreen2 = 0x204A1DC0;
uintptr_t _S2widescreen3 = 0x204A1DC4;
uintptr_t _S2widescreen4 = 0x204A7CEC;
uintptr_t _S3playerPTR = 0x206723F8;
uintptr_t _S3fps1_ADDR = 0x20612680;
uintptr_t _S3fps2_ADDR = 0x20612688;
uintptr_t _CAplayerPtr_ADDR = 0x20709D98;
uintptr_t _CABaseEntityPointer = 0x20709788;
uintptr_t _CAforcestart_ADDR = 0x20A7675C;
uintptr_t _CAfps1_ADDR = 0x206AA770;
uintptr_t _CAfps2_ADDR = 0x206AA778;

//PERFECT SHOT FUNCTIONS
void _PS_ON(bool& GameMenu, bool& loop, string& ACTIVE)
{
    GameMenu = false;
    loop = true;
    ACTIVE = "X";
}

void _PS_OFF(bool& LOOP, bool& bPS, bool& GameMenu, string& INACTIVE)
{
    LOOP = false;
    bPS = false;
    GameMenu = false;
    INACTIVE = " ";
}

//FPS FUNCTIONS
void _FPS_ON(string& ACTIVE, bool& MENU, uintptr_t& address, HANDLE& process)
{
    ACTIVE = "60";
    MENU = false;
    mem::PatchEx((BYTE*)address, (BYTE*)"\x3C", 1, process);
}

void _FPS_OFF(string& ACTIVE, bool& MENU, uintptr_t& address, HANDLE& process)
{
    ACTIVE = "30";
    MENU = false;
    mem::PatchEx((BYTE*)address, (BYTE*)"\x1E", 1, process);
}

#pragma region //SOCOM 1
//SOCOM 1 PERFECT SHOT IS SPECIAL
void SOCOM1_PERFECTSHOT_ON(bool& GameMenu, string& ACTIVE, HANDLE& process)
{
    GameMenu = false;
    ACTIVE = "X";
    mem::PatchEx((BYTE*)_S1perfectshot1_ADDR, (BYTE*)"\x03\x00\x00\x10", 4, process);
    mem::PatchEx((BYTE*)_S1perfectshot2_ADDR, (BYTE*)"\x66\x00\x00\x10", 4, process);
    mem::PS2NopEx((BYTE*)_S1perfectshot3_ADDR, 4, process);
    mem::PS2NopEx((BYTE*)_S1perfectshot4_ADDR, 4, process);
}

void SOCOM1_PERFECTSHOT_OFF(bool& GameMenu, string& INACTIVE, HANDLE& process)
{
    GameMenu = false;
    INACTIVE = " ";
    mem::PatchEx((BYTE*)_S1perfectshot1_ADDR, (BYTE*)"\x03\x00\x00\x10", 4, process);
    mem::PatchEx((BYTE*)_S1perfectshot2_ADDR, (BYTE*)"\x03\x00\x02\x24", 4, process);
    mem::PatchEx((BYTE*)_S1perfectshot3_ADDR, (BYTE*)"\x14\x00\x62\x14", 4, process);
    mem::PatchEx((BYTE*)_S1perfectshot4_ADDR, (BYTE*)"\x0C\x08\x22\xAE", 4, process);
}
#pragma endregion

#pragma region //SOCOM 2

//SOCOM 2 PERFECT SHOT
void _S2_POINTERS(uintptr_t& a, uintptr_t& b, uintptr_t& c, HANDLE process)
{
    a = PS2_FindDMAAddy(process, _S2playerPTR, { 0x5D8 });
    b = PS2_FindDMAAddy(process, _S2playerPTR, { 0xE2C });
    c = PS2_FindDMAAddy(process, _S2playerPTR, { 0x604 });
}

void _S2_POINTERS_2(uintptr_t& a, uintptr_t& b, uintptr_t& c, uintptr_t& d, uintptr_t& e, HANDLE& process)
{
    a = PS2_FindDMAAddy(process, _S2playerPTR, { 0x604 });
    b = PS2_FindDMAAddy(process, _S2playerPTR, { 0x608 });
    c = PS2_FindDMAAddy(process, _S2playerPTR, { 0x60C });
    d = PS2_FindDMAAddy(process, _S2playerPTR, { 0x61C });
    e = PS2_FindDMAAddy(process, _S2playerPTR, { 0x620 });
}

//FORCE START FUCNTIONS
void _FORCESTART_S2_ON(string& ACTIVE, bool& MENU, HANDLE& process)
{
    ACTIVE = "X";
    MENU = false;
    mem::PatchEx((BYTE*)_S2forcestart_ADDR, (BYTE*)"\x80\xE2\x27\x00", 4, process);
}

void _FORCESTART_S2_OFF(string& ACTIVE, bool& MENU, HANDLE& process)
{
    ACTIVE = " ";
    MENU = false;
    mem::PatchEx((BYTE*)_S2forcestart_ADDR, (BYTE*)"\x00\xDD\x27\x00", 4, process);
}

//S2 COLOR CROSSHAIR
void _COLORCROSSHAIR1_S2(string& COLOR, bool& oldCOLOR, bool& newCOLOR, bool& gameMENU, bool& CCOLOR, HANDLE& process)
{
    COLOR = "1";
    oldCOLOR = false;
    newCOLOR = true;
    gameMENU = false;
    CCOLOR = false;
    mem::PatchEx((BYTE*)_S2crosshairR, (BYTE*)"\x00\x00\xC0\x41", 4, process);
    mem::PatchEx((BYTE*)_S2crosshairG, (BYTE*)"\x00\x00\x48\x43", 4, process);
    mem::PatchEx((BYTE*)_S2crosshairB, (BYTE*)"\x00\x00\x48\x43", 4, process);
}

void _COLORCROSSHAIR2_S2(string& COLOR, bool& oldCOLOR, bool& newCOLOR, bool& gameMENU, bool& CCOLOR, HANDLE& process)
{
    COLOR = "2";
    oldCOLOR = false;
    newCOLOR = true;
    gameMENU = false;
    CCOLOR = false;
    mem::PatchEx((BYTE*)_S2crosshairR, (BYTE*)"\x00\x00\x7F\x43", 4, process);
    mem::PatchEx((BYTE*)_S2crosshairG, (BYTE*)"\x00\x00\x00\x00", 4, process);
    mem::PatchEx((BYTE*)_S2crosshairB, (BYTE*)"\x00\x00\x5b\x43", 4, process);
}

void _COLORCROSSHAIR3_S2(string& COLOR, bool& oldCOLOR, bool& newCOLOR, bool& gameMENU, bool& CCOLOR, HANDLE& process)
{
    COLOR = "3";
    oldCOLOR = false;
    newCOLOR = true;
    gameMENU = false;
    CCOLOR = false;
    mem::PatchEx((BYTE*)_S2crosshairR, (BYTE*)"\x00\x00\x00\x00", 4, process);
    mem::PatchEx((BYTE*)_S2crosshairG, (BYTE*)"\x00\x00\x00\x00", 4, process);
    mem::PatchEx((BYTE*)_S2crosshairB, (BYTE*)"\x00\x00\x7F\x43", 4, process);
}

void _COLORCROSSHAIR4_S2(string& COLOR, bool& oldCOLOR, bool& newCOLOR, bool& gameMENU, bool& CCOLOR, HANDLE& process)
{
    COLOR = "4";
    oldCOLOR = false;
    newCOLOR = true;
    gameMENU = false;
    CCOLOR = false;
    mem::PatchEx((BYTE*)_S2crosshairR, (BYTE*)"\x00\x00\x7F\x43", 4, process);
    mem::PatchEx((BYTE*)_S2crosshairG, (BYTE*)"\x00\x00\x7F\x43", 4, process);
    mem::PatchEx((BYTE*)_S2crosshairB, (BYTE*)"\x00\x00\x7F\x43", 4, process);
}

void _COLORCROSSHAIR5_S2(string& COLOR, bool& oldCOLOR, bool& newCOLOR, bool& gameMENU, bool& CCOLOR, HANDLE& process)
{
    COLOR = "0";
    oldCOLOR = false;
    newCOLOR = true;
    gameMENU = false;
    CCOLOR = false;
    mem::PatchEx((BYTE*)_S2crosshairR, (BYTE*)"\x00\x00\x48\x43", 4, process);
    mem::PatchEx((BYTE*)_S2crosshairG, (BYTE*)"\x00\x00\x48\x43", 4, process);
    mem::PatchEx((BYTE*)_S2crosshairB, (BYTE*)"\x00\x00\xC0\x41", 4, process);
}

//S2 WIDESCREEN
void _WIDESCREEN_S2_ON(string& ACTIVE, bool& MENU, HANDLE& process)
{
    ACTIVE = "X";
    MENU = false;
    mem::PatchEx((BYTE*)_S2widescreen1, (BYTE*)"\xF6\x28\x3C\x3F", 4, process);
    mem::PatchEx((BYTE*)_S2widescreen2, (BYTE*)"\x00\xA0\xE2\x44", 4, process);
    mem::PatchEx((BYTE*)_S2widescreen3, (BYTE*)"\x00\x20\xE4\x44", 4, process);
    mem::PatchEx((BYTE*)_S2widescreen4, (BYTE*)"\x33\x33\x93\x3F", 4, process);
}

void _WIDESCREEN_S2_OFF(string& ACTIVE, bool& MENU, HANDLE& process)
{
    ACTIVE = " ";
    MENU = false;
    mem::PatchEx((BYTE*)_S2widescreen1, (BYTE*)"\x00\x00\x80\x3F", 4, process);
    mem::PatchEx((BYTE*)_S2widescreen2, (BYTE*)"\x00\x00\xD8\x44", 4, process);
    mem::PatchEx((BYTE*)_S2widescreen3, (BYTE*)"\x00\x00\xE4\x44", 4, process);
    mem::PatchEx((BYTE*)_S2widescreen4, (BYTE*)"\x00\x00\x80\x3F", 4, process);
}

#pragma endregion

#pragma region //SOCOM 3
//SOCOM 3   Perfect Shot
void _S3_POINTERS(uintptr_t& a, uintptr_t& b, HANDLE process)
{
    a = PS2_FindDMAAddy(process, _S3playerPTR, { 0x8C8 });
    b = PS2_FindDMAAddy(process, _S3playerPTR, { 0x8B4 });
}

void _S3_POINTERS2(uintptr_t& a, uintptr_t& b, uintptr_t& c, HANDLE process)
{
    a = PS2_FindDMAAddy(process, _S3playerPTR, { 0x774 });
    b = PS2_FindDMAAddy(process, _S3playerPTR, { 0x8BC });
    c = PS2_FindDMAAddy(process, _S3playerPTR, { 0x8C0 });
}
#pragma endregion

#pragma region //SOCOM CA
void _CA_POINTERS(uintptr_t& a, uintptr_t& b, uintptr_t& c, HANDLE& process)
{
    a = PS2_FindDMAAddy(process, _CAplayerPtr_ADDR, { 0x6E4 }); //Start of CA Perfect Shot
    b = PS2_FindDMAAddy(process, _CAplayerPtr_ADDR, { 0x854 });
    c = PS2_FindDMAAddy(process, _CAplayerPtr_ADDR, { 0x868 });
}

//SOCOM CA  No Idle Scope Sway (IN-ZOOM) STEADY AIM
void _CA_POINTERS_2(uintptr_t& a, uintptr_t& b, uintptr_t& c, uintptr_t& d, uintptr_t& e, HANDLE process)
{
    a = PS2_FindDMAAddy(process, _CAplayerPtr_ADDR, { 0x714 });
    b = PS2_FindDMAAddy(process, _CAplayerPtr_ADDR, { 0x85C });
    c = PS2_FindDMAAddy(process, _CAplayerPtr_ADDR, { 0x860 });
    d = PS2_FindDMAAddy(process, _CAplayerPtr_ADDR, { 0x86C });
    e = PS2_FindDMAAddy(process, _CAplayerPtr_ADDR, { 0x870 });
}

void _FORCESTART_CA_ON(string& ACTIVE, bool& MENU, HANDLE& process)
{
    ACTIVE = "X";
    MENU = false;
    mem::PatchEx((BYTE*)_CAforcestart_ADDR, (BYTE*)"\x02\x00\x00\x00", 4, process);
}

void _FORCESTART_CA_OFF(string& ACTIVE, bool& MENU, HANDLE& process)
{
    ACTIVE = " ";
    MENU = false;
    mem::PatchEx((BYTE*)_CAforcestart_ADDR, (BYTE*)"\x84\x49\xB5\x00", 4, process);
}
#pragma endregion

#pragma region //CLEAR FUNCTIONS

//WORKS FOR ALL GAMES
void _clear_FPS(uintptr_t& address, HANDLE& process, bool& gameFPS, string& FPS)
{
    _clearConsole();
    std::wcout << "RESTORING DATA . . ." << std::endl;
    mem::PatchEx((BYTE*)address, (BYTE*)"\x1E", 1, process); //patch
    gameFPS = false;
    FPS = "30";
    Sleep(2050);
}

// FORCE START CLEARING
void _clear_FORCESTART_S2(string& ACTIVE, bool& gameFORCESTART, HANDLE& process)
{
    _clearConsole();
    ACTIVE = " ";
    gameFORCESTART = false;
    mem::PatchEx((BYTE*)_S2forcestart_ADDR, (BYTE*)"\x00\xDD\x27\x00", 4, process); //Restore Data
    std::wcout << "RESTORING DATA . . ." << std::endl;
    Sleep(2050);
}

void _clear_FORCESTART_CA(string& ACTIVE, bool& gameFORCESTART, HANDLE& process)
{
    _clearConsole();
    ACTIVE = " ";
    gameFORCESTART = false;
    mem::PatchEx((BYTE*)_CAforcestart_ADDR, (BYTE*)"\x84\x49\xB5\x00", 4, process); //Restore Data
    std::wcout << "RESTORING DATA . . ." << std::endl;
    Sleep(2050);
}

//SOCOM 2
void _clear_WIDESCREEN(string& ACTIVE, bool& gameWIDESCREEN, HANDLE& process)
{
    ACTIVE = " ";
    gameWIDESCREEN = false;
    mem::PatchEx((BYTE*)_S2widescreen1, (BYTE*)"\x00\x00\x80\x3F", 4, process);
    mem::PatchEx((BYTE*)_S2widescreen2, (BYTE*)"\x00\x00\xD8\x44", 4, process);
    mem::PatchEx((BYTE*)_S2widescreen3, (BYTE*)"\x00\x00\xE4\x44", 4, process);
    mem::PatchEx((BYTE*)_S2widescreen4, (BYTE*)"\x00\x00\x80\x3F", 4, process);
}
#pragma endregion

//ONLY WORKING FOR COMBINED ASSAULT
//Im not sure if I like this method very much.
//I also need to create a quit function.... at this rate it would require . . .
//4 different functions ... and that just wont do. We can do better. 
//1 function for clear , 1 function for quit

void _return_MAIN(bool& gameFPS, bool& gamePERFSHOT, bool& gameFORCE,
    bool& LOOP, HANDLE& process, string& SgameFPS,
    string& SgameFORCE, string& SgamePERFSHOT, bool& gameMENU, bool& game, bool& mMENU)
{
    if (gameFPS)
    {
        _clear_FPS(_CAfps1_ADDR, process, gameFPS, SgameFPS);
    }
    if (gamePERFSHOT)
    {
        gamePERFSHOT = false;
        if (LOOP)
        {
            LOOP = false;
            SgamePERFSHOT = " ";
        }
    }
    if (gameFORCE)
    {
        _clear_FORCESTART_CA(SgameFORCE, gameFORCE, process);
    }
    _ReturnToMainMenu(gameMENU, game, mMENU);
}

//WORKING FOR SOCOM 2
void _QUITfromSOCOM_2(bool& gameFPS, string& FPS, bool& gamePerfectShot, bool& LOOP, string& PSHOT,
    bool& gameFOG, string& FOG, bool& gameBRIGHTNESS, string& BRIGHTNESS, bool& gameFORCE,
    string& FORCE, bool& gameNVG, string& NVG, bool& bcolor0, bool& bcolor1, bool& bcolor2,
    bool& bcolor3, bool& bcolor4, bool& mainCOLOR, string& COLOR, bool& gameWIDESCREEN,
    string& WIDESCREEN, HANDLE& process)
{
    if (gameFPS)
    {
        _clear_FPS(_S2fps1_ADDR, process, gameFPS, FPS);
    }
    if (gamePerfectShot)
    {
        gamePerfectShot = false;
        if (LOOP)
        {
            LOOP = false;
            PSHOT = " ";
        }
    }
    if (gameFOG)
    {
        FOG = " ";
        gameFOG = false;
        mem::PatchEx((BYTE*)_S2fog_ADDR, (BYTE*)"\x01\x00\x00\x00", 4, process);
    }
    if (gameBRIGHTNESS)
    {
        BRIGHTNESS = " ";
        gameBRIGHTNESS = false;
        mem::PS2NopEx((BYTE*)_S2mapBrightness1, 4, process);
        mem::PS2NopEx((BYTE*)_S2mapBrightness2, 4, process);
        mem::PS2NopEx((BYTE*)_S2mapBrightness3, 4, process);
    }
    if (gameFORCE)
    {
        _clear_FORCESTART_S2(FORCE, gameFORCE, process);
    }
    if (gameNVG)
    {
        NVG = " ";
        gameNVG = false;
        mem::PatchEx((BYTE*)_S2nvgFIX, (BYTE*)"\xD0\x5D\x06\x0C", 4, process);
    }
    if (COLOR != "0")
    {
        COLOR = "0";
        bcolor1 = false;
        bcolor2 = false;
        bcolor3 = false;
        bcolor4 = false;
        bcolor0 = true;
        mainCOLOR = false;
        mem::PatchEx((BYTE*)_S2crosshairR, (BYTE*)"\x00\x00\x48\x43", 4, process);
        mem::PatchEx((BYTE*)_S2crosshairG, (BYTE*)"\x00\x00\x48\x43", 4, process);
        mem::PatchEx((BYTE*)_S2crosshairB, (BYTE*)"\x00\x00\xC0\x41", 4, process);
    }
    if (gameWIDESCREEN)
    {
        _clear_WIDESCREEN(WIDESCREEN, gameWIDESCREEN, process);

    }
    _clearConsole();
    std::cout << "TERMINATING SESSION, THANK YOU FOR USING" << std::endl;
}


///I SERIOUSLY NEED TO GO THROUGH ALL OF THESE AS I DO NOT KNOW WHAT IS AND ISNT BEING USED
// EVERYTHING BELOW IS THE LATEST AS OF VIP BUILD 0.0.5
// RETURN TO MAIN AND EXIT RESTORE DEFAULTS


void SOCOM::_return(HANDLE& PROCESS, bool& MENU, bool& HACK1, string& sHACK1, bool& HACK2, string& sHACK2, bool LOOP,
    bool& HACK3, string& sHACK3, bool& HACK4, bool& HACK5, string& sHACK5,
    bool& HACK6, string& sHACK6, bool& HACK7, string& sHACK7)
{
    if (HACK1)
    {
        _FPS_OFF(sHACK1, MENU, _S2fps1_ADDR, PROCESS);
    }
    if (HACK2)
    {
        _PS_OFF(LOOP, HACK2, MENU, sHACK2);
    }
    if (HACK3)
    {
        sHACK3 = " ";
        MENU = false;
        mem::PatchEx((BYTE*)_S2fog_ADDR, (BYTE*)"\x01\x00\x00\x00", 4, PROCESS);
    }
    if (HACK4)
    {
        HACK4 = false;
    }
    if (HACK5)
    {
        sHACK5 = " ";
        MENU = false;
        mem::PatchEx((BYTE*)_S2nvgFIX, (BYTE*)"\xD0\x5D\x06\x0C", 4, PROCESS);
    }
    if (sHACK6 != "0")
    {
        int a;
        ReadProcessMemory(PROCESS, (BYTE*)_S2crosshairR, &a, sizeof(a), nullptr);
        if (a != 1128792064)
        {
            mem::PatchEx((BYTE*)_S2crosshairR, (BYTE*)"\x00\x00\x48\x43", 4, PROCESS);
            mem::PatchEx((BYTE*)_S2crosshairG, (BYTE*)"\x00\x00\x48\x43", 4, PROCESS);
            mem::PatchEx((BYTE*)_S2crosshairB, (BYTE*)"\x00\x00\xC0\x41", 4, PROCESS);
            sHACK6 = "0";
            HACK6 = false;
        }
    }
    if (HACK7)
    {
        _WIDESCREEN_S2_OFF(sHACK7, MENU, PROCESS);
        HACK7 = false;
    }
}