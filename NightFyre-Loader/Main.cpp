//v0.0.6
//UPDATE NOTES
//- Updated Hack Loop Thread
//- 

#include "stdafx.h"

void _ANCHOR();
int _socomLANDING();
int _codLANDING();

//GAME MENUS
int ePSXe();
int PCSX2();
int FarCry3();
int AssaultCube();
int TheBindingofIsaac();
int DeathlyStillness();
int WorldAtWar();
//-----------------------

#pragma region  //VARIABLES
//MAIN
static bool MAINMENU = false;
static bool menuSHOWN = false;
static bool bSOCOM_SERIES_MENU = false;
static bool bCOD_SERIES_MENU = false;

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

//Call of Duty

static bool bGAME_WorldAtWar = false;

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

#pragma endregion

///MAIN MENU
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
            _socomLANDING();

            //Hopefully* anything after this is only executed after main2 has returned 0. 
            //Therefore we will want to repopulate main, which we can do simply by running through it again
            _MAINMENU();
        }

        //Call of Duty Series
        if (GetAsyncKeyState(VK_NUMPAD2) & 1)
        {
            _clearConsole();
            _codLANDING();

            //This should only execute if we leave main3
            _MAINMENU();
        }

        //Far Cry 3
        if (GetAsyncKeyState(VK_NUMPAD3) & 1)
        {
            bGAME_FARCRY3 = true;
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

        //Assault Cube
        if (GetAsyncKeyState(VK_NUMPAD6) & 1)
        {
            bGAME_ASSAULT_CUBE = true;
            _ANCHOR();
        }

        //Deathly Stilness x64 (TEST)
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

///ALT MENUS
int _socomLANDING()
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
int _codLANDING()
{
    MENU_COD_SELECT();
    bCOD_SERIES_MENU = true;
    while (MENU_COD_SELECT)
    {
        if (GetAsyncKeyState(VK_NUMPAD2) & 1)
        {
            bGAME_WorldAtWar = true;
            _ANCHOR();
        }

        //Return to Main or Exit
        if (GetAsyncKeyState(VK_SUBTRACT) & 1)
        {
            _clearConsole();
            bCOD_SERIES_MENU = false;
            return 0;
        }
        if (GetAsyncKeyState(VK_END) & 1)
        {
            _clearConsole();
            bCOD_SERIES_MENU = false;
            MAINMENU = false;
            return 0;
        }

        if (!bCOD_SERIES_MENU)
        {
            _clearConsole();
            std::cout << "If for some reason this window does not close on its own , you may go ahead and close it." << std::endl;
            return 0;
        }
    }
}

///VERY IMPORTANT
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
    if (bGAME_WorldAtWar)
    {
        selectCODwaw();
        WorldAtWar();
    }
    _MAINMENU();
}

