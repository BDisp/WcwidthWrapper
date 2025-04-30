#include "pch.h"

#include "WcwidthWrapper.h"

// Bring the C# namespace into scope—replace with the real one
using namespace Wcwidth;

// Managed implementations—no dllexport
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
