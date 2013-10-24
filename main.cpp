/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: source.c - 	a program that does stuff
--
-- PROGRAM: 
--
-- FUNCTIONS:
-- int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hprevInstance,	LPSTR lspszCmdParam, int nCmdShow)
--
-- DATE: 		October 23, 2013
--
-- REVISIONS: 	None
--
-- DESIGNER: 	Andrew Burian
--
-- PROGRAMMER: 	Andrew Burian
--
-- NOTES:
-- Notes Section
----------------------------------------------------------------------------------------------------------------------*/

#include "ProtocolX.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hprevInstance,
	LPSTR lspszCmdParam, int nCmdShow)
{
	HWND hwnd;
	MSG Msg;
	WNDCLASSEX Wcl;

	static TCHAR Name[] = TEXT("Hello Win!");

	// Define a Window class
	Wcl.cbSize = sizeof (WNDCLASSEX);
	Wcl.style = 0; // default style
	Wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);			// large icon 
	Wcl.hIconSm = NULL;										// use small version of large icon
	Wcl.hCursor = LoadCursor(NULL, IDC_ARROW);				// cursor style

	Wcl.lpfnWndProc = WndProc;								// window function
	Wcl.hInstance = hInst;									// handle to this instance
	Wcl.hbrBackground = CreateSolidBrush(RGB(255, 0, 0));	// background
	Wcl.lpszClassName = Name;								// window class name

	Wcl.lpszMenuName = NULL;								// no class menu 
	Wcl.cbClsExtra = 0;										// no extra memory needed
	Wcl.cbWndExtra = 0;

	// Register the class
	if (!RegisterClassEx(&Wcl))
		return 0;

	hwnd = CreateWindow(
		Name,					// name of window class
		Name,					// title 
		WS_OVERLAPPEDWINDOW,	// window style - normal
		CW_USEDEFAULT,			// X coord
		CW_USEDEFAULT,			// Y coord
		CW_USEDEFAULT,			// width
		CW_USEDEFAULT,			// height
		NULL,					// no parent window
		NULL,					// no menu
		hInst,					// instance handle
		NULL					// no additional arguments
		);

	// Display the window
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// Create the message loop
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);		// translate keybpard messages
		DispatchMessage(&Msg);		// dispatch message and return control to windows
	}

	return Msg.wParam;
}