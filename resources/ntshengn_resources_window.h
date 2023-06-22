#pragma once

namespace NtshEngn {

	// Window
	typedef uint64_t WindowId;

	// Native window handle
	typedef void* NativeWindowHandle;
	typedef void* NativeWindowAdditionalInformation;

	// Input
	enum class InputState {
		None, // State when the input is neutral
		Pressed, // State on the frame an input is pressed
		Held, // State after an input is pressed and before it's released
		Released // State on the frame an input is released
	};

	enum class InputKeyboardKey {
		Any, // Any key
		A, // Letter A
		B, // Letter B
		C, // Letter C
		D, // Letter D
		E, // Letter E
		F, // Letter F
		G, // Letter G
		H, // Letter H
		I, // Letter I
		J, // Letter J
		K, // Letter K
		L, // Letter L
		M, // Letter M
		N, // Letter N
		O, // Letter O
		P, // Letter P
		Q, // Letter Q
		R, // Letter R
		S, // Letter S
		T, // Letter T
		U, // Letter U
		V, // Letter V
		W, // Letter W
		X, // Letter X
		Y, // Letter Y
		Z, // Letter Z
		Space, // Spacebar
		Shift, // Shift
		LeftCtrl, // Left Control
		RightCtrl, // Right Control
		Alt, // Alt
		Escape, // Escape
		Tab, // Tab
		Backspace, // Backspace
		Return, // Return
		Enter, // Enter
		Num0, // Numpad 0
		Num1, // Numpad 1
		Num2, // Numpad 2
		Num3, // Numpad 3
		Num4, // Numpad 4
		Num5, // Numpad 5
		Num6, // Numpad 6
		Num7, // Numpad 7
		Num8, // Numpad 8
		Num9, // Numpad 9
		NumPlus, // Numpad +
		NumMinus, // Numpad -
		NumTimes, // Numpad *
		NumDivision, // Numpad /
		Left, // Left Arrow
		Right, // Right Arrow
		Up, // Up Arrow
		Down, // Down Arrow
		F1, // F1
		F2, // F2
		F3, // F3
		F4, // F4
		F5, // F5
		F6, // F6
		F7, // F7
		F8, // F8
		F9, // F9
		F10, // F10
		F11, // F11
		F12 // F12
	};

	enum class InputMouseButton {
		Any, // Any mouse button
		One, // Left mouse button
		Two, // Right mouse button
		Three, // Middle mouse button
		Four, // Additional mouse button 4
		Five, // Additional mouse button 5
		Six, // Additional mouse button 6
		Seven, // Additional mouse button 7
		Eight // Additional mouse button 8
	};

}