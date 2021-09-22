#include "stdafx.h"

#pragma region //MAIN MENU
void _clearConsole()
{
    system("cls");
}

void _setConsole()
{
    //Set Cursor to Draw From Beginning
    //Credit : Acidix -- Guided Hacking 
    COORD coords;
    coords.X = 0;
    coords.Y = 0;
    HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(stdHandle, coords);
}

void _MAINMENU()
{
    SetConsoleTitle(L"NightFyre L0AD3R | CONSOLE");
    _clearConsole();
    std::cout << "       _____________________________    __________________________ \n";
    std::cout << "      |------------GAMES------------|  |  YouTube -> NightFyreTV  |\n";
    std::cout << "      | [1] SOCOM SERIES     (PCSX2)|  |  Discord -> xCENTx#0001  |\n";
    std::cout << "      | [2] Call of Duty Series     |  |  GitHub  -> xCENTx       |\n";
    std::cout << "      | [3] Far Cry 3               |  |-----Special-Mentions-----|\n";
    std::cout << "      | [4] Binding of Isaac        |  |  - GuidedHacking.com     |\n";
    std::cout << "      | [5] Final Fantasy 7  (ePSXe)|  |  - UnknownCheats.com     |\n";
    std::cout << "      | [6] Assault Cube            |  |  - Cronotrigga           |\n";
    std::cout << "      | [7]                         |  |  - bismofunyuns          |\n";
    std::cout << "      | [8]                         |  |  - Bravo                 |\n";
    std::cout << "      | [9] Deathly Stillness       |  |  - Harry62               |\n";
    std::cout << "      | [END] EXIT                  |  |                          |\n";
    std::cout << "      |----------NightFyre----------|  |--------------------------|\n";
    std::cout << R"(
 /$$   /$$ /$$           /$$         /$$     /$$$$$$$$                           
| $$$ | $$|__/          | $$        | $$    | $$_____/                           
| $$$$| $$ /$$  /$$$$$$ | $$$$$$$  /$$$$$$  | $$    /$$   /$$  /$$$$$$   /$$$$$$ 
| $$ $$ $$| $$ /$$__  $$| $$__  $$|_  $$_/  | $$$$$| $$  | $$ /$$__  $$ /$$__  $$
| $$  $$$$| $$| $$  \ $$| $$  \ $$  | $$    | $$__/| $$  | $$| $$  \__/| $$$$$$$$
| $$\  $$$| $$| $$  | $$| $$  | $$  | $$ /$$| $$   | $$  | $$| $$      | $$_____/
| $$ \  $$| $$|  $$$$$$$| $$  | $$  |  $$$$/| $$   |  $$$$$$$| $$      |  $$$$$$$
|__/  \__/|__/ \____  $$|__/  |__/   \___/  |__/    \____  $$|__/       \_______/
               /$$  \ $$                            /$$  | $$                    
              |  $$$$$$/                           |  $$$$$$/                    
               \______/                             \______/                     
                       v0.0.55 (alpha - [VIP] preview)
)" << std::endl;
}

//ALT MENUS FOR GAMES WITH MULTIPLE VERSIONS
void MENU_SOCOM_SELECT()
{
    _setConsole();
    std::cout << " ___________________________ \n";
    std::cout << "|-----------GAMES-----------|\n";
    std::cout << "| [1] SOCOM 1               |\n";
    std::cout << "| [2] SOCOM 2               |\n";
    std::cout << "| [3] SOCOM 3               |\n";
    std::cout << "| [4] SOCOM : CA            |\n";
    std::cout << "| [-] MAIN MENU             |\n";
    std::cout << "| [END] QUIT                |\n";
    std::cout << "|---------NightFyre---------| v1.0" << std::endl;
}

void MENU_COD_SELECT()
{
    _setConsole();
    std::cout << " ___________________________ \n";
    std::cout << "|-----------GAMES-----------|\n";
    std::cout << "| [1] CoD4 Modern Warfare   |\n";
    std::cout << "| [2] CoD  World at War     |\n";
    std::cout << "| [3] CoD  Modern Warfare 2 |\n";
    std::cout << "| [5] CoD  Black Ops        |\n";
    std::cout << "| [6] CoD  Modern Warfare 3 |\n";
    std::cout << "| [7] CoD  Black Ops 2      |\n";
    std::cout << "| [8] CoD  Ghosts           |\n";
    std::cout << "| [9] CoD  Black Ops 3      |\n";
    std::cout << "| [-] MAIN MENU             |\n";
    std::cout << "| [END] QUIT                |\n";
    std::cout << "|---------NightFyre---------| v0.1" << std::endl;
    std::cout << R"(
::ATTENTION::
CoD 5 World at War Is the only functional menu for now
)" << std::endl;
}
#pragma endregion


