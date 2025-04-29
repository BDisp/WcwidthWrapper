#pragma once

// Include necessary .NET namespaces
using namespace System;
using namespace System::Text;
using namespace Wcwidth;

// Declare the wrapper class
public ref class WcwidthWrapper
{
public:
	/// <summary>
	/// Gets the width of a Unicode code point.
	/// </summary>
	/// <param name="value">The Unicode code point to calculate the width of.</param>
	/// <param name="version">The Unicode version to use.</param>
	/// <returns>The width of the character (-1, 0, 1, 2).</returns>
	static int GetWidth(int value, Nullable<Wcwidth::Unicode> version);

	/// <summary>
	/// Gets the width of a Unicode scalar.
	/// </summary>
	/// <param name="value">The Unicode scalar to calculate the width of.</param>
	/// <param name="version">The Unicode version to use.</param>
	/// <returns>The width of the character (-1, 0, 1, 2).</returns>
	static int GetWidth(Rune value, Nullable<Wcwidth::Unicode> version);

	/// <summary>
	/// Gets the width of a UTF-16 code unit.
	/// </summary>
	/// <param name="value">The UTF-16 code unit to calculate the width of.</param>
	/// <param name="version">The Unicode version to use.</param>
	/// <returns>The width of the character (-1, 0, 1, 2).</returns>
	static int GetWidth(char value, Nullable<Wcwidth::Unicode> version);
};
