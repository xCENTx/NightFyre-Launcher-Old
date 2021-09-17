#include "stdafx.h"

//METHODS
int main2();
void _ANCHOR();
int ePSXe();
int PCSX2();
int FarCry3();
int AssaultCube();
int TheBindingofIsaac();
int DeathlyStillness();

//MAIN
static bool MAINMENU = false;
static bool menuSHOWN = false;
static bool bSOCOM_SERIES_MENU = false;

//ePSXe
static bool bGAME_FF7;

//PCSX2
static bool bGAME_SOCOM1 = false;
static bool bGAME_SOCOM2 = false;
static bool bGAME_SOCOM3 = false;
static bool bGAME_SOCOMCA = false;

//Assault Cube
static bool bGAME_ASSAULT_CUBE = false;

//Binding of Isaac
static bool bGAME_ISAAC = false;

//FarCry
static bool bGAME_FARCRY3 = false;

//Borderlands
static bool bGAME_BORDERLANDS = false;
static bool bGAME_BORDERLANDS2 = false;
static bool bGAME_BORDERLANDS3 = false;

//Metal Gear Solid
static bool bGAME_MGSTPP = false;

//Deathly Stillness
static bool bGAME_Deathly_Stillness = false;

/// MAIN MENU
int main()
{
    //We need to display a text with selections
    //Once the user selects an option a splash screen will be shown , much like a loading screen , indicating the users selection
    //During this load screen , we can establish the Base Address and resolve our pointer chains
    //Once this process has sucessfully completed we can then clear the slashscreen and display the games menu with its options
    _MAINMENU();
    MAINMENU = true;
    while (_MAINMENU)
    {
        //SOCOM SERIES (Soon will become Numpad 1 and then display a seperate menu)
        if (GetAsyncKeyState(VK_NUMPAD1) & 1)
        {
            _clearConsole();
            main2();

            //Hopefully* anything after this is only executed after main2 has returned 0. 
            //Therefore we will want to repopulate main, which we can do simply by running through it again
            _MAINMENU();
        }

        //FAR CRY 3
        if (GetAsyncKeyState(VK_NUMPAD2) & 1)
        {
            bGAME_FARCRY3 = true;
            _ANCHOR();
        }

        //ASSAULT CUBE
        if (GetAsyncKeyState(VK_NUMPAD3) & 1)
        {
            bGAME_ASSAULT_CUBE = true;
            _ANCHOR();
        }

        //Binding of Isaac
        if (GetAsyncKeyState(VK_NUMPAD4) & 1)
        {
            bGAME_ISAAC = true;
            _ANCHOR();
        }

        //Final Fantasy 7
        if (GetAsyncKeyState(VK_NUMPAD5) & 1)
        {
            bGAME_FF7 = true;
            _ANCHOR();
        }

        //Deathly Stilness
        if (GetAsyncKeyState(VK_NUMPAD9) & 1)
        {
            bGAME_Deathly_Stillness = true;
            _ANCHOR();
        }

        //QUIT
        if (GetAsyncKeyState(VK_END) & 1)
        {
            break;
        }

        if (!MAINMENU)
        {
            _clearConsole();
            std::cout << "If for some reason this window does not close on its own , you may go ahead and close it." << std::endl;
            return 0;
        }
    }


}

//SOCOM SERIES ALT MENU
int main2()
{
    MENU_SOCOM_SELECT();
    bSOCOM_SERIES_MENU = true;
    while (MENU_SOCOM_SELECT)
    {
        if (GetAsyncKeyState(VK_NUMPAD1) & 1)
        {
            bGAME_SOCOM1 = true;
            _ANCHOR();
        }
        if (GetAsyncKeyState(VK_NUMPAD2) & 1)
        {
            bGAME_SOCOM2 = true;
            _ANCHOR();
        }
        if (GetAsyncKeyState(VK_NUMPAD3) & 1)
        {
            bGAME_SOCOM3 = true;
            _ANCHOR();
        }
        if (GetAsyncKeyState(VK_NUMPAD4) & 1)
        {
            bGAME_SOCOMCA = true;
            _ANCHOR();
        }

        //Return to Main or Exit
        if (GetAsyncKeyState(VK_SUBTRACT) & 1)
        {
            _clearConsole();
            bSOCOM_SERIES_MENU = false;
            return 0;
        }
        if (GetAsyncKeyState(VK_END) & 1)
        {
            _clearConsole();
            bSOCOM_SERIES_MENU = false;
            MAINMENU = false;
            return 0;
        }

        if (!bSOCOM_SERIES_MENU)
        {
            _clearConsole();
            std::cout << "If for some reason this window does not close on its own , you may go ahead and close it." << std::endl;
            return 0;
        }
    }
}

//The goal here is to keep everything tied together
void _ANCHOR()
{
    if (bGAME_SOCOM1)
    {
        select_S1();
        PCSX2();
    }
    if (bGAME_SOCOM2)
    {
        select_S2();
        PCSX2();
    }
    if (bGAME_SOCOM3)
    {
        select_S3();
        PCSX2();
    }
    if (bGAME_SOCOMCA)
    {
        select_CA();
        PCSX2();
    }
    if (bGAME_FARCRY3)
    {
        select_FC3();
        FarCry3();
    }
    if (bGAME_ASSAULT_CUBE)
    {
        select_ASSAULT_CUBE();
        AssaultCube();
    }
    if (bGAME_ISAAC)
    {
        select_ISAAC();
        TheBindingofIsaac();
    }
    if (bGAME_FF7)
    {
        select_FF7();
        ePSXe();
    }
    if (bGAME_Deathly_Stillness)
    {
        select_DEATHLY_STILLNESS();
        DeathlyStillness();
    }
    _MAINMENU();
}

