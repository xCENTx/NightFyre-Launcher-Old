#include "stdafx.h"

//PATCHES
void waw::HEALTH(bool& HACK, uintptr_t& address, HANDLE& process, string& STRING, bool& menu)
{
	HACK = !HACK;
	if (HACK)
	{
		mem::NopEx((BYTE*)address, 6, process);
		STRING = "X";
		menu = false;
	}
	else
	{
		mem::PatchEx((BYTE*)address, (BYTE*)"\x89\x96\xC8\x01\x00\x00", 6, process);
		STRING = " ";
		menu = false;
	}
}

void waw::AMMO(bool& HACK, uintptr_t& address, HANDLE& process, string& STRING, bool& menu)
{
	HACK = !HACK;
	if (HACK)
	{
		mem::NopEx((BYTE*)address, 7, process);
		STRING = "X";
		menu = false;
	}
	else
	{
		mem::PatchEx((BYTE*)address, (BYTE*)"\x89\x84\x8F\xFC\x05\x00\x00", 7, process);
		STRING = " ";
		menu = false;
	}
}

void waw::RAPIDFIRE(bool& HACK, uintptr_t& address, HANDLE& process, string& STRING, bool& menu)
{
	HACK = !HACK;
	if (HACK)
	{
		mem::NopEx((BYTE*)address, 5, process);
		STRING = "X";
		menu = false;
	}
	else
	{
		mem::PatchEx((BYTE*)address, (BYTE*)"\xE8\x10\xFA\xFF\xFF", 5, process);
		STRING = " ";
		menu = false;
	}
}

void waw::BOOL(bool& HACK, uintptr_t& address, HANDLE& process, string& STRING, bool& menu)
{
	HACK = !HACK;
	if (HACK)
	{
		mem::PatchEx((BYTE*)address, (BYTE*)"\x01", 1, process);
		STRING = "X";
		menu = false;
	}
	else
	{
		mem::PatchEx((BYTE*)address, (BYTE*)"\x00", 1, process);
		STRING = " ";
		menu = false;
	}
}

void waw::FPS(bool& HACK, uintptr_t& address, HANDLE& process, string& STRING, bool& menu)
{
	HACK = !HACK;
	if (HACK)
	{
		mem::PatchEx((BYTE*)address, (BYTE*)"\x02", 1, process);
		STRING = "X";
		menu = false;
	}
	else
	{
		mem::PatchEx((BYTE*)address, (BYTE*)"\x00", 1, process);
		STRING = " ";
		menu = false;
	}
}

void waw::POINTS(uintptr_t& address, HANDLE& process, string& STRING, bool& menu)
{
	mem::PatchEx((BYTE*)address, (BYTE*)"\x3F\x42\0F\x00", 4, process);
	std::cout << "SENT POINTS" << std::endl;
	Sleep(2000);
	menu = false;
}

void waw::PROMOD(bool& HACK, uintptr_t& address, uintptr_t& address2, uintptr_t& address3, HANDLE& process, string& STRING, bool& menu)
{
	HACK = !HACK;
	if (HACK)
	{
		mem::PatchEx((BYTE*)address, (BYTE*)"\x01", 1, process);
		mem::PatchEx((BYTE*)address2, (BYTE*)"\x00\x00\xB4\x42", 4, process);
		mem::PatchEx((BYTE*)address3, (BYTE*)"\x01", 1, process);
		STRING = "X";
		menu = false;
	}
	else
	{
		mem::PatchEx((BYTE*)address, (BYTE*)"\x00", 1, process);
		mem::PatchEx((BYTE*)address2, (BYTE*)"\x00\x00\x82\x42", 4, process);
		mem::PatchEx((BYTE*)address3, (BYTE*)"\x00", 1, process);
		STRING = " ";
		menu = false;
	}
}

void waw::CENTHACK(bool& HACK, uintptr_t& address, uintptr_t& address2, uintptr_t& address3, uintptr_t& address4, uintptr_t& address5, uintptr_t& address6, uintptr_t& address7, uintptr_t& address8, HANDLE& process, string& STRING, bool& menu)
{
	HACK = !HACK;
	if (HACK)
	{
		mem::NopEx((BYTE*)address, 6, process);
		mem::NopEx((BYTE*)address2, 7, process);
		mem::NopEx((BYTE*)address3, 5, process);
		mem::PatchEx((BYTE*)address4, (BYTE*)"\x01", 1, process);
		mem::PatchEx((BYTE*)address5, (BYTE*)"\x01", 1, process);
		mem::PatchEx((BYTE*)address6, (BYTE*)"\x00\x00\xB4\x42", 4, process);
		mem::PatchEx((BYTE*)address7, (BYTE*)"\x01", 1, process);
		mem::PatchEx((BYTE*)address8, (BYTE*)"\x02", 1, process);
		STRING = "X";
		menu = false;
	}
	else
	{
		mem::PatchEx((BYTE*)address, (BYTE*)"\x89\x96\xC8\x01\x00\x00", 6, process);
		mem::PatchEx((BYTE*)address2, (BYTE*)"\x89\x84\x8F\xFC\x05\x00\x00", 7, process);
		mem::PatchEx((BYTE*)address3, (BYTE*)"\xE8\x10\xFA\xFF\xFF", 5, process);
		mem::PatchEx((BYTE*)address4, (BYTE*)"\x00", 1, process);
		mem::PatchEx((BYTE*)address5, (BYTE*)"\x00", 1, process);
		mem::PatchEx((BYTE*)address6, (BYTE*)"\x00\x00\x82\x42", 4, process);
		mem::PatchEx((BYTE*)address7, (BYTE*)"\x00", 1, process);
		mem::PatchEx((BYTE*)address8, (BYTE*)"\x00", 1, process);
		STRING = " ";
		menu = false;
	}
}