//1
#pragma region //SOCOM SERIES
void select_S1()
{
    _clearConsole();
    _artS1();
    Sleep(2050);
}

void select_S2()
{
    _clearConsole();
    _artS2();
    Sleep(2050);
}

void select_S3()
{
    _clearConsole();
    _artS3();
    Sleep(2050);
}

void select_CA()
{
    _clearConsole();
    _artCA();
    Sleep(2050);
}

void _artS1()
{
    _clearConsole();
    std::cout << R"(
  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$  /$$      /$$         /$$  
 /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$| $$$    /$$$       /$$$$  
| $$  \__/| $$  \ $$| $$  \__/| $$  \ $$| $$$$  /$$$$      |_  $$  
|  $$$$$$ | $$  | $$| $$      | $$  | $$| $$ $$/$$ $$        | $$  
 \____  $$| $$  | $$| $$      | $$  | $$| $$  $$$| $$        | $$  
 /$$  \ $$| $$  | $$| $$    $$| $$  | $$| $$\  $ | $$        | $$  
|  $$$$$$/|  $$$$$$/|  $$$$$$/|  $$$$$$/| $$ \/  | $$       /$$$$$$
 \______/  \______/  \______/  \______/ |__/     |__/      |______/
)" << std::endl;
}

void _artS2()
{
    _clearConsole();
    std::cout << R"(
  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$  /$$      /$$        /$$$$$$ 
 /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$| $$$    /$$$       /$$__  $$
| $$  \__/| $$  \ $$| $$  \__/| $$  \ $$| $$$$  /$$$$      |__/  \ $$
|  $$$$$$ | $$  | $$| $$      | $$  | $$| $$ $$/$$ $$        /$$$$$$/
 \____  $$| $$  | $$| $$      | $$  | $$| $$  $$$| $$       /$$____/ 
 /$$  \ $$| $$  | $$| $$    $$| $$  | $$| $$\  $ | $$      | $$      
|  $$$$$$/|  $$$$$$/|  $$$$$$/|  $$$$$$/| $$ \/  | $$      | $$$$$$$$
 \______/  \______/  \______/  \______/ |__/     |__/      |________/
)" << std::endl;
}

void _artS3()
{
    _clearConsole();
    std::cout << R"(
  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$  /$$      /$$        /$$$$$$ 
 /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$| $$$    /$$$       /$$__  $$
| $$  \__/| $$  \ $$| $$  \__/| $$  \ $$| $$$$  /$$$$      |__/  \ $$
|  $$$$$$ | $$  | $$| $$      | $$  | $$| $$ $$/$$ $$         /$$$$$/
 \____  $$| $$  | $$| $$      | $$  | $$| $$  $$$| $$        |___  $$
 /$$  \ $$| $$  | $$| $$    $$| $$  | $$| $$\  $ | $$       /$$  \ $$
|  $$$$$$/|  $$$$$$/|  $$$$$$/|  $$$$$$/| $$ \/  | $$      |  $$$$$$/
 \______/  \______/  \______/  \______/ |__/     |__/       \______/ 
)" << std::endl;
}