/// GAME MENUS
int ePSXe()
{
    SetConsoleTitle(L"ePSXe v2.0.5 - Final Fantasy 7 | CONSOLE");
    #pragma region //Establish Variables
    HANDLE hProcess = 0;
    uintptr_t moduleBase = 0;
    uintptr_t currentHP1 = 0, maxHP1 = 0, currentMP1 = 0;
    uintptr_t currentHP2 = 0, maxHP2 = 0, currentMP2 = 0;
    uintptr_t currentHP3 = 0, maxHP3 = 0, currentMP3 = 0;
    bool bHP = false, bMP = false, bGIL = false;
    string sHP = " ", sMP = " ", sGIL = " ";
    bool HACK_LOOP = false;

    //Empty Variables
    int cHP1, mHP1, cMP1, mMP1;
    int cHP2, mHP2, cMP2, mMP2;
    int cHP3, mHP3, cMP3, mMP3;
    #pragma endregion

    std::cout << "Searching for ePSXe . . .\n";
    Sleep(1050);

    //Get Proc Id of target process
    DWORD procId = GetProcId(L"epsxe.exe");
    if (procId)
    {
        std::cout << "Process Found" << std::endl;
        Sleep(550);

        std::cout << "Connecting to Process . . ." << std::endl;
        Sleep(750);

        //Let user know we have established connection with the process
        std::cout << "Connection Established" << std::endl;
        Sleep(1050);

        // Get Handle to process
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
        std::cout << "Gathering Process Information . . ." << std::endl;
        Sleep(750);

        //Get module base address
        moduleBase = GetModuleBaseAddress(procId, L"epsxe.exe");
        std::cout << "Loading Menu . . ." << std::endl;
        Sleep(1550);

        //Character 1 Pointers
        currentHP1 = moduleBase + 0xB7A42C;
        maxHP1 = moduleBase + 0xB7A430;
        currentMP1 = moduleBase + 0xB7A428;

        //Character 2 Pointers
        currentHP2 = moduleBase + 0xB7A494;
        maxHP2 = moduleBase + 0xB7A498;
        currentMP2 = moduleBase + 0x0B7A490;
        
        _clearConsole();
    }
    else
    {
        _clearConsole();
        std::cout << "Process Not Found - Returning to main menu" << std::endl;
        bGAME_FF7 = false;
        Sleep(2050);
        return 0;
    }

    DWORD dwExit = 0;
    while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
    {

        if (bGAME_FF7)
        {
            if (!menuSHOWN)
            {
                menuSHOWN = true;
                _clearConsole();
                MENU_FF7(sHP, sMP, sGIL);
            }

            if (GetAsyncKeyState(VK_NUMPAD1) & 1)
            {
                bHP = !bHP;

                if (bHP)
                {
                    //We need to establish max hp first
                    ReadProcessMemory(hProcess, (BYTE*)maxHP1, &mHP1, sizeof(mHP1), nullptr);
                    ReadProcessMemory(hProcess, (BYTE*)maxHP2, &mHP2, sizeof(mHP2), nullptr);
                }
            }

            if (bHP)
            {
                if (!HACK_LOOP)
                {
                    sHP = "X";
                    HACK_LOOP = true;
                    menuSHOWN = false;

                }
                if (currentHP1 < mHP1)
                {
                    WriteProcessMemory(hProcess, (BYTE*)currentHP1, &maxHP1, sizeof(maxHP1), nullptr);
                }
                if (currentHP2 < mHP2)
                {
                    WriteProcessMemory(hProcess, (BYTE*)currentHP2, &maxHP2, sizeof(maxHP2), nullptr);
                }
            }
            else if (HACK_LOOP)
            {
                sHP = " ";
                HACK_LOOP = false;
                menuSHOWN = false;
            }
        }

        Sleep(10);
    }

    _clearConsole();
    std::cout << "Process Not Found - Returning to main menu" << std::endl;
    bGAME_FF7 = false;
    Sleep(2050);
    return 0;
}

