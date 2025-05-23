#include "pch.h"

#include "WcwidthWrapper.h"

// Bring the C# namespace into scopeóreplace with the real one
using namespace Wcwidth;

// Managed implementationsóno dllexport
int WcwidthWrapper::GetWidth(int value, Nullable<Wcwidth::Unicode> version)
{
	return Wcwidth::UnicodeCalculator::GetWidth(value, version);
}

int WcwidthWrapper::GetWidth(Rune value, Nullable<Wcwidth::Unicode> version)
{
	return Wcwidth::UnicodeCalculator::GetWidth(value, version);
}

int WcwidthWrapper::GetWidth(char value, Nullable<Wcwidth::Unicode> version)
{
	return Wcwidth::UnicodeCalculator::GetWidth(static_cast<int>(value), version);
}