void _artCA()
{
    _clearConsole();
    std::cout << R"(
  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$  /$$      /$$                         
 /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$| $$$    /$$$                         
| $$  \__/| $$  \ $$| $$  \__/| $$  \ $$| $$$$  /$$$$                         
|  $$$$$$ | $$  | $$| $$      | $$  | $$| $$ $$/$$ $$                         
 \____  $$| $$  | $$| $$      | $$  | $$| $$  $$$| $$                         
 /$$  \ $$| $$  | $$| $$    $$| $$  | $$| $$\  $ | $$                         
|  $$$$$$/|  $$$$$$/|  $$$$$$/|  $$$$$$/| $$ \/  | $$                         
 \______/  \______/  \______/  \______/ |__/     |__/                         
  /$$$$$$                          /$$       /$$                           /$$
 /$$__  $$                        | $$      |__/                          | $$
| $$  \__/  /$$$$$$  /$$$$$$/$$$$ | $$$$$$$  /$$ /$$$$$$$   /$$$$$$   /$$$$$$$
| $$       /$$__  $$| $$_  $$_  $$| $$__  $$| $$| $$__  $$ /$$__  $$ /$$__  $$
| $$      | $$  \ $$| $$ \ $$ \ $$| $$  \ $$| $$| $$  \ $$| $$$$$$$$| $$  | $$
| $$    $$| $$  | $$| $$ | $$ | $$| $$  | $$| $$| $$  | $$| $$_____/| $$  | $$
|  $$$$$$/|  $$$$$$/| $$ | $$ | $$| $$$$$$$/| $$| $$  | $$|  $$$$$$$|  $$$$$$$
 \______/  \______/ |__/ |__/ |__/|_______/ |__/|__/  |__/ \_______/ \_______/
  /$$$$$$                                         /$$   /$$                   
 /$$__  $$                                       | $$  | $$                   
| $$  \ $$  /$$$$$$$ /$$$$$$$  /$$$$$$  /$$   /$$| $$ /$$$$$$                 
| $$$$$$$$ /$$_____//$$_____/ |____  $$| $$  | $$| $$|_  $$_/                 
| $$__  $$|  $$$$$$|  $$$$$$   /$$$$$$$| $$  | $$| $$  | $$                   
| $$  | $$ \____  $$\____  $$ /$$__  $$| $$  | $$| $$  | $$ /$$               
| $$  | $$ /$$$$$$$//$$$$$$$/|  $$$$$$$|  $$$$$$/| $$  |  $$$$/               
|__/  |__/|_______/|_______/  \_______/ \______/ |__/   \___/                 
)" << std::endl;
}

void MENU_SOCOM1(string& FPS, string& PERFECTSHOT)
{
    _setConsole();
    std::cout << " ___________________________ \n";
    std::cout << "|----------PATCHES----------|\n";
    std::cout << "| [1] FPS MOD:      => [" << FPS << "] |\n";
    std::cout << "| [2] PERFECT SHOT: => [" << PERFECTSHOT << "]  |\n";
    std::cout << "| [-] MAIN MENU             |\n";
    std::cout << "| [END] QUIT                |\n";
    std::cout << "|-------SOCOM 1----xCENTx---|" << std::endl;
}

void MENU_SOCOM2(string& FPS, string& PERFECTSHOT, string& FORCESTART, string& FOG, string& NVG, string& COLOR, string& WIDESCREEN, string& BRIGHTNESS)
{
    _setConsole();
    std::cout << " ______________________________ \n";
    std::cout << "|------------PATCHES-----------|\n";
    std::cout << "|[1] FPS MOD:          => [" << FPS << "] |\n";
    std::cout << "|[2] PERFECT SHOT:     => [" << PERFECTSHOT << "]  |\n";
    std::cout << "|[3] MAP FOG:          => [" << FOG << "]  |\n";
    std::cout << "|[4] BRIGHTNESS:       => [" << BRIGHTNESS << "]  |\n";
    std::cout << "|[5] NVG PATCH - bismo => [" << NVG << "]  |\n";
    std::cout << "|[6] CROSSHAIR COLOR   => [" << COLOR << "]  |\n";
    std::cout << "|[7] WIDESCREEN MOD    => [" << WIDESCREEN << "]  |\n";
    std::cout << "|[9] FORCE START:      => [" << FORCESTART << "]  |\n";
    std::cout << "|[-] MAIN MENU                 |\n";
    std::cout << "|[END] QUIT                    |\n";
    std::cout << "|--------SOCOM 2-----xCENTx----|" << std::endl;
}

void MENU_SOCOM3(string& FPS, string& PERFECTSHOT, string& NOSWAY)
{
    _setConsole();
    std::cout << " ___________________________ \n";
    std::cout << "|----------PATCHES----------|\n";
    std::cout << "|[1] FPS:           => [" << FPS << "] |\n";
    std::cout << "|[2] PERFECT SHOT:  => [" << PERFECTSHOT << "]  |\n";
    std::cout << "|[2] NO SWAY:        => [" << NOSWAY << "]  |\n";
    std::cout << "|[-] MAIN MENU              |\n";
    std::cout << "|[END] QUIT                 |\n";
    std::cout << "|-------SOCOM 3----xCENTx---|" << std::endl;
}

