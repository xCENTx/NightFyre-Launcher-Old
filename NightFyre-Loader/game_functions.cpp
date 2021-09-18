#include "stdafx.h"

void FF7::battleHP(HANDLE& PROCESS, uintptr_t& currentHP1, uintptr_t& currentHP2, uintptr_t& currentHP3, 
                    int& HP1, int& HP2, int& HP3, int& MAX1, int& MAX2, int& MAX3)
{
    ReadProcessMemory(PROCESS, (BYTE*)currentHP1, &HP1, sizeof(HP1), nullptr);
    ReadProcessMemory(PROCESS, (BYTE*)currentHP2, &HP2, sizeof(HP2), nullptr);
    ReadProcessMemory(PROCESS, (BYTE*)currentHP3, &HP3, sizeof(HP3), nullptr);
    if (HP1 != MAX1)
    {
        WriteProcessMemory(PROCESS, (BYTE*)currentHP1, &MAX1, sizeof(MAX1), nullptr);
    }
    if (HP2 != MAX2)
    {
        WriteProcessMemory(PROCESS, (BYTE*)currentHP2, &MAX2, sizeof(MAX2), nullptr);
    }
    //if (HP3 != MAX3)
    //{
    //    WriteProcessMemory(hProcess, (BYTE*)currentHP3, &MAX3, sizeof(MAX3), nullptr);
    //}
}

void FF7::battleMP(HANDLE& PROCESS, uintptr_t& cMP1addr, uintptr_t& cMP2addr, uintptr_t& cMP3addr,
    byte& MP1, byte& MP2, byte& MP3, byte& maxMP1, byte& maxMP2, byte& maxMP3)
{
    ReadProcessMemory(PROCESS, (BYTE*)cMP1addr, &MP1, sizeof(MP1), nullptr);
    ReadProcessMemory(PROCESS, (BYTE*)cMP2addr, &MP2, sizeof(MP2), nullptr);
    //ReadProcessMemory(hProcess, (BYTE*)currentMP3, &MP3, sizeof(MP3), nullptr);
    if (MP1 != maxMP1)
    {
        if (maxMP1 < 40)
        {
            maxMP1 = 40;
        }
        WriteProcessMemory(PROCESS, (BYTE*)cMP1addr, &maxMP1, sizeof(maxMP1), nullptr);
    }
    if (MP2 != maxMP2)
    {
        if (maxMP2 < 40)
        {
            maxMP2 = 40;
        }
        WriteProcessMemory(PROCESS, (BYTE*)cMP2addr, &maxMP2, sizeof(maxMP2), nullptr);
    }
    //if (MP3 != maxMP3)
    //{
    //    if (maxMP3 < 40)
    //    {
    //        maxMP3 = 40;
    //    }
    //    WriteProcessMemory(PROCESS, (BYTE*)currentMP3, &maxMP3, sizeof(maxMP3), nullptr);
    //}
}