///GAME MENUS
int ePSXe()
{
    SetConsoleTitle(L"ePSXe v2.0.5 - Final Fantasy 7 | CONSOLE");
    #pragma region //Establish Variables
    HANDLE hProcess = 0;
    uintptr_t moduleBase = 0;
    uintptr_t currentHP1_ADDR = 0, maxHP1_ADDR = 0, currentMP1_ADDR = 0;
    uintptr_t currentHP2_ADDR = 0, maxHP2_ADDR = 0, currentMP2_ADDR = 0;
    uintptr_t currentHP3_ADDR = 0, maxHP3_ADDR = 0, currentMP3_ADDR = 0;
    uintptr_t GIL_ADDRESS = 0;
    bool bHP = false, bMP = false, bGIL = false;
    string sHP = " ", sMP = " ", sGIL = " ";
    bool HACK_LOOP = false;

    //Empty Variables
    int cHP1, mHP1;
    byte cMP1, mMP1;
    int cHP2, mHP2;
    byte cMP2, mMP2;
    int cHP3, mHP3;
    byte cMP3, mMP3;
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

        GIL_ADDRESS = moduleBase + 0xB1F280;

        //Character 1 Pointers
        currentHP1_ADDR = moduleBase + 0xB7A42C;
        maxHP1_ADDR = moduleBase + 0xB7A430;
        currentMP1_ADDR = moduleBase + 0xB7A428;

        //Character 2 Pointers
        currentHP2_ADDR = moduleBase + 0xB7A494;
        maxHP2_ADDR = moduleBase + 0xB7A498;
        currentMP2_ADDR = moduleBase + 0x0B7A490;
        
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

            //Battlescreen
            
            //HP
            if (GetAsyncKeyState(VK_NUMPAD1) & 1)
            {
                bHP = !bHP;

                if (bHP)
                {
                    //We need to establish max hp first
                    ReadProcessMemory(hProcess, (BYTE*)maxHP1_ADDR, &mHP1, sizeof(mHP1), nullptr);
                    ReadProcessMemory(hProcess, (BYTE*)maxHP2_ADDR, &mHP2, sizeof(mHP2), nullptr);
                }
            }

            //MP
            if (GetAsyncKeyState(VK_NUMPAD2) & 1)
            {
                bMP = !bMP;

                if (bMP)
                {
                    ReadProcessMemory(hProcess, (BYTE*)currentMP1_ADDR, &mMP1, sizeof(mMP1), nullptr);
                    ReadProcessMemory(hProcess, (BYTE*)currentMP2_ADDR, &mMP2, sizeof(mMP2), nullptr);
                    //ReadProcessMemory(hProcess, (BYTE*)currentMP3_ADDR, &mMP3, sizeof(mMP3), nullptr);
                }
            }

            //GIL
            if (GetAsyncKeyState(VK_NUMPAD3) & 1)
            {
                bGIL = !bGIL;
                if (bGIL)
                {
                    int a;
                    //Read Current Gil
                    ReadProcessMemory(hProcess, (BYTE*)GIL_ADDRESS, &a, sizeof(a), nullptr);

                    //Make Adjustments
                    int newValue = a + 20000;

                    if (newValue > 10000000)
                    {
                        newValue = 9999999;
                    }
                    
                    //Send Gil
                    WriteProcessMemory(hProcess, (BYTE*)GIL_ADDRESS, &newValue, sizeof(newValue), nullptr);

                    //Send Message to menu
                    std::cout << "GIL SENT" << std::endl;
                    Sleep(2050);

                    //Cleanup
                    bGIL = false;
                    menuSHOWN = false;
                }
            }

            //LOOP
            if (bHP)
            {
                if (!HACK_LOOP)
                {
                    sHP = "X";
                    HACK_LOOP = true;
                    menuSHOWN = false;
                }
                else if (sHP != "X")
                {
                    sHP = "X";
                    menuSHOWN = false;
                }
                FF7::battleHP(hProcess, currentHP1_ADDR, currentHP2_ADDR, currentHP3_ADDR, cHP1, cHP2, cHP3, mHP1, mHP2, mHP3);

            }
            if (bMP)
            {
                if (!HACK_LOOP)
                {
                    sMP = "X";
                    HACK_LOOP = true;
                    menuSHOWN = false;
                }
                else if (sMP != "X")
                {
                    sMP = "X";
                    menuSHOWN = false;
                }
                FF7::battleMP(hProcess, currentMP1_ADDR, currentMP2_ADDR, currentMP3_ADDR, cMP1, cMP2, cMP3, mMP1, mMP2, mMP3);
            }

            //Hopefully this new method should handle everything I want in a single loop 
            //Instead of having multiple loops
            if (HACK_LOOP)
            {
                if (!bHP && sHP != " ")
                {
                    sHP = " ";
                    menuSHOWN = false;
                }
                if (!bMP && sMP != " ")
                {
                    sMP = " ";
                    menuSHOWN = false;
                }

                //If all patches are requiring a loop are disabled
                //Then we can also disable the loop
                if (!bHP && !bMP)
                {
                    HACK_LOOP = false;
                }
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

// - Need to introduce a single loop for all hacks which will keep anything toggled so the user does not have to manually re activate on each round
//- FOG , FPS , Crosshair color all reset between rounds
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
    uintptr_t oPlayerY = 0;

    //GAME BOOLS
    bool bPerfectShot_S1 = false, bFPS_S1 = false;                                                       //SOCOM 1
    bool bPerfectShot_S2 = false, bFPS_S2 = false, bForceStart_S2 = false;                               //SOCOM 2
    bool bFOG_S2 = false, bBRIGHTNESS_S2 = false, bNVG_S2 = false, bCCOLOR_S2 = false;                   //SOCOM 2 (cont...)
    bool color0 = true, color1 = false, color2 = false, color3 = false, color4 = false;                  //SOCOM 2 (cont...)
    bool bWideScreen = false;                                                                            //SOCOM 2 (cont...)
    bool bPerfectShot_S3 = false, bNoSway_S3 = false, bFPS_S3 = false;                                                       //SOCOM 3
    bool bForceStart_CA = false, bFPS_CA = false, bPerfectShot_CA = false;                               //SOCOM CA
    bool bYpos_CA = false;
    
    //bool for hacks in threads
    bool HACK_LOOP = false, HACK_LOOP2 = false;

    //Strings for MENU indicators
    string sPSHOT = " ", sFPS = "30", sFORCE = " ", sFOG = " ", sBRIGHTNESS = " ", sNVG = " ", sCOLOR = "0", sWIDESCREEN = " ";
    string sNOSWAY = " ", sDEBUG = " ";
    
    //Empty Value for Read and Write Process Memory
    int value;
    int value2;
    int value3;
    int value4;
    int _flagSway;
    int _flagSway2;
    int _cPos;
    #pragma endregion
    
    std::cout << "Searching for PCSX2 NightFyre Edition . . ." << std::endl;
    Sleep(1050);

    // Get proc Id of target process
    DWORD procId = GetProcId(L"PlayStation2.exe");
    DWORD procId_dev = GetProcId(L"pcsx2DEV.exe");

    if (procId || procId_dev)
    {
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
        if (procId_dev)
        {
            hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId_dev);
            moduleBase = GetModuleBaseAddress(procId_dev, L"PlayStation2.exe");
            _clearConsole();
        }
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
                std::cout << "RESTORING DEFAULTS . . . ." << std::endl;
                Sleep(1050);
                if (bFPS_S1)
                {
                    _FPS_OFF(sFPS, menuSHOWN, _S1framerate1_ADDR, hProcess);
                }
                if (bPerfectShot_S1)
                {
                    SOCOM1_PERFECTSHOT_OFF(menuSHOWN, sPSHOT, hProcess);
                }
                std::cout << "SUCCESFULLY RESTORED DATA TO DEFAULTS , RETURNING TO MENU" << std::endl;
                Sleep(1050);
                _clearConsole();
                bGAME_SOCOM1 = false;
                bSOCOM_SERIES_MENU = false;
                menuSHOWN = false;
                return 0;
            }
            if (GetAsyncKeyState(VK_END) & 1)
            {
                _clearConsole();
                std::cout << "RESTORING DEFAULTS . . . ." << std::endl;
                Sleep(1050);
                if (bFPS_S1)
                {
                    _FPS_OFF(sFPS, menuSHOWN, _S1framerate1_ADDR, hProcess);
                }
                if (bPerfectShot_S1)
                {
                    SOCOM1_PERFECTSHOT_OFF(menuSHOWN, sPSHOT, hProcess);
                }
                std::cout << "SUCCESFULLY RESTORED DATA TO DEFAULTS , RETURNING TO MENU" << std::endl;
                Sleep(1050);
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
                    int inGAME;
                    ReadProcessMemory(hProcess, (BYTE*)_S2playerPTR, &inGAME, sizeof(inGAME), nullptr);
                    if (inGAME != 0)
                    {
                        _FPS_ON(sFPS, menuSHOWN, _S2fps1_ADDR, hProcess);
                    }
                    else
                    {
                        std::cout << "Please wait until your are in game to use this patch" << std::endl;
                        Sleep(2000);
                    }
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
                    int inGAME;
                    ReadProcessMemory(hProcess, (BYTE*)_S2playerPTR, &inGAME, sizeof(inGAME), nullptr);
                    if (inGAME != 0)
                    {
                        sFOG = "X";
                        menuSHOWN = false;
                        mem::PS2NopEx((BYTE*)_S2fog_ADDR, 4, hProcess);
                    }
                    else
                    {
                        std::cout << "Please wait until your are in game to use this patch" << std::endl;
                        Sleep(2000);
                    }
                }
                else
                {
                    sFOG = " ";
                    menuSHOWN = false;
                    mem::PatchEx((BYTE*)_S2fog_ADDR, (BYTE*)"\x01\x00\x00\x00", 4, hProcess);
                }
            }

            //BRIGHTNESS (NEED TO LOOP)
            if (GetAsyncKeyState(VK_NUMPAD4) & 1)
            {
                bBRIGHTNESS_S2 = !bBRIGHTNESS_S2;
                
                if (bBRIGHTNESS_S2)
                {
                    int inGAME;
                    ReadProcessMemory(hProcess, (BYTE*)_S2playerPTR, &inGAME, sizeof(inGAME), nullptr);
                    if (inGAME != 0)
                    {
                        sBRIGHTNESS = "X";
                        menuSHOWN = false;
                        mem::PatchEx((BYTE*)_S2mapBrightness1, (BYTE*)"\x00\x00\x50\x40", 4, hProcess);
                        mem::PatchEx((BYTE*)_S2mapBrightness2, (BYTE*)"\x00\x00\x50\x40", 4, hProcess);
                        mem::PatchEx((BYTE*)_S2mapBrightness3, (BYTE*)"\x00\x00\x50\x40", 4, hProcess);
                    }
                    else
                    {
                        std::cout << "Please wait until your are in game to use this patch" << std::endl;
                        Sleep(2000);
                    }
                }
                else
                {
                    sBRIGHTNESS = " ";
                    menuSHOWN = false;
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

                //IN GAME CHECK
                int inGAME;
                ReadProcessMemory(hProcess, (BYTE*)_S2playerPTR, &inGAME, sizeof(inGAME), nullptr);
                if (inGAME != 0)
                {
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
                else
                {
                    std::cout << "Please wait until your are in game to use this patch" << std::endl;
                    Sleep(2000);
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
                std::cout << "RESTORING DEFAULTS . . . ." << std::endl;
                Sleep(1050);
                SOCOM::_return(hProcess, menuSHOWN, bFPS_S2, sFPS, bPerfectShot_S2, sPSHOT, HACK_LOOP, bFOG_S2, sFOG, 
                    bBRIGHTNESS_S2, bNVG_S2, sNVG, bCCOLOR_S2, sCOLOR, bWideScreen, sWIDESCREEN);
                std::cout << "SUCCESFULLY RESTORED DATA TO DEFAULTS , RETURNING TO MENU" << std::endl;
                Sleep(1050);
                _clearConsole();
                bGAME_SOCOM2 = false;
                bSOCOM_SERIES_MENU = false;
                menuSHOWN = false;
                return 0;
            }

            if (GetAsyncKeyState(VK_END) & 1)
            {
                _clearConsole();
                std::cout << "RESTORING DEFAULTS . . . ." << std::endl;
                Sleep(1050);
                SOCOM::_return(hProcess, menuSHOWN, bFPS_S2, sFPS, bPerfectShot_S2, sPSHOT, HACK_LOOP, bFOG_S2, sFOG, bBRIGHTNESS_S2, bNVG_S2, sNVG, bCCOLOR_S2, sCOLOR, bWideScreen, sWIDESCREEN);
                std::cout << "SUCCESFULLY RESTORED DATA TO DEFAULTS , RETURNING TO MENU" << std::endl;
                Sleep(1050);
                _clearConsole();
                bGAME_SOCOM2 = false;
                bSOCOM_SERIES_MENU = false;
                menuSHOWN = false;
                MAINMENU = false;
                return 0;
            }

            //PROF. LUPIN
            //THE FOLLOWING PATCHES EXECUTE EVERY 10 SECONDS
            //FURTHERMORE, CHECKS IF PLAYER IS IN GAME ARE MADE
            //IF PLAYER IS NOT IN GAME , DEFAULTS ARE RESTORED IF NOT ALREADY
            //AS WELL AS, METHOD WILL WAIT FOR PLAYER TO BE IN GAME AGAIN.
            //THEREFORE , THE PATCH IS STILL "TOGGLED" REQUIRING NO USER INPUT
            //AS SOON AS A MATCH RESTARTS , THE PATCH WILL BE APPLIED AGAIN
            if (bPerfectShot_S2)
            {
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
                value = 0;
                value2 = 0;
            }
            
            if (bBRIGHTNESS_S2)
            {
                //if (!HACK_LOOP2)
                //{
                //    HACK_LOOP2 = true;
                //}
                ////Patch 0.0.51
                ////Check if player is in game
                ////If player is not in game , we do not want to change anything
                //int inGAME;
                //ReadProcessMemory(hProcess, (BYTE*)_S2playerPTR, &inGAME, sizeof(inGAME), nullptr);
                //if (inGAME != 0)
                //{
                //    int bFLAG = ReadProcessMemory(hProcess, (BYTE*)_S2mapBrightness1, &value3, sizeof(value3), nullptr);
                //    if (value3 != 0)
                //    {
                //        mem::PatchEx((BYTE*)_S2mapBrightness1, (BYTE*)"\x00\x00\x50\x40", 4, hProcess);
                //        mem::PatchEx((BYTE*)_S2mapBrightness2, (BYTE*)"\x00\x00\x50\x40", 4, hProcess);
                //        mem::PatchEx((BYTE*)_S2mapBrightness3, (BYTE*)"\x00\x00\x50\x40", 4, hProcess);
                //    }
                //}
                //else
                //{
                //    bBRIGHTNESS_S2 = false;
                //}
            }
            else if (HACK_LOOP2)
            {
                //ReadProcessMemory(hProcess, (BYTE*)_S2mapBrightness1, &value4, sizeof(value4), nullptr);
                //if (value4 != 0)
                //{
                //    //mem::PS2NopEx((BYTE*)_S2mapBrightness1, 4, hProcess);
                //    //mem::PS2NopEx((BYTE*)_S2mapBrightness2, 4, hProcess);
                //    //mem::PS2NopEx((BYTE*)_S2mapBrightness3, 4, hProcess);
                //}
                //value3 = 0;
                //value4 = 0;
                //bBRIGHTNESS_S2 = false;
                //HACK_LOOP2 = false;
                //sBRIGHTNESS = " ";
                //menuSHOWN = false;
            }

            //THE FOLLOWING ARE CHECKS IF THE GAME HAS ENDED
            //AS SOON AS THE GAME ENDS, PATCHES WILL ALL RETURN DEFAULT VALUE
            //THIS SHOULD HAPPEN BEFORE RETURNING TO LOBBY
            //THIS WILL ALSO HAPPEN IN BETWEEN ROUNDS , USER WILL NEED TO TOGGLE AGAIN
            if (bFOG_S2)
            {
                int inGAME;
                ReadProcessMemory(hProcess, (BYTE*)_S2playerPTR, &inGAME, sizeof(inGAME), nullptr);
                if (inGAME == 0)
                {
                    sFOG = " ";
                    menuSHOWN = false;
                    mem::PatchEx((BYTE*)_S2fog_ADDR, (BYTE*)"\x01\x00\x00\x00", 4, hProcess);
                }
            }

            if (bCCOLOR_S2)
            {
                int inGAME;
                ReadProcessMemory(hProcess, (BYTE*)_S2playerPTR, &inGAME, sizeof(inGAME), nullptr);
                if (inGAME == 0)
                {
                    int a;
                    ReadProcessMemory(hProcess, (BYTE*)_S2crosshairR, &a, sizeof(a), nullptr);
                    if (a != 1128792064)
                    {
                        mem::PatchEx((BYTE*)_S2crosshairR, (BYTE*)"\x00\x00\x48\x43", 4, hProcess);
                        mem::PatchEx((BYTE*)_S2crosshairG, (BYTE*)"\x00\x00\x48\x43", 4, hProcess);
                        mem::PatchEx((BYTE*)_S2crosshairB, (BYTE*)"\x00\x00\xC0\x41", 4, hProcess);
                        sCOLOR = "0";
                        bCCOLOR_S2 = false;
                        menuSHOWN = false;
                    }
                }
            }

            if (bFPS_S2)
            {
                int inGAME;
                ReadProcessMemory(hProcess, (BYTE*)_S2playerPTR, &inGAME, sizeof(inGAME), nullptr);
                if (inGAME == 0)
                {
                    _FPS_OFF(sFPS, menuSHOWN, _S2fps1_ADDR, hProcess);
                }
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

            //PERFECT SHOT (VIP OPTION)
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
                std::cout << "RESTORING DEFAULTS . . . ." << std::endl;
                Sleep(1050);
                if (bFPS_S3)
                {
                    _FPS_OFF(sFPS, menuSHOWN, _S3fps1_ADDR, hProcess);
                }
                if (bPerfectShot_S3)
                {
                    bPerfectShot_S3 = false;
                }
                if (bNoSway_S3)
                {
                    bNoSway_S3 = false;
                }
                std::cout << "SUCCESFULLY RESTORED DATA TO DEFAULTS , RETURNING TO MENU" << std::endl;
                Sleep(1050);
                _clearConsole();
                bGAME_SOCOM3 = false;
                bSOCOM_SERIES_MENU = false;
                menuSHOWN = false;
                return 0;
            }
            if (GetAsyncKeyState(VK_END) & 1)
            {
                _clearConsole();
                std::cout << "RESTORING DEFAULTS . . . ." << std::endl;
                Sleep(1050);
                if (bFPS_S3)
                {
                    _FPS_OFF(sFPS, menuSHOWN, _S3fps1_ADDR, hProcess);
                }
                if (bPerfectShot_S3)
                {
                    bPerfectShot_S3 = false;
                }
                if (bNoSway_S3)
                {
                    bNoSway_S3 = false;
                }
                std::cout << "SUCCESFULLY RESTORED DATA TO DEFAULTS , RETURNING TO MENU" << std::endl;
                Sleep(1050);
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
                MENU_SOCOMCA(sFPS, sPSHOT, sDEBUG,sFORCE);
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

            //Freeze Y Pos
            //if (GetAsyncKeyState(VK_NUMPAD3) & 1)
            //{
            //    bYpos_CA = !bYpos_CA;

            //    if (bYpos_CA)
            //    {
            //        sDEBUG = true;
            //        menuSHOWN = false;
            //        oPlayerY = PS2_FindDMAAddy(hProcess, _CAplayerPtr_ADDR, { 0x20 });
            //        int _InGame;
            //        int flag = ReadProcessMemory(hProcess, (BYTE*)_CAplayerPtr_ADDR, &_InGame, sizeof(_InGame), nullptr);
            //        if (flag != 0)
            //        {
            //            ReadProcessMemory(hProcess, (BYTE*)oPlayerY, &_cPos, sizeof(_cPos), nullptr);
            //        }
            //    }
            //}

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
                std::cout << "RESTORING DEFAULTS . . . ." << std::endl;
                Sleep(1050);
                if (bFPS_CA)
                {
                    _FPS_OFF(sFPS, menuSHOWN, _CAfps1_ADDR, hProcess);
                }
                if (bPerfectShot_CA)
                {
                    bPerfectShot_CA = false;
                    HACK_LOOP = false;
                }
                if (bForceStart_CA)
                {
                    _FORCESTART_CA_OFF(sFORCE, menuSHOWN, hProcess);
                }
                std::cout << "SUCCESFULLY RESTORED DATA TO DEFAULTS , RETURNING TO MENU" << std::endl;
                Sleep(1050);
                _clearConsole();
                bGAME_SOCOMCA = false;
                bSOCOM_SERIES_MENU = false;
                menuSHOWN = false;
                return 0;
            }
            if (GetAsyncKeyState(VK_END) & 1)
            {
                _clearConsole();
                std::cout << "RESTORING DEFAULTS . . . ." << std::endl;
                Sleep(1050);
                if (bFPS_CA)
                {
                    _FPS_OFF(sFPS, menuSHOWN, _CAfps1_ADDR, hProcess);
                }
                if (bPerfectShot_CA)
                {
                    bPerfectShot_CA = false;
                    HACK_LOOP = false;
                }
                if (bForceStart_CA)
                {
                    _FORCESTART_CA_OFF(sFORCE, menuSHOWN, hProcess);
                }
                std::cout << "SUCCESFULLY RESTORED DATA TO DEFAULTS , RETURNING TO MENU" << std::endl;
                Sleep(1050);
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
            if (bYpos_CA)
            {
                //WriteProcessMemory(hProcess, (BYTE*)oPlayerY, &_cPos, sizeof(_cPos), nullptr);
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

///PATCH v0.0.6
//UPDATED HACK LOOP
int FarCry3()
{
    //Set Console Window Title
    SetConsoleTitle(L"Far Cry 3 R3L0AD3D | CONSOLE");

    #pragma region VARIABLES
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
    #pragma endregion
    
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
                //RESTORE DEFAULTS
                std::cout << "Restoring defaults , Please do not close window" << std::endl;
                Sleep(2050);
                if (bAMMO)
                {
                    HACK_LOOP = false;
                    bAMMO = false;
                    sAMMO = " ";
                }
                std::cout << "Sucessfully restored game data to defaults!" << std::endl;
                _clearConsole();
                bGAME_FARCRY3 = false;
                menuSHOWN = false;
                return 0;
            }
            if (GetAsyncKeyState(VK_END) & 1)
            {
                _clearConsole();
                std::cout << "Restoring defaults , Please do not close window" << std::endl;
                Sleep(2050);
                if (bAMMO)
                {
                    HACK_LOOP = false;
                    bAMMO = false;
                    sAMMO = " ";
                }
                std::cout << "Sucessfully restored game data to defaults!" << std::endl;
                bGAME_FARCRY3 = false;
                menuSHOWN = false;
                MAINMENU = false;
                return 0;
            }

            //HACK LOOP
            if (bAMMO)
            {
                if (!HACK_LOOP)
                {
                    sAMMO = "X";
                    HACK_LOOP = true;
                    menuSHOWN = false;
                }
                else if (sAMMO != "X")
                {
                    sAMMO = "X";
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
                if (bAMMO && sAMMO != " ")
                {
                    bAMMO = false;
                    sAMMO = " ";
                    menuSHOWN = false;
                }
                if (!bAMMO)
                {
                    HACK_LOOP = false;
                }
            }
        }
    }

    _clearConsole();
    std::cout << "Process Not Found - Returning to main menu" << std::endl;
    bGAME_FARCRY3 = false;
    Sleep(2050);
    return 0;
}

///PATCH v0.0.6
//UPDATED HACK LOOP
int AssaultCube()
{
    SetConsoleTitle(L"Assault Cube R3L0AD3D | CONSOLE");

    #pragma region //VARIABLES
    //Establish Variables
    HANDLE hProcess = 0;
    uintptr_t moduleBase = 0, PointerBase = 0, ammoBase = 0, recoilBase = 0;
    uintptr_t entityAddress = 0, _baseHealthADDRESS = 0, healthADDRESS = 0, _baseAmmoADDRESS = 0, ammoADDRESS = 0, playerX = 0, playerY = 0, playerZ = 0;
    uintptr_t spectateAddress = 0, invisibleAddress = 0;
    bool HACK_LOOP = false;
    bool bAMMO = false, bHEALTH = false, bRECOIL = false, bNOCLIP = false;
    string sHEALTH = " ", sAMMO = " ", sRECOIL = " ", sNOCLIP = " ";

    //Empty Variables
    int cHEALTH;
    int cARMOR;
    int cAMMO;
    #pragma endregion
    
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
                MENU_ASSAULT_CUBE(sHEALTH, sAMMO, sRECOIL, sNOCLIP);
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

            if (GetAsyncKeyState(VK_NUMPAD4) & 1)
            {
                bNOCLIP = !bNOCLIP;
                ReadProcessMemory(hProcess, (BYTE*)ammoBase, &entityAddress, sizeof(entityAddress), nullptr);
                invisibleAddress = entityAddress + 0x82;
                spectateAddress = entityAddress + 0x338;

                if (bNOCLIP)
                {
                    int invisibleON = 11;
                    int spectateON = 5;
                    WriteProcessMemory(hProcess, (BYTE*)invisibleAddress, &invisibleON, sizeof(invisibleON), nullptr);
                    WriteProcessMemory(hProcess, (BYTE*)spectateAddress, &spectateON, sizeof(spectateON), nullptr);
                    sNOCLIP = "X";
                    menuSHOWN = false;
                }
                else
                {
                    int invisibleON = 0;
                    int spectateON = 0;
                    WriteProcessMemory(hProcess, (BYTE*)invisibleAddress, &invisibleON, sizeof(invisibleON), nullptr);
                    WriteProcessMemory(hProcess, (BYTE*)spectateAddress, &spectateON, sizeof(spectateON), nullptr);
                    sNOCLIP = " ";
                    menuSHOWN = false;
                }
            }

            //Return to Main or Exit
            if (GetAsyncKeyState(VK_SUBTRACT) & 1)
            {
                _clearConsole();
                //RESTORE DEFAULTS
                std::cout << "Restoring defaults , Please do not close window" << std::endl;
                Sleep(2050);
                if (bHEALTH)
                {
                    HACK_LOOP = false;
                    bHEALTH = false;
                    sHEALTH = " ";
                }
                if (bAMMO)
                {
                    HACK_LOOP = false;
                    bAMMO = false;
                    sAMMO = " ";
                }
                if (bRECOIL)
                {
                    mem::PatchEx((BYTE*)recoilBase, (BYTE*)"\x55\x8b\xEC", 3, hProcess);
                    bRECOIL = false;
                    sRECOIL = " ";
                }
                if (bNOCLIP)
                {
                    int invisibleON = 0;
                    int spectateON = 0;
                    WriteProcessMemory(hProcess, (BYTE*)invisibleAddress, &invisibleON, sizeof(invisibleON), nullptr);
                    WriteProcessMemory(hProcess, (BYTE*)spectateAddress, &spectateON, sizeof(spectateON), nullptr);
                    sNOCLIP = " ";
                    bNOCLIP = false;
                }
                std::cout << "Sucessfully restored game data to defaults!" << std::endl;
                _clearConsole();
                bGAME_ASSAULT_CUBE = false;
                menuSHOWN = false;
                return 0;
            }
            if (GetAsyncKeyState(VK_END) & 1)
            {
                _clearConsole();
                //RESTORE DEFAULTS
                std::cout << "Restoring defaults , Please do not close window" << std::endl;
                Sleep(2050);
                if (bHEALTH)
                {
                    HACK_LOOP = false;
                    bHEALTH = false;
                    sHEALTH = " ";
                }
                if (bAMMO)
                {
                    HACK_LOOP = false;
                    bAMMO = false;
                    sAMMO = " ";
                }
                if (bRECOIL)
                {
                    mem::PatchEx((BYTE*)recoilBase, (BYTE*)"\x55\x8b\xEC", 3, hProcess);
                    bRECOIL = false;
                    sRECOIL = " ";
                }
                if (bNOCLIP)
                {
                    int invisibleON = 0;
                    int spectateON = 0;
                    WriteProcessMemory(hProcess, (BYTE*)invisibleAddress, &invisibleON, sizeof(invisibleON), nullptr);
                    WriteProcessMemory(hProcess, (BYTE*)spectateAddress, &spectateON, sizeof(spectateON), nullptr);
                    sNOCLIP = " ";
                    bNOCLIP = false;
                }
                std::cout << "Sucessfully restored game data to defaults!" << std::endl;
                _clearConsole();
                bGAME_ASSAULT_CUBE = false;
                menuSHOWN = false;
                MAINMENU = false;
                return 0;
            }

            //HACK THREADS
            if (bHEALTH)
            {
                if (!HACK_LOOP)
                {
                    sHEALTH = "X";
                    HACK_LOOP = true;
                    menuSHOWN = false;
                }
                else if (sHEALTH != " ")
                {
                    sHEALTH = "X";
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

            if (bAMMO)
            {
                if (!HACK_LOOP)
                {
                    sAMMO = "X";
                    HACK_LOOP = true;
                    menuSHOWN = false;
                }
                else if (sAMMO != "X")
                {
                    sAMMO = "X";
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

            //MAIN LOOP
            if (HACK_LOOP)
            {
                if (!bHEALTH && sHEALTH != " ")
                {
                    menuSHOWN = false;
                    bHEALTH = false;
                    sHEALTH = " ";
                }

                if (!bAMMO && sAMMO != " ")
                {
                    menuSHOWN = false;
                    bAMMO = false;
                    sAMMO = " ";
                }

                if (!bHEALTH && !bAMMO)
                {
                    HACK_LOOP = false;
                }
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
    SetConsoleTitle(L"The Binding of Isaac: Wrath of The Lamb | CONSOLE");
 
    #pragma region VARIABLES
    HANDLE hProcess = 0;
    uintptr_t moduleBase = 0;
    uintptr_t HEALTH_ADDR = 0, BOMBS_ADDR = 0, DAMAGE_ADDR = 0, FIRERATE_ADDR = 0, COINS_ADDR = 0, COINS2_ADDR = 0;
    bool HACK_LOOP = false;

    //BOOLS
    bool bHEALTH = false, bBOMBS = false, bDAMAGE = false, bFIRERATE = false, bCOINS = false;
    
    //STRINGS
    string sHEALTH = " ", sBOMBS = " ", sDAMAGE = " ", sFIRERATE = " ", sCOINS = " ";
    #pragma endregion
    
    std::cout << "Searching for The Binding of Isaac: Wrath of The Lamb" << std::endl;
    Sleep(1050);

    DWORD procID = GetProcId(L"isaac.exe");
    if (procID)
    {
        std::cout << "Process found , Connecting . . ." << std::endl;
        Sleep(750);

        //Let user know we have established connection with the process
        std::cout << "Connection Established" << std::endl;
        Sleep(1050);

        // Get Handle to process
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procID);
        std::cout << "Gathering Process Information . . ." << std::endl;
        Sleep(750);

        //Get module base address
        moduleBase = GetModuleBaseAddress(procID, L"isaac.exe");
        std::cout << "Established Base Address . . ." << std::endl;
        Sleep(750);

        HEALTH_ADDR = 0x1656f75E;
        BOMBS_ADDR = 0x1658A05A;
        DAMAGE_ADDR = 0x1655C1B4;
        FIRERATE_ADDR = 0x1658BAA4;
        COINS_ADDR = 0x1657C0FF;
        COINS2_ADDR = 0x1657C6A2;
        std::cout << "Resolving Pointers" << std::endl;

        std::cout << "SUCCESS! , Loading Menu . . ." << std::endl;
        Sleep(2050);
        _clearConsole();
    }
    else
    {
        _clearConsole();
        std::cout << "Process Not Found - Returning to main menu" << std::endl;
        bGAME_ISAAC = false;
        Sleep(2050);
        return 0;
    }
    DWORD dwExit = 0;
    
    while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
    {
        if (bGAME_ISAAC)
        {
            if (!menuSHOWN)
            {
                menuSHOWN = true;
                _clearConsole();
                MENU_ISAAC(sHEALTH, sBOMBS, sDAMAGE, sFIRERATE, sCOINS);
            }

            //INFINITE HEALTH
            if (GetAsyncKeyState(VK_NUMPAD1) & 1)
            {
                bHEALTH = !bHEALTH;

                if (bHEALTH)
                {
                    int VALUE;
                    ReadProcessMemory((BYTE*)hProcess, (BYTE*)HEALTH_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 93736715)
                    {
                        mem::PatchEx((BYTE*)HEALTH_ADDR, (BYTE*)"\x0A", 1, hProcess);
                        sHEALTH = "X";
                        menuSHOWN = false;
                    }
                }
                else
                {
                    int VALUE;
                    ReadProcessMemory((BYTE*)hProcess, (BYTE*)HEALTH_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 93736714)
                    {
                        mem::PatchEx((BYTE*)HEALTH_ADDR, (BYTE*)"\x0B", 1, hProcess);
                        sHEALTH = " ";
                        menuSHOWN = false;
                    }
                }
            }
            
            //INFINITE BOMBS
            if (GetAsyncKeyState(VK_NUMPAD2) & 1)
            {
                bBOMBS = !bBOMBS;

                if (bBOMBS)
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)BOMBS_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 43601745)
                    {
                        mem::PatchEx((BYTE*)BOMBS_ADDR, (BYTE*)"\x50", 1, hProcess);
                        sBOMBS = "X";
                        menuSHOWN = false;
                    }
                }
                else
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)BOMBS_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 43601744)
                    {
                        mem::PatchEx((BYTE*)BOMBS_ADDR, (BYTE*)"\x51", 1, hProcess);
                        sBOMBS = " ";
                        menuSHOWN = false;
                    }
                }
            }
            
            //MAX DAMAGE
            if (GetAsyncKeyState(VK_NUMPAD3) & 1)
            {
                bDAMAGE = !bDAMAGE;
                if (bDAMAGE)
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)DAMAGE_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 0)
                    {
                        mem::PatchEx((BYTE*)DAMAGE_ADDR, (BYTE*)"\x00\x40\x6F\x40", 3, hProcess);
                        sDAMAGE = "X";
                        menuSHOWN = false;
                    }
                }
                else
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)DAMAGE_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE != 0)
                    {
                        mem::PatchEx((BYTE*)DAMAGE_ADDR, (BYTE*)"\x00\x00\x00\x00", 3, hProcess);
                        sDAMAGE = " ";
                        menuSHOWN = false;
                    }
                }
            }
            
            //MAX FIRE RATE
            if (GetAsyncKeyState(VK_NUMPAD4) & 1)
            {
                bFIRERATE = !bFIRERATE;
                if (bFIRERATE)
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)FIRERATE_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 1543)
                    {
                        mem::PatchEx((BYTE*)FIRERATE_ADDR, (BYTE*)"\x07\xFF", 2, hProcess);
                        sFIRERATE = "X";
                        menuSHOWN = false;
                    }
                }
                else
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)FIRERATE_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 65287)
                    {
                        mem::PatchEx((BYTE*)FIRERATE_ADDR, (BYTE*)"\x07\x06", 2, hProcess);
                        sFIRERATE = " ";
                        menuSHOWN = false;
                    }
                }
            }

            //INFINITE COINS
            if (GetAsyncKeyState(VK_NUMPAD5) & 1)
            {
                bCOINS = !bCOINS;
                if (bCOINS)
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)0x1657C0FC, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 1364071944)
                    {
                        mem::PatchEx((BYTE*)COINS_ADDR, (BYTE*)"\x02", 1, hProcess);
                        mem::PatchEx((BYTE*)COINS2_ADDR, (BYTE*)"\x47", 1, hProcess);
                    }
                    sCOINS = "X";
                    menuSHOWN = false;
                }
                else
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)0x1657C0FC, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 38671880)
                    {
                        mem::PatchEx((BYTE*)COINS_ADDR, (BYTE*)"\x51", 1, hProcess);
                        mem::PatchEx((BYTE*)COINS2_ADDR, (BYTE*)"\x0B", 1, hProcess);
                    }
                    sCOINS = " ";
                    menuSHOWN = false;
                }
            }
            
            //Return to Main or Exit
            if (GetAsyncKeyState(VK_SUBTRACT) & 1)
            {
                _clearConsole();
                std::cout << "Restoring defaults , Please do not close window" << std::endl;
                Sleep(2050);
                if (bHEALTH)
                {
                    int VALUE;
                    ReadProcessMemory((BYTE*)hProcess, (BYTE*)HEALTH_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 93736714)
                    {
                        int newVALUE = 93736715;
                        WriteProcessMemory(hProcess, (BYTE*)HEALTH_ADDR, &newVALUE, sizeof(newVALUE), nullptr);
                        sHEALTH = " ";
                        bHEALTH = false;
                    }
                }
                if (bBOMBS)
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)BOMBS_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 43601744)
                    {
                        int newVALUE = 43601745;
                        WriteProcessMemory(hProcess, (BYTE*)BOMBS_ADDR, &newVALUE, sizeof(newVALUE), nullptr);
                        sBOMBS = " ";
                        bBOMBS = false;
                    }
                }
                if (bDAMAGE)
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)DAMAGE_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE != 0)
                    {
                        mem::PatchEx((BYTE*)DAMAGE_ADDR, (BYTE*)"\x00\x00\x00\x00", 3, hProcess);
                        sDAMAGE = " ";
                        bDAMAGE = false;
                    }
                }
                if (bFIRERATE)
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)FIRERATE_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 65287)
                    {
                        mem::PatchEx((BYTE*)FIRERATE_ADDR, (BYTE*)"\x07\x06", 2, hProcess);
                        sFIRERATE = " ";
                        bFIRERATE = false;
                    }
                }
                if (bCOINS)
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)0x1657C0FC, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 38671880)
                    {
                        mem::PatchEx((BYTE*)COINS_ADDR, (BYTE*)"\x51", 1, hProcess);
                        mem::PatchEx((BYTE*)COINS2_ADDR, (BYTE*)"\x0B", 1, hProcess);
                    }
                    sCOINS = " ";
                    bCOINS = false;
                }
                std::cout << "Sucessfully restored game data to defaults!" << std::endl;
                _clearConsole();
                bGAME_ISAAC = false;
                menuSHOWN = false;
                return 0;
            }
            if (GetAsyncKeyState(VK_END) & 1)
            {
                _clearConsole();
                std::cout << "Restoring defaults , Please do not close window" << std::endl;
                Sleep(2050);
                if (bHEALTH)
                {
                    int VALUE;
                    ReadProcessMemory((BYTE*)hProcess, (BYTE*)HEALTH_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 93736714)
                    {
                        int newVALUE = 93736715;
                        WriteProcessMemory(hProcess, (BYTE*)HEALTH_ADDR, &newVALUE, sizeof(newVALUE), nullptr);
                        sHEALTH = " ";
                        bHEALTH = false;
                    }
                }
                if (bBOMBS)
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)BOMBS_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 43601744)
                    {
                        int newVALUE = 43601745;
                        WriteProcessMemory(hProcess, (BYTE*)BOMBS_ADDR, &newVALUE, sizeof(newVALUE), nullptr);
                        sBOMBS = " ";
                        bBOMBS = false;
                    }
                }
                if (bDAMAGE)
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)DAMAGE_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE != 0)
                    {
                        mem::PatchEx((BYTE*)DAMAGE_ADDR, (BYTE*)"\x00\x00\x00\x00", 3, hProcess);
                        sDAMAGE = " ";
                        bDAMAGE = false;
                    }
                }
                if (bFIRERATE)
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)FIRERATE_ADDR, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 65287)
                    {
                        mem::PatchEx((BYTE*)FIRERATE_ADDR, (BYTE*)"\x07\x06", 2, hProcess);
                        sFIRERATE = " ";
                        bFIRERATE = false;
                    }
                }
                if (bCOINS)
                {
                    int VALUE;
                    ReadProcessMemory(hProcess, (BYTE*)0x1657C0FC, &VALUE, sizeof(VALUE), nullptr);
                    if (VALUE == 38671880)
                    {
                        mem::PatchEx((BYTE*)COINS_ADDR, (BYTE*)"\x51", 1, hProcess);
                        mem::PatchEx((BYTE*)COINS2_ADDR, (BYTE*)"\x0B", 1, hProcess);
                    }
                    sCOINS = " ";
                    bCOINS = false;
                }
                std::cout << "Sucessfully restored game data to defaults!" << std::endl;
                _clearConsole();
                bGAME_ISAAC = false;
                menuSHOWN = false;
                MAINMENU = false;
                return 0;
            }
        }
    }
    _clearConsole();
    std::cout << "Process Not Found - Returning to main menu" << std::endl;
    bGAME_ISAAC = false;
    Sleep(2050);
    return 0;
}