void MENU_SOCOMCA(string& FPS, string& PERFECTSHOT, string& FORCESTART)
{
    _setConsole();
    std::cout << " ___________________________ \n";
    std::cout << "|----------PATCHES----------|\n";
    std::cout << "|[1] FPS:           => [" << FPS << "] |\n";
    std::cout << "|[2] PERFECT SHOT:  => [" << PERFECTSHOT << "]  |\n";
    std::cout << "|[9] FORCE START:   => [" << FORCESTART << "]  |\n";
    std::cout << "|[-] MAIN MENU              |\n";
    std::cout << "|[END] QUIT                 |\n";
    std::cout << "|------COMBINED ASSAULT-----|" << std::endl;
}
#pragma endregion

//2
#pragma region //Call of Duty Series
void selectCODwaw()
{
    _clearConsole();
    _artCODwaw();
    Sleep(2050);
}

void _artCODwaw()
{
    _clearConsole();
    std::cout << R"(
   ____      _ _          __   ____        _                    
  / ___|__ _| | |   ___  / _| |  _ \ _   _| |_ _   _ _          
 | |   / _` | | |  / _ \| |_  | | | | | | | __| | | (_)         
 | |__| (_| | | | | (_) |  _| | |_| | |_| | |_| |_| |_          
 _\____\__,_|_|_|  \___/|_| _ |____/ \__,_|\__|\__, (_)         
 \ \      / /__  _ __| | __| |   __ _| |_  \ \ |___// /_ _ _ __ 
  \ \ /\ / / _ \| '__| |/ _` |  / _` | __|  \ \ /\ / / _` | '__|
   \ V  V / (_) | |  | | (_| | | (_| | |_    \ V  V / (_| | |   
    \_/\_/ \___/|_|  |_|\__,_|  \__,_|\__|    \_/\_/ \__,_|_|   
                                                                
)" << std::endl;
}

void MENU_CODwaw(string& HEALTH, string& AMMO, string& rFIRE, string& FLY, string& LASER, string& PROMOD, string& FPS, string& xCENTx, string& POINTS)
{
    _setConsole();
    std::cout << " ______________________________ \n";
    std::cout << "|--Call of Duty: World at War--|\n";
    std::cout << "|[1] INF HEALTH        => [" << HEALTH << "]  |\n";
    std::cout << "|[2] INF AMMO          => [" << AMMO << "]  |\n";
    std::cout << "|[3] RAPID FIRE        => [" << rFIRE << "]  |\n";
    std::cout << "|[4] NO CLIP           => [" << FLY << "]  |\n";
    std::cout << "|[5] GUN LASER         => [" << LASER << "]  |\n";
    std::cout << "|[6] PRO MOD           => [" << PROMOD << "]  |\n";
    std::cout << "|[7] DRAW FPS          => [" << FPS << "]  |\n";
    std::cout << "|[8] xCENTx MOD        => [" << xCENTx << "]  |\n";
    std::cout << "|[9] GIVE MAX POINTS   => [" << POINTS << "]  |\n";
    std::cout << "|[END] QUIT                    |\n";
    std::cout << "|______________________________|" << std::endl;
}
#pragma endregion

//3
#pragma region  //FAR CRY 3
void select_FC3()
{
    _clearConsole();
    _artFC3();
    Sleep(2050);
}

void _artFC3()
{
    _clearConsole();
    std::cout << R"(
  .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-.
01010\1010101\0101010\1010101\0101010\1010101\0101010\1010101\0101010\1010101\01  
:########::::'###::::'########::::::'######::'########::'##:::'##:::::'#######::
:##.....::::'## ##::: ##.... ##::::'##... ##: ##.... ##:. ##:'##:::::'##.... ##:
:##::::::::'##:. ##:: ##:::: ##:::: ##:::..:: ##:::: ##::. ####::::::..::::: ##:
:######:::'##:::. ##: ########::::: ##::::::: ########::::. ##::::::::'#######::
:##...:::: #########: ##.. ##:::::: ##::::::: ##.. ##:::::: ##::::::::...... ##:
:##::::::: ##.... ##: ##::. ##::::: ##::: ##: ##::. ##::::: ##:::::::'##:::: ##:
:##::::::: ##:::: ##: ##:::. ##::::. ######:: ##:::. ##:::: ##:::::::. #######::
10101\0101010\1010101\0101010\1010101\0101010\1010101\0101010\1010101\0101010\10
-'    `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-
)" << std::endl;
}

void MENU_FARCRY_3(string& money, string& ammo)
{
    _setConsole();
    std::cout << " ___________________________ " << std::endl;
    std::cout << "|----------PATCHES----------|" << std::endl;
    std::cout << "|[1] SEND $500      => [" << money << "]  |" << std::endl;
    std::cout << "|[2] INFINITE AMMO  => [" << ammo << "]  |" << std::endl;
    std::cout << "|[-] MAIN MENU              |" << std::endl;
    std::cout << "|[END] QUIT                 |" << std::endl;
    std::cout << "|-----FAR CRY 3----xCENTx---| v1.1" << std::endl;
}
#pragma endregion

//4
#pragma region //BINDING OF ISAAC
void select_ISAAC()
{
    _clearConsole();
    _artISAAC();
    Sleep(2050);
}

void _artISAAC()
{
    _clearConsole();
    std::cout << R"(
  _____ _            ____  _           _ _                      __   ___                      
 |_   _| |__   ___  | __ )(_)_ __   __| (_)_ __   __ _    ___  / _| |_ _|___  __ _  __ _  ___ 
   | | | '_ \ / _ \ |  _ \| | '_ \ / _` | | '_ \ / _` |  / _ \| |_   | |/ __|/ _` |/ _` |/ __|
   | | | | | |  __/ | |_) | | | | | (_| | | | | | (_| | | (_) |  _|  | |\__ \ (_| | (_| | (__ 
   |_| |_| |_|\___| |____/|_|_| |_|\__,_|_|_| |_|\__, |  \___/|_|   |___|___/\__,_|\__,_|\___|
                                                 |___/                                                                                                                  
)" << std::endl;
}

void MENU_ISAAC(string& HEALTH, string& BOMBS, string& DAMAGE, string& FIRERATE, string& COINS)
{
    _setConsole();
    std::cout << " ____________________________ " << std::endl;
    std::cout << "|----------PATCHES-----------|" << std::endl;
    std::cout << "|[1] INFINITE HEALTH  => [" << HEALTH << "] |" << std::endl;
    std::cout << "|[2] INFINITE BOMBS   => [" << BOMBS << "] |" << std::endl;
    std::cout << "|[3] MAX DAMAGE       => [" << DAMAGE << "] |" << std::endl;
    std::cout << "|[4] MAX FIRE RATE    => [" << FIRERATE << "] |" << std::endl;
    std::cout << "|[5] INFINITE COINS   => [" << COINS << "] |" << std::endl;
    std::cout << "|[-] MAIN MENU               |" << std::endl;
    std::cout << "|[END] QUIT                  |" << std::endl;
    std::cout << "|--Binding-of-Isaac--xCENTx--| v1.0" << std::endl;
}
#pragma endregion

//5
#pragma region  //FINAL FANTASY 7
void select_FF7()
{
    _clearConsole();
    _artFF7();
    Sleep(2050);
}

void _artFF7()
{
    _clearConsole();
    std::cout << R"(
    ___________   _____    __       _________    _   ___________   _______  __   _____
   / ____/  _/ | / /   |  / /      / ____/   |  / | / /_  __/   | / ___/\ \/ /  /__  /
  / /_   / //  |/ / /| | / /      / /_  / /| | /  |/ / / / / /| | \__ \  \  /     / / 
 / __/ _/ // /|  / ___ |/ /___   / __/ / ___ |/ /|  / / / / ___ |___/ /  / /     / /  
/_/   /___/_/ |_/_/  |_/_____/  /_/   /_/  |_/_/ |_/ /_/ /_/  |_/____/  /_/     /_/   
                                                                                                                                                               
)" << std::endl;
}

void MENU_FF7(string& HP, string& MP, string& GIL)
{
    _setConsole();
    std::cout << " ___________________________ " << std::endl;
    std::cout << "|----------PATCHES----------|" << std::endl;
    std::cout << "|[1] INFINITE HP     => [" << HP << "] |" << std::endl;
    std::cout << "|[2] INFINITE MP     => [" << MP << "] |" << std::endl;
    std::cout << "|[3] ADD 20,000 GIL  => [" << GIL << "] |" << std::endl;
    std::cout << "|[-] MAIN MENU              |" << std::endl;
    std::cout << "|[END] QUIT                 |" << std::endl;
    std::cout << "|--Final-Fantasy-7---xCENTx-| v1.0" << std::endl;
}
#pragma endregion

//6
#pragma region  //ASSAULT CUBE
void select_ASSAULT_CUBE()
{
    _clearConsole();
    _artASSAULTCUBE();
    Sleep(2050);
}

void _artASSAULTCUBE()
{
    _clearConsole();
    std::cout << R"(
   _                       _ _       ___      _          
  /_\  ___ ___  __ _ _   _| | |_    / __\   _| |__   ___ 
 //_\\/ __/ __|/ _` | | | | | __|  / / | | | | '_ \ / _ \
/  _  \__ \__ \ (_| | |_| | | |_  / /__| |_| | |_) |  __/
\_/ \_/___/___/\__,_|\__,_|_|\__| \____/\__,_|_.__/ \___|
                                                         
)" << std::endl;
}

void MENU_ASSAULT_CUBE(string& HEALTH, string& AMMO, string& RECOIL, string& NOCLIP)
{
    _setConsole();
    std::cout << " ___________________________ " << std::endl;
    std::cout << "|----------PATCHES----------|" << std::endl;
    std::cout << "|[1] INFINITE HEALTH => [" << HEALTH << "] |" << std::endl;
    std::cout << "|[2] INFINITE AMMO   => [" << AMMO << "] |" << std::endl;
    std::cout << "|[3] NO RECOIL       => [" << RECOIL << "] |" << std::endl;
    std::cout << "|[4] NO CLIP         => [" << NOCLIP << "] |" << std::endl;
    std::cout << "|[-] MAIN MENU              |" << std::endl;
    std::cout << "|[END] QUIT                 |" << std::endl;
    std::cout << "|----Assault--Cube--xCENTx--| v1.0" << std::endl;
}
#pragma endregion

//7
#pragma region  //

#pragma endregion

//8
#pragma region  //

#pragma endregion

//9
#pragma region  //

#pragma endregion

///////////////////|
#pragma region  //DEATHLY STILLNESS
void select_DEATHLY_STILLNESS()
{
    _clearConsole();
    _artDEATHLYSTILLNESS();
    Sleep(2050);
}

void _artDEATHLYSTILLNESS()
{
    _clearConsole();
    std::cout << R"(
  ___  ___   _ _____ _  _ _ __   __  ___ _____ ___ _    _    _  _ ___ ___ ___ 
 |   \| __| /_\_   _| || | |\ \ / / / __|_   _|_ _| |  | |  | \| | __/ __/ __|
 | |) | _| / _ \| | | __ | |_\ V /  \__ \ | |  | || |__| |__| .` | _|\__ \__ \
 |___/|___/_/ \_\_| |_||_|____|_|   |___/ |_| |___|____|____|_|\_|___|___/___/
                                                                              
)" << std::endl;
}

void MENU_DEATHLY_STILLNESS(string& ammo, string& yPOS)
{
    _setConsole();
    std::cout << " ___________________________ " << std::endl;
    std::cout << "|----------PATCHES----------|" << std::endl;
    std::cout << "|[1] INFINITE AMMO  => [" << ammo << "]  |" << std::endl;
    std::cout << "|[2] FREEZE Y POS   => [" << yPOS << "]  |" << std::endl;
    std::cout << "|[SPACE] FLY UP             |" << std::endl;
    std::cout << "|[LCTRL] FLY DOWN           |" << std::endl;
    std::cout << "|[-] MAIN MENU              |" << std::endl;
    std::cout << "|[END] QUIT                 |" << std::endl;
    std::cout << "|--Deathly-Stillness-xCENTx-| v1.0" << std::endl;
    std::cout << R"(
IMPORTANT NOTE:
Trainer options currently only work with AKM(Hard) on Village (Hard)
)" << std::endl;

    std::cout << R"(
NOT IMPLEMENTED QUITE YET , IM GLAD YOU ARE INTERESTED IN THIS OPTION
Stay Tuned For Updates !!

P.S , If you are seeing this message , be sure to shoot me a PM and tell me how much you want this added
)" << std::endl;
}
#pragma endregion

#pragma region //OLD METHODS
void _ReturnToMainMenu(bool& currentMENU, bool& currentGAME, bool& mainMENU)
{
    currentMENU = false;
    currentGAME = false;
    _clearConsole();
    std::cout << "RETURNING TO MENU . . ." << std::endl;
    Sleep(2050);
    _clearConsole();
    mainMENU = true;
}

//TOGGLES
void select_CA(bool& MENU, bool& TITLE_MENU, bool& gameMENU)
{
    MENU = false;      // We don't want to display main menu anymore or trigger any of its functions
    TITLE_MENU = false;  // We don't want key input from our selected menu to toggle MAIN MENU options
    _clearConsole();    // Clear the menu

    //Display some cool ascii art cause why not
    _artCA();
    Sleep(2050);    // Weve worked pretty hard to get this far , lets take a coffee break
    _clearConsole();    // Clear the console
    gameMENU = true;    // Display Combined Assault Menu
}

#pragma endregion