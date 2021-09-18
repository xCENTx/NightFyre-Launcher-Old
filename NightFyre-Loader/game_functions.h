#pragma once
#include "stdafx.h"

namespace FF7
{
	void battleHP(HANDLE& PROCESS, uintptr_t& currentHP1, uintptr_t& currentHP2, uintptr_t& currentHP3,
		int& HP1, int& HP2, int& HP3, int& MAX1, int& MAX2, int& MAX3);
	void battleMP(HANDLE& PROCESS, uintptr_t& cMP1addr, uintptr_t& cMP2addr, uintptr_t& cMP3addr,
		byte& MP1, byte& MP2, byte& MP3, byte& maxMP1, byte& maxMP2, byte& maxMP3);
}