#pragma region //Call of Duty Series
int Cod4()
{
    return 0;
}

int WorldAtWar()
{
    SetConsoleTitle(L"Call of Duty: World at War | CONSOLE");
    HANDLE hProcess = 0;
    uintptr_t moduleBase = 0;
    uintptr_t pHEALTH = 0, pAMMO = 0, prFIRE = 0, pNOCLIP = 0, pLASER = 0, pFPS = 0, pFOG = 0, pFOV = 0, pSPRINT = 0, pPOINTS = 0;
    
    //Hack Bools
    bool healthhack_enabled = false;
    bool ammohack_enabled = false;
    bool rapidfire_enabled = false;
    bool NoClip_enabled = false;
    bool Laser_Enabled = false;
    bool DrawFPS_Enabled = false;
    bool ProMod_Enabled = false;
    bool CentsMod_Enabled = false;
    bool GiveMoney_Enabled = false;

    //Variable Strings for menu
    string sHEALTH = " ", sAMMO = " ", srFIRE = " ", sFLY = " ", sLASER = " ", sPROMOD = " ", sFPS = " ", sxCENTx = " ", sPOINTS = " ";

    //Get Proc ID
    DWORD procId = GetProcId(L"cod5sp.exe");
    std::cout << "Searching for process . . ." << std::endl;
    Sleep(500);

    if (procId)
    {
        std::cout << "Process Found!" << std::endl;
        Sleep(700);
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

        moduleBase = GetModuleBaseAddress(procId, L"cod5sp.exe");

        std::cout << "Obtained handle to process" << std::endl;
        Sleep(1400);
        pHEALTH = 0x004F31F4;
        pAMMO = 0x0041E619;
        prFIRE = 0x00420BCB;
        pNOCLIP = 0x018EF2A4;
        pLASER = 0x021C6F94;
        pFPS = 0x021B51E0;
        pFOG = 0x21D0E10;
        pFOV = 0x021C4F98;
        pSPRINT = 0x21CBBC4;
        pPOINTS = 0x018EF124;

        std::cout << "Established base address and resolved pointer chains" << std::endl;
        Sleep(750);
        std::cout << "Loading Menu . . ." << std::endl;
        Sleep(500);
    }
    else
    {
        _clearConsole();
        std::cout << "Process Not Found - Returning to main menu" << std::endl;
        bGAME_WorldAtWar = false;
        bCOD_SERIES_MENU = false;
        Sleep(2050);
        return 0;
    }

    DWORD dwExit = 0;
    while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
    {
        if (bGAME_WorldAtWar)
        {
            if (!menuSHOWN)
            {
                menuSHOWN = true;
                _clearConsole();
                MENU_CODwaw(sHEALTH, sAMMO, srFIRE, sFLY, sLASER, sPROMOD, sFPS, sxCENTx, sPOINTS);
            }

            //INFINITE HEALTH
            if (GetAsyncKeyState(VK_NUMPAD1) & 1)
            {
                waw::HEALTH(healthhack_enabled, pHEALTH, hProcess, sHEALTH, menuSHOWN);
            }

            //UNLIMITED AMMO
            if (GetAsyncKeyState(VK_NUMPAD2))
            {
                waw::AMMO(ammohack_enabled, pAMMO, hProcess, sAMMO, menuSHOWN);
            }

            //RAPID FIRE
            if (GetAsyncKeyState(VK_NUMPAD3))
            {
                waw::RAPIDFIRE(rapidfire_enabled, prFIRE, hProcess, srFIRE, menuSHOWN);
            }

            //NO CLIP
            if (GetAsyncKeyState(VK_NUMPAD4))
            {
                waw::BOOL(NoClip_enabled, pNOCLIP, hProcess, sFLY, menuSHOWN);
            }

            //LASER
            if (GetAsyncKeyState(VK_NUMPAD5))
            {
                waw::BOOL(Laser_Enabled, pLASER, hProcess, sLASER, menuSHOWN);
            }

            //PRO MOD
            if (GetAsyncKeyState(VK_NUMPAD6))
            {
                waw::PROMOD(ProMod_Enabled, pFOG, pFOV, pSPRINT, hProcess, sPROMOD, menuSHOWN);
            }

            //DRAW FPS
            if (GetAsyncKeyState(VK_NUMPAD7))
            {
                waw::FPS(DrawFPS_Enabled, pFPS, hProcess, sFPS, menuSHOWN);
            }

            //xCENTx MOD
            if (GetAsyncKeyState(VK_F8))
            {
                //patch::CENTHACK(CentsMod_Enabled, pHEALTH, pAMMO, prFIRE, pLASER, pFOG, pFOV, pSPRINT, pFPS, hProc, sxCENTx, menuSHOWN);
            }

            //GIVE POINTS
            if (GetAsyncKeyState(VK_NUMPAD9))
            {
                waw::POINTS(pPOINTS, hProcess, sPOINTS, menuSHOWN);
            }

            //RETURN and EXIT
            if (GetAsyncKeyState(VK_SUBTRACT) & 1)
            {
                _clearConsole();
                
                //RESTORE DEFAULTS
                std::cout << "Restoring defaults , Please do not close window" << std::endl;
                Sleep(2050);
                if (healthhack_enabled)
                {
                    mem::PatchEx((BYTE*)pHEALTH, (BYTE*)"\x89\x96\xC8\x01\x00\x00", 6, hProcess);
                    sHEALTH = " ";
                }
                if (ammohack_enabled)
                {
                    mem::PatchEx((BYTE*)pAMMO, (BYTE*)"\x89\x84\x8F\xFC\x05\x00\x00", 7, hProcess);
                    sAMMO = " ";
                }
                if (rapidfire_enabled)
                {
                    mem::PatchEx((BYTE*)prFIRE, (BYTE*)"\xE8\x10\xFA\xFF\xFF", 5, hProcess);
                    srFIRE = " ";
                }
                if (NoClip_enabled)
                {
                    mem::PatchEx((BYTE*)pNOCLIP, (BYTE*)"\x00", 1, hProcess);
                    sFLY = " ";
                }
                if (Laser_Enabled)
                {
                    mem::PatchEx((BYTE*)pLASER, (BYTE*)"\x00", 1, hProcess);
                    sLASER = " ";
                }
                if (ProMod_Enabled)
                {
                    mem::PatchEx((BYTE*)pFOG, (BYTE*)"\x00", 1, hProcess);
                    mem::PatchEx((BYTE*)pSPRINT, (BYTE*)"\x00\x00\x82\x42", 4, hProcess);
                    mem::PatchEx((BYTE*)pFOV, (BYTE*)"\x00", 1, hProcess);
                }
                if (DrawFPS_Enabled)
                {
                    mem::PatchEx((BYTE*)pFPS, (BYTE*)"\x00", 1, hProcess);
                    sFPS = " ";
                }
                std::cout << "Sucessfully restored game data to defaults!" << std::endl;
                _clearConsole();
                Sleep(2050);
                bGAME_WorldAtWar = false;
                menuSHOWN = false;
                return 0;
            }
            if (GetAsyncKeyState(VK_END) & 1)
            {
                _clearConsole();

                //RESTORE DEFAULTS
                std::cout << "Restoring defaults , Please do not close window" << std::endl;
                Sleep(2050);
                if (healthhack_enabled)
                {
                    mem::PatchEx((BYTE*)pHEALTH, (BYTE*)"\x89\x96\xC8\x01\x00\x00", 6, hProcess);
                    sHEALTH = " ";
                }
                if (ammohack_enabled)
                {
                    mem::PatchEx((BYTE*)pAMMO, (BYTE*)"\x89\x84\x8F\xFC\x05\x00\x00", 7, hProcess);
                    sAMMO = " ";
                }
                if (rapidfire_enabled)
                {
                    mem::PatchEx((BYTE*)prFIRE, (BYTE*)"\xE8\x10\xFA\xFF\xFF", 5, hProcess);
                    srFIRE = " ";
                }
                if (NoClip_enabled)
                {
                    mem::PatchEx((BYTE*)pNOCLIP, (BYTE*)"\x00", 1, hProcess);
                    sFLY = " ";
                }
                if (Laser_Enabled)
                {
                    mem::PatchEx((BYTE*)pLASER, (BYTE*)"\x00", 1, hProcess);
                    sLASER = " ";
                }
                if (ProMod_Enabled)
                {
                    mem::PatchEx((BYTE*)pFOG, (BYTE*)"\x00", 1, hProcess);
                    mem::PatchEx((BYTE*)pSPRINT, (BYTE*)"\x00\x00\x82\x42", 4, hProcess);
                    mem::PatchEx((BYTE*)pFOV, (BYTE*)"\x00", 1, hProcess);
                }
                if (DrawFPS_Enabled)
                {
                    mem::PatchEx((BYTE*)pFPS, (BYTE*)"\x00", 1, hProcess);
                    sFPS = " ";
                }
                std::cout << "Sucessfully restored game data to defaults!" << std::endl;
                _clearConsole();
                bGAME_WorldAtWar = false;
                menuSHOWN = false;
                MAINMENU = false;
                return 0;
            }
        }
        Sleep(100);
    }
    _clearConsole();
    std::cout << "Process Not Found - Returning to main menu" << std::endl;
    bGAME_WorldAtWar = false;
    bCOD_SERIES_MENU = false;
    Sleep(2050);
    return 0;
}

int MW2()
{
    return 0;
}
#pragma endregion

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