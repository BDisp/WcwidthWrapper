// NativeExports.cpp
#include "pch.h"

#include "NativeExports.h"
#include "WcwidthWrapper.h"
#include <string>

Nullable<Wcwidth::Unicode> GetVersion(int version) {
    return (version < 0)
        ? Nullable<Wcwidth::Unicode>() // null  
        : Nullable<Wcwidth::Unicode>(
            static_cast<Wcwidth::Unicode>(version));
}

// Overload implementations:
int GetWidth(int codePoint, int version)
{
    // Calls managed wrapper
	return WcwidthWrapper::GetWidth(codePoint, GetVersion(version));
}

int GetWidth(wchar_t ch, int version)
{
    return WcwidthWrapper::GetWidth(ch, GetVersion(version));
}

int GetWidth(const char* utf8, int version)
{
    if (utf8 == nullptr)
        return -1; // Handle null input appropriately

    // Convert const char* to std::string
    std::string utf8Str(utf8);

    // Convert std::string to System::String^ using UTF8 encoding
    array<Byte>^ utf8Bytes = gcnew array<Byte>(static_cast<int>(utf8Str.length()));
    for (int i = 0; i < utf8Bytes->Length; ++i)
        utf8Bytes[i] = static_cast<Byte>(utf8Str[i]);

    String^ managedStr = Encoding::UTF8->GetString(utf8Bytes);

    // Ensure the string is not empty
    if (String::IsNullOrEmpty(managedStr))
        return -1; // Handle empty string appropriately

    // Use enumerator to get the first Rune
    Rune rune;
    auto enumerator = managedStr->EnumerateRunes().GetEnumerator();
    if (enumerator.MoveNext())
    {
        rune = enumerator.Current;
    }
    else
    {
        return -1; // Handle case where no runes are found
    }

    // Call the managed GetWidth method
    return WcwidthWrapper::GetWidth(rune, GetVersion(version));
}

int GetWidth(uint32_t codePoint, int version)
{
	// Calls managed wrapper
    return WcwidthWrapper::GetWidth(static_cast<int>(codePoint), GetVersion(version));
}