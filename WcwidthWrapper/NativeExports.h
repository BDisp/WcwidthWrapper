// NativeExports.h
#pragma once

#include <vector>

__declspec(dllexport) int GetWidth(int codePoint, int version = -1);
__declspec(dllexport) int GetWidth(wchar_t ch, int version = -1);
__declspec(dllexport) int GetWidth(const char* utf8, int version = -1);
__declspec(dllexport) int GetWidth(uint32_t codePoint, int version = -1);
