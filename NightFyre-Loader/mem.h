#pragma once
#include "stdafx.h"
///Credit: GuidedHacking
// Check out the website and youtube channel
//GHB1 Tutorials 11 - 16

namespace mem
{
	void PatchEx(BYTE* dst, BYTE* src, unsigned int size, HANDLE hProcess);
	void NopEx(BYTE* dst, unsigned int size, HANDLE hProcess);
	void PS2NopEx(BYTE* dst, unsigned int size, HANDLE hProcess);
}