int PCSX2()
{
    //Set Console Window Title
    SetConsoleTitle(L"PCSX2 - NightFyre Edition | CONSOLE");

    #pragma region //Establish Variables
    HANDLE hProcess = 0;
    uintptr_t moduleBase = 0;
    //S2 Perfect Shot
    uintptr_t oBounce_S2 = 0, oRecoil_S2 = 0, oSpread_S2 = 0;
    uintptr_t ScopeSway1_S2 = 0, ScopeSway2_S2 = 0, ScopeSway3_S2 = 0, 
                             ScopeRecoil1_S2 = 0, ScopeRecoil2_S2 = 0;

    //S3 Perfect Shot
    uintptr_t oRecoil_S3 = 0, oSpread_S3 = 0;
    uintptr_t oScope1_S3 = 0, oScope2_S3 = 0, oScope3_S3 = 0;

    //CA Perfect Shot
    uintptr_t ospread1 = 0, ospread2 = 0, orecoil = 0;                                                  //Perfect Shot Offset (inside Player Pointer)
    uintptr_t oScope1 = 0, oScope2 = 0, oScope3 = 0, oScope4 = 0, oScope5 = 0;                          //Steady Aim Offsets (inside Player Pointer)
    
    //GAME BOOLS
    bool bPerfectShot_S1 = false, bFPS_S1 = false;                                                       //SOCOM 1
    bool bPerfectShot_S2 = false, bFPS_S2 = false, bForceStart_S2 = false;                               //SOCOM 2
    bool bFOG_S2 = false, bBRIGHTNESS_S2 = false, bNVG_S2 = false, bCCOLOR_S2 = false;                   //SOCOM 2 (cont...)
    bool color0 = true, color1 = false, color2 = false, color3 = false, color4 = false;                  //SOCOM 2 (cont...)
    bool bWideScreen = false;                                                                            //SOCOM 2 (cont...)
    bool bPerfectShot_S3 = false, bNoSway_S3 = false, bFPS_S3 = false;                                                       //SOCOM 3
    bool bForceStart_CA = false, bFPS_CA = false, bPerfectShot_CA = false;                               //SOCOM CA
    
    //bool for hacks in threads
    bool HACK_LOOP = false, HACK_LOOP2 = false;

    //Strings for MENU indicators
    string sPSHOT = " ", sFPS = "30", sFORCE = " ", sFOG = " ", sBRIGHTNESS = " ", sNVG = " ", sCOLOR = "0", sWIDESCREEN = " ";
    string sNOSWAY = " ";
    
    //Empty Value for Read and Write Process Memory
    int value;
    int _flagSway;
    int _flagSway2;
    #pragma endregion
    
    std::cout << "Searching for PCSX2 NightFyre Edition . . ." << std::endl;
    Sleep(1050);

    // Get proc Id of target process
    DWORD procId = GetProcId(L"PlayStation2.exe");

    if (procId)
    {
        std::cout << "Process found , Thank You for using PCSX2 - NightFyre Edition" << std::endl;
        Sleep(550);

        std::cout << "Connecting to Process . . ." << std::endl;
        Sleep(750);

        //Let user know we have established connection with the process
        std::cout << "Connection Established" << std::endl;
        Sleep(1050);

        // Get Handle to process
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
        std::cout << "Gathering Process Information . . ." << std::endl;
        Sleep(750);

        //Get module base address
        moduleBase = GetModuleBaseAddress(procId, L"PlayStation2.exe");
        std::cout << "Loading Menu . . ." << std::endl;
        Sleep(1550);

        // We have a handle to our process , we got the module base address ... 
        // We are now ready to proceeed to the main hack thread
        // Start by clearing console and sending some input to user
        _clearConsole();
    }
    else
    {
        _clearConsole();
        std::cout << "Process Not Found - Returning to main menu" << std::endl;
        bGAME_SOCOM1 = false, bGAME_SOCOM2 = false, bGAME_SOCOM3 = false, bGAME_SOCOMCA = false, bSOCOM_SERIES_MENU = false;
        Sleep(2050);
        return 0;
    }

    DWORD dwExit = 0;
    while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
    {

        if (bGAME_SOCOM1)
        {
            //Used to initialize and reset menu
            if (!menuSHOWN)
            {
                SetConsoleTitle(L"PCSX2 - NightFyre Edition | SOCOM 1 - CONSOLE");

                //So we dont run down this path again
                menuSHOWN = true;
                _clearConsole();    //Clear our console
                MENU_SOCOM1(sFPS, sPSHOT);      //Now we show SOCOM 1 MENU
            }

            //FPS
            if (GetAsyncKeyState(VK_NUMPAD1) & 1)
            {
                bFPS_S1 = !bFPS_S1;
                if (bFPS_S1)
                {
                    _FPS_ON(sFPS, menuSHOWN, _S1framerate1_ADDR, hProcess);
                }
                else
                {
                    _FPS_OFF(sFPS, menuSHOWN, _S1framerate1_ADDR, hProcess);
                }
            }

            // PERFECT SHOT (VIP OPTION)
            if (GetAsyncKeyState(VK_NUMPAD2) & 1)
            {
                bPerfectShot_S1 = !bPerfectShot_S1;

                if (bPerfectShot_S1)
                {
                    SOCOM1_PERFECTSHOT_ON(menuSHOWN, sPSHOT, hProcess);
                }
                else
                {
                    SOCOM1_PERFECTSHOT_OFF(menuSHOWN, sPSHOT, hProcess);
                }
            }

            //Return to Main or Exit
            if (GetAsyncKeyState(VK_SUBTRACT) & 1)
            {
                _clearConsole();
                bGAME_SOCOM1 = false;
                bSOCOM_SERIES_MENU = false;
                menuSHOWN = false;
                return 0;
            }
            if (GetAsyncKeyState(VK_END) & 1)
            {
                _clearConsole();
                bGAME_SOCOM1 = false;
                bSOCOM_SERIES_MENU = false;
                menuSHOWN = false;
                MAINMENU = false;
                return 0;
            }
        }

        if (bGAME_SOCOM2)
        {
            if (!menuSHOWN)
            {    
                //Set Console Window Title
                SetConsoleTitle(L"PCSX2 - NightFyre Edition | SOCOM 2 - CONSOLE");

                menuSHOWN = true;
                _clearConsole();
                MENU_SOCOM2(sFPS, sPSHOT, sFORCE, sFOG, sNVG, sCOLOR, sWIDESCREEN, sBRIGHTNESS);
            }

            //FPS MOD
            if (GetAsyncKeyState(VK_NUMPAD1) & 1)
            {
                bFPS_S2 = !bFPS_S2;

                if (bFPS_S2)
                {
                    _FPS_ON(sFPS, menuSHOWN, _S2fps1_ADDR, hProcess);
                }
                else
                {
                    _FPS_OFF(sFPS, menuSHOWN, _S2fps1_ADDR, hProcess);
                }
            }

            //PERFECT SHOT
            if (GetAsyncKeyState(VK_NUMPAD2) & 1)
            {
                bPerfectShot_S2 = !bPerfectShot_S2;

                if (bPerfectShot_S2)
                {
                    _S2_POINTERS(oBounce_S2, oSpread_S2, oRecoil_S2, hProcess);
                    _S2_POINTERS_2(ScopeRecoil1_S2, ScopeRecoil2_S2, ScopeRecoil1_S2, ScopeRecoil2_S2, ScopeSway3_S2, hProcess);
                }
            }

            //NO FOG
            if (GetAsyncKeyState(VK_NUMPAD3) & 1)
            {
                bFOG_S2 = !bFOG_S2;

                if (bFOG_S2)
                {
                    sFOG = "X";
                    menuSHOWN = false;
                    mem::PS2NopEx((BYTE*)_S2fog_ADDR, 4, hProcess);
                }
                else
                {
                    sFOG = " ";
                    menuSHOWN = false;
                    mem::PatchEx((BYTE*)_S2fog_ADDR, (BYTE*)"\x01\x00\x00\x00", 4, hProcess);
                }
            }

            //BRIGHTNESS
            if (GetAsyncKeyState(VK_NUMPAD4) & 1)
            {
                bBRIGHTNESS_S2 = !bBRIGHTNESS_S2;
                if (bBRIGHTNESS_S2)
                {
                    sBRIGHTNESS = "X";
                    menuSHOWN = false;
                    mem::PatchEx((BYTE*)_S2mapBrightness1, (BYTE*)"\x00\x00\x50\x40", 4, hProcess);
                    mem::PatchEx((BYTE*)_S2mapBrightness2, (BYTE*)"\x00\x00\x50\x40", 4, hProcess);
                    mem::PatchEx((BYTE*)_S2mapBrightness3, (BYTE*)"\x00\x00\x50\x40", 4, hProcess);
                }
                else
                {
                    sBRIGHTNESS = " ";
                    menuSHOWN = false;
                    mem::PS2NopEx((BYTE*)_S2mapBrightness1, 4, hProcess);
                    mem::PS2NopEx((BYTE*)_S2mapBrightness2, 4, hProcess);
                    mem::PS2NopEx((BYTE*)_S2mapBrightness3, 4, hProcess);
                }
            }

            //NVG PATCH (bismofunyuns)
            if (GetAsyncKeyState(VK_NUMPAD5) & 1)
            {
                bNVG_S2 = !bNVG_S2;
                if (bNVG_S2)
                {
                    sNVG = "X";
                    menuSHOWN = false;
                    mem::PS2NopEx((BYTE*)_S2nvgFIX, 4, hProcess);
                }
                else
                {
                    sNVG = " ";
                    menuSHOWN = false;
                    mem::PatchEx((BYTE*)_S2nvgFIX, (BYTE*)"\xD0\x5D\x06\x0C", 4, hProcess);
                }
            }

            //COLORED CROSSHAIR (Harry62)
            if (GetAsyncKeyState(VK_NUMPAD6) & 1)
            {
                bCCOLOR_S2 = !bCCOLOR_S2;

                if (bCCOLOR_S2)
                {
                    //TEAL
                    if (sCOLOR == "0" && color0)
                    {
                        _COLORCROSSHAIR1_S2(sCOLOR, color0, color1, menuSHOWN, bCCOLOR_S2, hProcess);
                    }
                }

                if (bCCOLOR_S2 && color1)
                {
                    //MAGENTA
                    if (sCOLOR == "1")
                    {
                        _COLORCROSSHAIR2_S2(sCOLOR, color1, color2, menuSHOWN, bCCOLOR_S2, hProcess);
                    }
                }

                if (bCCOLOR_S2 && color2)
                {
                    //BLUE
                    if (sCOLOR == "2")
                    {
                        _COLORCROSSHAIR3_S2(sCOLOR, color2, color3, menuSHOWN, bCCOLOR_S2, hProcess);
                    }
                }

                if (bCCOLOR_S2 && color3)
                {
                    //WHITE
                    if (sCOLOR == "3")
                    {
                        _COLORCROSSHAIR4_S2(sCOLOR, color3, color4, menuSHOWN, bCCOLOR_S2, hProcess);
                    }
                }

                if (bCCOLOR_S2 && color4)
                {
                    //DEFAULT
                    if (sCOLOR == "4")
                    {
                        _COLORCROSSHAIR5_S2(sCOLOR, color4, color0, menuSHOWN, bCCOLOR_S2, hProcess);
                    }
                }
            }

            //WIDESCREEN PATCH (Harry62)
            if (GetAsyncKeyState(VK_NUMPAD7) & 1)
            {
                bWideScreen = !bWideScreen;
                if (bWideScreen)
                {
                    _WIDESCREEN_S2_ON(sWIDESCREEN, menuSHOWN, hProcess);
                }
                else
                {
                    _WIDESCREEN_S2_OFF(sWIDESCREEN, menuSHOWN, hProcess);
                }
            }

            //FORCE START
            if (GetAsyncKeyState(VK_NUMPAD9) & 1)
            {
                bForceStart_S2 = !bForceStart_S2;
                if (bForceStart_S2)
                {
                    _FORCESTART_S2_ON(sFORCE, menuSHOWN, hProcess);
                }
                else
                {
                    _FORCESTART_S2_OFF(sFORCE, menuSHOWN, hProcess);
                }
            }

            //Return to Main and Exit
            if (GetAsyncKeyState(VK_SUBTRACT) & 1)
            {
                _clearConsole();
                bGAME_SOCOM2 = false;
                bSOCOM_SERIES_MENU = false;
                menuSHOWN = false;
                return 0;
            }

            if (GetAsyncKeyState(VK_END) & 1)
            {
                _clearConsole();
                bGAME_SOCOM2 = false;
                bSOCOM_SERIES_MENU = false;
                menuSHOWN = false;
                MAINMENU = false;
                return 0;
            }

            if (bPerfectShot_S2)
            {
                int value2;
                int flag = ReadProcessMemory(hProcess, (BYTE*)_S2playerPTR, &value, sizeof(value), nullptr);
                int flag2 = ReadProcessMemory(hProcess, (BYTE*)_S2playerPTR, &value2, sizeof(value2), nullptr);
                if (value != 0)
                {
                    int FLAG = ReadProcessMemory(hProcess, (LPVOID)oRecoil_S2, &value, sizeof(value), nullptr);
                    if (!HACK_LOOP)
                    {
                        _PS_ON(menuSHOWN, HACK_LOOP, sPSHOT);
                    }
                    if (value != 0)
                    {
                        mem::PS2NopEx((BYTE*)oRecoil_S2, 4, hProcess); //patch
                        mem::PS2NopEx((BYTE*)oSpread_S2, 4, hProcess);

                    }
                    if (value2 != 0)
                    {
                        mem::PS2NopEx((BYTE*)ScopeRecoil1_S2, 4, hProcess); //RECOIL
                        mem::PS2NopEx((BYTE*)ScopeRecoil2_S2, 4, hProcess);
                        mem::PS2NopEx((BYTE*)ScopeSway1_S2, 4, hProcess); //SWAY
                        mem::PS2NopEx((BYTE*)ScopeSway2_S2, 4, hProcess);
                        mem::PS2NopEx((BYTE*)ScopeSway3_S2, 4, hProcess);
                    }
                }
                else bPerfectShot_S2 = false;
            }
            else if (HACK_LOOP)
            {
                _PS_OFF(HACK_LOOP, bPerfectShot_S2, menuSHOWN, sPSHOT);
            }
        }

        if (bGAME_SOCOM3)
        {
            if (!menuSHOWN)
            {
                SetConsoleTitle(L"PCSX2 - NightFyre Edition | SOCOM 3 - CONSOLE");
                menuSHOWN = true;
                _clearConsole();
                MENU_SOCOM3(sFPS, sPSHOT, sNOSWAY);
            }

            //FPS
            if (GetAsyncKeyState(VK_NUMPAD1) & 1)
            {
                bFPS_S3 = !bFPS_S3;

                if (bFPS_S3)
                {
                    _FPS_ON(sFPS, menuSHOWN, _S3fps1_ADDR, hProcess);
                }
                else
                {
                    _FPS_OFF(sFPS, menuSHOWN, _S3fps1_ADDR, hProcess);
                }
            }

            // PERFECT SHOT (VIP OPTION)
            if (GetAsyncKeyState(VK_NUMPAD2) & 1)
            {
                bPerfectShot_S3 = !bPerfectShot_S3;
                if (bPerfectShot_S3)
                {
                    _S3_POINTERS(oRecoil_S3, oSpread_S3, hProcess);
                }
            }

            //No Scope Idle Sway
            if (GetAsyncKeyState(VK_NUMPAD3) & 1)
            {
                bNoSway_S3 = !bNoSway_S3;
                if (bNoSway_S3)
                {
                    _S3_POINTERS2(oScope1_S3, oScope2_S3, oScope3_S3, hProcess);
                }
            }

            //Return to Main or Exit
            if (GetAsyncKeyState(VK_SUBTRACT) & 1)
            {
                _clearConsole();
                bGAME_SOCOM3 = false;
                bSOCOM_SERIES_MENU = false;
                menuSHOWN = false;
                return 0;
            }
            if (GetAsyncKeyState(VK_END) & 1)
            {
                _clearConsole();
                bGAME_SOCOM3 = false;
                bSOCOM_SERIES_MENU = false;
                menuSHOWN = false;
                MAINMENU = false;
                return 0;
            }

            if (bPerfectShot_S3)
            {
                int flag = ReadProcessMemory(hProcess, (BYTE*)_S3playerPTR, &value, sizeof(value), nullptr);
                if (value != 0)
                {
                    int FLAGA = ReadProcessMemory(hProcess, (LPVOID)oRecoil_S3, &value, sizeof(value), nullptr);
                    if (!HACK_LOOP)
                    {
                        _PS_ON(menuSHOWN, HACK_LOOP, sPSHOT);
                    }
                    if (value != 0)
                    {
                        mem::PS2NopEx((BYTE*)oRecoil_S3, 4, hProcess);
                        mem::PS2NopEx((BYTE*)oSpread_S3, 4, hProcess);
                    }
                }
                else bPerfectShot_S3 = false;
            }
            else if (HACK_LOOP)
            {
                _PS_OFF(HACK_LOOP, bPerfectShot_S3, menuSHOWN, sPSHOT);
            }

            if (bNoSway_S3)
            {
                if (!HACK_LOOP2)
                {
                    sNOSWAY = "X";
                    menuSHOWN = false;
                    HACK_LOOP2 = true;
                }

                int flag = ReadProcessMemory(hProcess, (BYTE*)_S3playerPTR, &value, sizeof(value), nullptr);
                if (value != 0)
                {
                    ReadProcessMemory(hProcess, (BYTE*)oScope2_S3, &_flagSway, sizeof(_flagSway), nullptr);
                    ReadProcessMemory(hProcess, (BYTE*)oScope3_S3, &_flagSway2, sizeof(_flagSway2), nullptr);
                    if (_flagSway && _flagSway2 != 0)
                    {
                        mem::PS2NopEx((BYTE*)oScope1_S3, 4, hProcess);
                        mem::PS2NopEx((BYTE*)oScope2_S3, 4, hProcess);
                        mem::PS2NopEx((BYTE*)oScope3_S3, 4, hProcess);
                    }
                }
                else bNoSway_S3 = false;
            }
            else if (HACK_LOOP2)
            {
                sNOSWAY = " ";
                menuSHOWN = false;
                HACK_LOOP2 = false;
            }
        }

        if (bGAME_SOCOMCA)
        {
            if (!menuSHOWN)
            {
                SetConsoleTitle(L"PCSX2 - NightFyre Edition | SOCOM CA - CONSOLE");
                menuSHOWN = true;
                _clearConsole();
                MENU_SOCOMCA(sFPS, sPSHOT, sFORCE);
            }

            //FPS MOD
            if (GetAsyncKeyState(VK_NUMPAD1) & 1)
            {
                bFPS_CA = !bFPS_CA;

                if (bFPS_CA)
                {
                    _FPS_ON(sFPS, menuSHOWN, _CAfps1_ADDR, hProcess);

                }
                else
                {
                    _FPS_OFF(sFPS, menuSHOWN, _CAfps1_ADDR, hProcess);
                }
            }

            // PERFECT SHOT (VIP OPTION)
            if (GetAsyncKeyState(VK_NUMPAD2) & 1)
            {
                bPerfectShot_CA = !bPerfectShot_CA;
                if (bPerfectShot_CA)
                {
                    _CA_POINTERS(ospread1, ospread2, orecoil, hProcess);
                    _CA_POINTERS_2(oScope1, oScope2, oScope3, oScope4, oScope5, hProcess);
                }
            }

            // FORCE START
            if (GetAsyncKeyState(VK_NUMPAD9) & 1)
            {
                bForceStart_CA = !bForceStart_CA;
                if (bForceStart_CA)
                {
                    _FORCESTART_CA_ON(sFORCE, menuSHOWN, hProcess);
                }
                else
                {
                    _FORCESTART_CA_OFF(sFORCE, menuSHOWN, hProcess);
                }
            }
            
            //Return to Main or Exit
            if (GetAsyncKeyState(VK_SUBTRACT) & 1)
            {
                _clearConsole();
                bGAME_SOCOMCA = false;
                bSOCOM_SERIES_MENU = false;
                menuSHOWN = false;
                return 0;
            }
            if (GetAsyncKeyState(VK_END) & 1)
            {
                _clearConsole();
                bGAME_SOCOMCA = false;
                bSOCOM_SERIES_MENU = false;
                menuSHOWN = false;
                MAINMENU = false;
                return 0;
            }

            // Perfect Shot Function
            if (bPerfectShot_CA)
            {
                //Need to establish if player is in game
                int flag = ReadProcessMemory(hProcess, (BYTE*)_CAplayerPtr_ADDR, &value, sizeof(value), nullptr);
                if (value != 0)
                {
                    int value2;
                    int FLAGA = ReadProcessMemory(hProcess, (LPVOID)orecoil, &value, sizeof(value), NULL);
                    int FLAGB = ReadProcessMemory(hProcess, (LPVOID)oScope2, &value2, sizeof(value2), NULL);
                    if (!HACK_LOOP)
                    {
                        _PS_ON(menuSHOWN, HACK_LOOP, sPSHOT);
                    }

                    if (value != 0)
                    {
                        mem::PS2NopEx((BYTE*)ospread1, 4, hProcess);
                        mem::PS2NopEx((BYTE*)ospread2, 4, hProcess);
                        mem::PS2NopEx((BYTE*)orecoil, 4, hProcess);
                    }

                    if (value2 != 0)
                    {
                        mem::PS2NopEx((BYTE*)oScope1, 4, hProcess);
                        mem::PS2NopEx((BYTE*)oScope2, 4, hProcess);
                        mem::PS2NopEx((BYTE*)oScope3, 4, hProcess);
                        mem::PS2NopEx((BYTE*)oScope4, 4, hProcess);
                        mem::PS2NopEx((BYTE*)oScope5, 4, hProcess);
                    }
                }
                else bPerfectShot_CA = false;
            }
            else if (HACK_LOOP)
            {
                _PS_OFF(HACK_LOOP, bPerfectShot_CA, menuSHOWN, sPSHOT);
            }
        }

        Sleep(10);
    }
    _clearConsole();
    std::cout << "Process Not Found - Returning to main menu" << std::endl;
    bGAME_SOCOM1 = false, bGAME_SOCOM2 = false, bGAME_SOCOM3 = false, bGAME_SOCOMCA = false, bSOCOM_SERIES_MENU = false;
    Sleep(2050);
    _clearConsole();
    return 0;
}

