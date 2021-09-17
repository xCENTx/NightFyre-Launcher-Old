#pragma once
#include "stdafx.h"

namespace waw
{
	void HEALTH(bool& HACK, uintptr_t& address, HANDLE& process, string& STRING, bool& menu);

	void AMMO(bool& HACK, uintptr_t& address, HANDLE& process, string& STRING, bool& menu);

	void RAPIDFIRE(bool& HACK, uintptr_t& address, HANDLE& process, string& STRING, bool& menu);

	void BOOL(bool& HACK, uintptr_t& address, HANDLE& process, string& STRING, bool& menu);

	void FPS(bool& HACK, uintptr_t& address, HANDLE& process, string& STRING, bool& menu);

	void POINTS(uintptr_t& address, HANDLE& process, string& STRING, bool& menu);

	void PROMOD(bool& HACK, uintptr_t& address, uintptr_t& address2, uintptr_t& address3,
		HANDLE& process, string& STRING, bool& menu);

	void CENTHACK(bool& HACK, uintptr_t& address, uintptr_t& address2, uintptr_t& address3,
		uintptr_t& address4, uintptr_t& address5, uintptr_t& address6, uintptr_t& address7, 
		uintptr_t& address8, HANDLE& process, string& STRING, bool& menu);
}