int FarCry3()
{
    //Set Console Window Title
    SetConsoleTitle(L"Far Cry R3L0AD3D | CONSOLE");

    //Establish Variables
    HANDLE hProcess = 0;
    uintptr_t moduleBase = 0, PointerBase = 0;
    uintptr_t healthADDRESS = 0, moneyADDRESS = 0;
    uintptr_t _baseAmmoADDRESS = 0, ammoADDRESS = 0;
    bool HACK_LOOP = false;
    bool bAMMO = false, bMONEY = false;
    string sMONEY = " ", sAMMO = " ";
    
    //For Ammo
    const int newValue = 3;

    //Empty Variables
    int cAMMO;

    std::cout << "Searching for Far Cry 3 Ubisoft Store Edition . . ." << std::endl;
    Sleep(1050);

    // Get proc Id of target process
    DWORD procId = GetProcId(L"farcry3_d3d11.exe");

    if (procId)
    {
        std::cout << "Process found , Connecting . . ." << std::endl;
        Sleep(750);

        //Let user know we have established connection with the process
        std::cout << "Connection Established" << std::endl;
        Sleep(1050);

        // Get Handle to process
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
        std::cout << "Gathering Process Information . . ." << std::endl;
        Sleep(750);

        //Get module base address
        moduleBase = GetModuleBaseAddress(procId, L"FC3_d3d11.dll");
        std::cout << "Established Base Address . . ." << std::endl;
        Sleep(400);

        PointerBase = moduleBase + 0x01E15A38;
        std::cout << "PointerBase: " << "0x" << std::hex << PointerBase << std::endl;
        Sleep(650);
        
        moneyADDRESS = FindDMAAddy(hProcess, PointerBase, { 0x4, 0x38, 0x4, 0x64 });
        std::cout << "MoneyAddress: " << "0x" << std::hex << moneyADDRESS << std::endl;
        Sleep(550);

        ammoADDRESS = FindDMAAddy(hProcess, PointerBase, { 0x4, 0x38, 0x4, 0x20, 0x280, 0x48, 0xCC});
        std::cout << "PointerBase: " << "0x" << std::hex << ammoADDRESS << std::endl;
        Sleep(750);
        
        std::cout << "SUCCESS! , Loading Menu . . ." << std::endl;
        Sleep(2050);
        _clearConsole();
    }
    else
    {
        _clearConsole();
        std::cout << "Process Not Found - Returning to main menu" << std::endl;
        bGAME_FARCRY3 = false;
        Sleep(2050);
        return 0;
    }

    DWORD dwExit = 0;
    while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
    {
        if (bGAME_FARCRY3)
        {
            if (!menuSHOWN)
            {
                menuSHOWN = true;
                _clearConsole();
                MENU_FARCRY_3(sMONEY, sAMMO);
            }

            //ADD $500
            if (GetAsyncKeyState(VK_NUMPAD1) & 1)
            {
                bMONEY = !bMONEY;

                if (bMONEY)
                {
                    int buffer;
                    ReadProcessMemory(hProcess, (BYTE*)moneyADDRESS, &buffer, sizeof(buffer), nullptr);

                    int newValue = buffer + 500;
                    WriteProcessMemory(hProcess, (BYTE*)moneyADDRESS, &newValue, sizeof(newValue), nullptr);

                    std::cout << "$500 ADDED TO PLAYER INVENTORY" << std::endl;
                    bMONEY = false;
                    Sleep(2050);
                    menuSHOWN = false;
                }
            }

            //Infinite Ammo 
            if (GetAsyncKeyState(VK_NUMPAD2) & 1)
            {
                bAMMO = !bAMMO;

                //Once we have established our base address , 
                //we can cross reference if it is still the same in our loop
                _baseAmmoADDRESS = FindDMAAddy(hProcess, PointerBase, { 0x4, 0x38, 0x4, 0x20, 0x280, 0x48, 0xCC });
                ReadProcessMemory(hProcess, (BYTE*)_baseAmmoADDRESS, &cAMMO, sizeof(cAMMO), nullptr); //We can also read our current ammo here , it will stay valid until our weapon has changed
            }

            //Return to Main or Exit
            if (GetAsyncKeyState(VK_SUBTRACT) & 1)
            {
                _clearConsole();
                bGAME_FARCRY3 = false;
                menuSHOWN = false;
                return 0;
            }
            if (GetAsyncKeyState(VK_END) & 1)
            {
                _clearConsole();
                bGAME_FARCRY3 = false;
                menuSHOWN = false;
                MAINMENU = false;
                return 0;
            }

            //LOOPS
            if (bAMMO)
            {
                if (!HACK_LOOP)
                {
                    sAMMO = "X";
                    HACK_LOOP = true;
                    menuSHOWN = false;
                }

                ammoADDRESS = FindDMAAddy(hProcess, PointerBase, { 0x4, 0x38, 0x4, 0x20, 0x280, 0x48, 0xCC });

                if (ammoADDRESS != _baseAmmoADDRESS)
                {
                    _baseAmmoADDRESS = ammoADDRESS;
                    ammoADDRESS = 0;
                    ReadProcessMemory(hProcess, (BYTE*)_baseAmmoADDRESS, &cAMMO, sizeof(cAMMO), nullptr);
                }

                WriteProcessMemory(hProcess, (BYTE*)_baseAmmoADDRESS, &cAMMO, sizeof(cAMMO), nullptr);
            }
            else if (HACK_LOOP)
            {
                HACK_LOOP = false;
                menuSHOWN = false;
                bAMMO = false;
                sAMMO = " ";
            }
        }
    }

    _clearConsole();
    std::cout << "Process Not Found - Returning to main menu" << std::endl;
    bGAME_FARCRY3 = false;
    Sleep(2050);
    return 0;
}

int AssaultCube()
{
    SetConsoleTitle(L"Assault Cube R3L0AD3D | CONSOLE");

    //Establish Variables
    HANDLE hProcess = 0;
    uintptr_t moduleBase = 0, PointerBase = 0, ammoBase = 0, recoilBase = 0;
    uintptr_t _baseHealthADDRESS = 0, healthADDRESS = 0, _baseAmmoADDRESS = 0, ammoADDRESS = 0, playerX = 0, playerY = 0, playerZ = 0;
    bool HACK_LOOP = false, HACK_LOOP2 = false;
    bool bAMMO = false, bHEALTH = false, bRECOIL = false;
    string sHEALTH = " ", sAMMO = " ", sRECOIL = " ";

    //Empty Variables
    int cHEALTH;
    int cARMOR;
    int cAMMO;

    std::cout << "Searching for Assault Cube . . ." << std::endl;    // Text to console for end-user to read
    Sleep(1050);

    // Get proc Id of target process
    DWORD procId = GetProcId(L"ac_client.exe");
    if (procId)
    {
        std::cout << "Process found , Connecting . . ." << std::endl;
        Sleep(750);

        //Let user know we have established connection with the process
        std::cout << "Connection Established" << std::endl;    // Text to console for end-user to read
        Sleep(1050);

        // Get Handle to process
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
        std::cout << "Gathering Process Information . . ." << std::endl;    // Text to console for end-user to read
        Sleep(750);

        //Get module base address
        moduleBase = GetModuleBaseAddress(procId, L"ac_client.exe");
        std::cout << "Established Base Address . . ." << std::endl;
        Sleep(300);

        PointerBase = moduleBase + 0x109B74;
        std::cout << "Player Pointer: " << "0x" << std::hex << PointerBase << std::endl;
        Sleep(650);

        ammoBase = moduleBase + 0x10F4F4;
        std::cout << "AmmoBase Address: " << "0x" << std::hex << ammoBase << std::endl;
        Sleep(500);

        recoilBase = moduleBase + 0x62020;
        std::cout << "Recoil Base Address: " << "0x" << std::hex << recoilBase << std::endl;
        Sleep(700);

        _baseHealthADDRESS = FindDMAAddy(hProcess, PointerBase, { 0xF8 });
        std::cout << "Player Health Address: " << "0x" << std::hex << _baseHealthADDRESS << std::endl;
        Sleep(950);

        _baseAmmoADDRESS = FindDMAAddy(hProcess, ammoBase, { 0x374, 0x14, 0x0 });
        std::cout << "Current Weapon Ammo Address: " << "0x" << std::hex << _baseAmmoADDRESS << std::endl;
        Sleep(450);

        std::cout << "Loading Menu . . ." << std::endl;    // Text to console for end-user to read
        Sleep(2050);    // wait
        _clearConsole();
    }
    else
    {
        _clearConsole();
        std::cout << "Process Not Found - Returning to main menu" << std::endl;
        bGAME_ASSAULT_CUBE = false;
        Sleep(2050);
        return 0;
    }

    DWORD dwExit = 0;
    while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
    {
        if (bGAME_ASSAULT_CUBE)
        {
            if (!menuSHOWN)
            {
                menuSHOWN = true;
                _clearConsole();
                MENU_ASSAULT_CUBE(sHEALTH, sAMMO, sRECOIL);
            }

            if (GetAsyncKeyState(VK_NUMPAD1) & 1)
            {
                bHEALTH = !bHEALTH;

                if (bHEALTH)
                {
                    ReadProcessMemory(hProcess, (BYTE*)healthADDRESS, &cHEALTH, sizeof(cHEALTH), nullptr);
                }
            }

            if (GetAsyncKeyState(VK_NUMPAD2) & 1)
            {
                bAMMO = !bAMMO;

                if (bAMMO)
                {
                    ReadProcessMemory(hProcess, (BYTE*)_baseAmmoADDRESS, &cAMMO, sizeof(cAMMO), nullptr);
                }
            }

            if (GetAsyncKeyState(VK_NUMPAD3) & 1)
            {
                bRECOIL = !bRECOIL;

                if (bRECOIL)
                {
                    sRECOIL = "X";
                    menuSHOWN = false;
                    mem::PatchEx((BYTE*)recoilBase, (BYTE*)"\xC2\x08\x00", 3, hProcess);
                }
                else
                {
                    sRECOIL = " ";
                    menuSHOWN = false;
                    mem::PatchEx((BYTE*)recoilBase, (BYTE*)"\x55\x8b\xEC", 3, hProcess);
                }
            }
            //Return to Main or Exit
            if (GetAsyncKeyState(VK_SUBTRACT) & 1)
            {
                _clearConsole();
                bGAME_ASSAULT_CUBE = false;
                menuSHOWN = false;
                return 0;
            }
            if (GetAsyncKeyState(VK_END) & 1)
            {
                _clearConsole();
                bGAME_ASSAULT_CUBE = false;
                menuSHOWN = false;
                MAINMENU = false;
                return 0;
            }

            if (bHEALTH)
            {
                if (!HACK_LOOP)
                {
                    sHEALTH = "X";
                    HACK_LOOP = true;
                    menuSHOWN = false;
                }
                healthADDRESS = FindDMAAddy(hProcess, PointerBase, { 0xF8 });

                if (healthADDRESS != _baseHealthADDRESS)
                {
                    _baseHealthADDRESS = healthADDRESS;
                    healthADDRESS = 0;
                    ReadProcessMemory(hProcess, (BYTE*)_baseHealthADDRESS, &cHEALTH, sizeof(cHEALTH), nullptr);
                }

                WriteProcessMemory(hProcess, (BYTE*)_baseHealthADDRESS, &cHEALTH, sizeof(cHEALTH), nullptr);
            }
            else if (HACK_LOOP)
            {
                HACK_LOOP = false;
                menuSHOWN = false;
                bHEALTH = false;
                sHEALTH = " ";
            }

            if (bAMMO)
            {
                if (!HACK_LOOP2)
                {
                    sAMMO = "X";
                    HACK_LOOP2 = true;
                    menuSHOWN = false;
                }
                ammoADDRESS = FindDMAAddy(hProcess, ammoBase, { 0x374, 0x14, 0x0 });

                if (ammoADDRESS != _baseAmmoADDRESS)
                {
                    _baseAmmoADDRESS = ammoADDRESS;
                    ammoADDRESS = 0;
                    ReadProcessMemory(hProcess, (BYTE*)_baseAmmoADDRESS, &cAMMO, sizeof(cAMMO), nullptr);
                }

                WriteProcessMemory(hProcess, (BYTE*)_baseAmmoADDRESS, &cAMMO, sizeof(cAMMO), nullptr);
            }
            else if (HACK_LOOP2)
            {
                HACK_LOOP2 = false;
                menuSHOWN = false;
                bAMMO = false;
                sAMMO = " ";
            }
        }
    }
    _clearConsole();
    std::cout << "Process Not Found - Returning to main menu" << std::endl;
    bGAME_ASSAULT_CUBE = false;
    Sleep(2050);
    return 0;
}

int TheBindingofIsaac()
{
    string HEALTH = " ", BOMBS = " ", DAMAGE = " ", FIRERATE = " ", COINS = " ";
    SetConsoleTitle(L"The Binding of Isaac - DLC | CONSOLE");
    _clearConsole();
    MENU_ISAAC(HEALTH, BOMBS, DAMAGE, FIRERATE, COINS);

    while (MENU_ISAAC)
    {
        if (GetAsyncKeyState(VK_SUBTRACT) & 1)
        {
            //Sleep(5050);
            _clearConsole();
            //std::cout << "Process Not Found - Returning to main menu" << std::endl;
            bGAME_ISAAC = false;
            //Sleep(2050);
            return 0;
        }
    }
}

//x64 (damnit)
int RPCS3()
{
    return 0;
}

int DeathlyStillness()
{
    //Set Console Window Title
    SetConsoleTitle(L"Deathly Stillness R3L0AD3D | CONSOLE");
    string sFREEZE = " ", sAMMO = " ";
    _clearConsole();
    MENU_DEATHLY_STILLNESS(sAMMO, sFREEZE);
    while (MENU_DEATHLY_STILLNESS)
    {
        if (GetAsyncKeyState(VK_SUBTRACT) & 1)
        {
            _clearConsole();
            bGAME_Deathly_Stillness = false;
            return 0;
        }
    }

    #pragma region // HACK

    //#pragma region  //Establish Variables
    //HANDLE hProcess = 0;
    //uintptr_t moduleBase = 0, pos_pointerBase = 0, ammo_pointerBase = 0;
    //uint64_t hard_PLAYERY = 0;
    //uint64_t hard_AMMO = 0;
    //bool bAMMO = false, bFREEZE = false;
    //bool HACK_LOOP = false, HACK_LOOP2 = false;
    //
    ////Empty Variables
    //int cAMMO;
    //float CURRENTPOS;
    //string sFREEZE = " ", sAMMO = " ";
    //#pragma endregion
    //
    //// Get proc Id of target process
    //DWORD procId = GetProcId(L"DeathlyStillness-Win64-Shipping.exe");

    //if (procId)
    //{
    //    std::cout << "Process found , Connecting . . ." << std::endl;
    //    Sleep(750);

    //    //Let user know we have established connection with the process
    //    std::cout << "Connection Established" << std::endl;
    //    Sleep(1050);

    //    // Get Handle to process
    //    hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
    //    std::cout << "Gathering Process Information . . ." << std::endl;
    //    Sleep(750);

    //    //Get module base address
    //    moduleBase = GetModuleBaseAddress(procId, L"DeathlyStillness-Win64-Shipping.exe"); //unsigned __int64
    //    std::cout << "Established Base Address . . ." << std::endl;
    //    Sleep(300);

    //    pos_pointerBase = moduleBase + 0x0410B0C0;
    //    ammo_pointerBase = moduleBase + 0x045B5BC8;

    //    std::cout << "SUCCESS! , Loading Menu . . ." << std::endl;
    //    Sleep(2050);
    //    _clearConsole();
    //}
    //else
    //{
    //    _clearConsole();
    //    std::cout << "Process Not Found - Returning to main menu" << std::endl;
    //    bGAME_Deathly_Stillness = false;
    //    Sleep(2050);
    //    return 0;
    //}

    //DWORD dwExit = 0;
    //while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
    //{
    //    if (!menuSHOWN)
    //    {
    //        menuSHOWN = true;
    //        _clearConsole();
    //        MENU_DEATHLY_STILLNESS(sAMMO, sFREEZE);
    //    }

    //    if (GetAsyncKeyState(VK_NUMPAD1) & 1)
    //    {
    //        bAMMO = !bAMMO;
    //        hard_AMMO = FindDMAAddy(hProcess, ammo_pointerBase, { 0xEA8, 0x20, 0x290 });
    //        
    //        if (bAMMO)
    //        {
    //            ReadProcessMemory(hProcess, (BYTE*)hard_AMMO, &cAMMO, sizeof(cAMMO), nullptr);
    //        }
    //    }

    //    if (GetAsyncKeyState(VK_NUMPAD2) & 1)
    //    {
    //        bFREEZE = !bFREEZE;
    //        if (bFREEZE)
    //        {
    //            //Resolve pointer chain
    //            hard_PLAYERY = FindDMAAddy(hProcess, pos_pointerBase, { 0x480, 0x130, 0x1D8 });

    //            //Read value
    //            ReadProcessMemory(hProcess, (BYTE*)hard_PLAYERY, &CURRENTPOS, sizeof(CURRENTPOS), nullptr);
    //        }
    //    }

    //    if (GetAsyncKeyState(VK_SPACE) & 1)
    //    {
    //        //Resolve pointer chain
    //        hard_PLAYERY = FindDMAAddy(hProcess, pos_pointerBase, { 0x480, 0x130, 0x1D8 });

    //        //CHEAT
    //        float buffer;
    //        ReadProcessMemory(hProcess, (BYTE*)hard_PLAYERY, &buffer, sizeof(buffer), nullptr);
    //        float VALUE = buffer + 100;
    //        WriteProcessMemory(hProcess, (BYTE*)hard_PLAYERY, &VALUE, sizeof(VALUE), nullptr);
    //    }

    //    if (GetAsyncKeyState(VK_LCONTROL) & 1)
    //    {
    //        //Resolve pointer chain
    //        hard_PLAYERY = FindDMAAddy(hProcess, pos_pointerBase, { 0x480, 0x130, 0x1D8 });

    //        //CHEAT
    //        float buffer;
    //        ReadProcessMemory(hProcess, (BYTE*)hard_PLAYERY, &buffer, sizeof(buffer), nullptr);
    //        float VALUE = buffer - 100;
    //        WriteProcessMemory(hProcess, (BYTE*)hard_PLAYERY, &VALUE, sizeof(VALUE), nullptr);
    //    }

    //    //Return to Main or Exit
    //    if (GetAsyncKeyState(VK_SUBTRACT) & 1)
    //    {
    //        _clearConsole();
    //        bGAME_Deathly_Stillness = false;
    //        menuSHOWN = false;
    //        return 0;
    //    }
    //    if (GetAsyncKeyState(VK_END) & 1)
    //    {
    //        _clearConsole();
    //        bGAME_Deathly_Stillness = false;
    //        menuSHOWN = false;
    //        MAINMENU = false;
    //        return 0;
    //    }

    //    //LOOPS

    //    if (bFREEZE)
    //    {
    //        if (!HACK_LOOP)
    //        {
    //            sFREEZE = "X";
    //            HACK_LOOP = true;
    //            menuSHOWN = false;
    //        }
    //        WriteProcessMemory(hProcess, (BYTE*)hard_PLAYERY, &CURRENTPOS, sizeof(CURRENTPOS), nullptr);
    //    }
    //    else if (HACK_LOOP)
    //    {
    //        HACK_LOOP = false;
    //        menuSHOWN = false;
    //        bAMMO = false;
    //        sFREEZE = " ";
    //    }

    //    if (bAMMO)
    //    {
    //        if (!HACK_LOOP2)
    //        {
    //            sAMMO = "X";
    //            HACK_LOOP2 = true;
    //            menuSHOWN = false;
    //        }
    //        WriteProcessMemory(hProcess, (BYTE*)hard_AMMO, &cAMMO, sizeof(cAMMO), nullptr);
    //    }
    //    else if (HACK_LOOP2)
    //    {
    //        HACK_LOOP2 = false;
    //        menuSHOWN = false;
    //        bAMMO = false;
    //        sAMMO = " ";
    //    }
    //}

    ////If we get this far it means the process was terminated somehow
    //_clearConsole();
    //std::cout << "Process Not Found - Returning to main menu" << std::endl;
    //bGAME_Deathly_Stillness = false;
    //Sleep(2050);
    //return 0;

    #pragma endregion
}