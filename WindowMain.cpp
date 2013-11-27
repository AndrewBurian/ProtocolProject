/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: WindowMain.cpp		Responsible for setting up the program and initializing
--									any global variables.
--
-- PROGRAM:		BCP
--
-- FUNCTIONS:
--	int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hprevInstance,	LPSTR lspszCmdParam, int nCmdShow)
--
-- DATE: 		October 23, 2013
--
-- REVISIONS: 	None
--
-- DESIGNER: 	Andrew Burian
--
-- PROGRAMMER: 	
--
-- NOTES:
-- 
----------------------------------------------------------------------------------------------------------------------*/

#include "BCP.h"

HANDLE hCommPort;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hprevInstance,
	LPSTR lspszCmdParam, int nCmdShow)
{
	HWND hwnd;
	MSG Msg;
	WNDCLASSEX Wcl;

	static TCHAR Name[] = TEXT("BeCreativeProtocol");
	static TCHAR Title[] = TEXT("(BЗ CЯЗATIVЗ) Protocol Engine");

	// Define a Window class
	Wcl.cbSize = sizeof (WNDCLASSEX);
	Wcl.style = 0; // default style
	Wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);			// large icon 
	Wcl.hIconSm = NULL;										// use small version of large icon
	Wcl.hCursor = LoadCursor(NULL, IDC_ARROW);				// cursor style

	Wcl.lpfnWndProc = WndProc;								// window function
	Wcl.hInstance = hInst;									// handle to this instance
	Wcl.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));// background
	Wcl.lpszClassName = Name;								// window class name

	Wcl.lpszMenuName = NULL;								// no class menu 
	Wcl.cbClsExtra = 0;										// no extra memory needed
	Wcl.cbWndExtra = 0;

	// Register the class
	if (!RegisterClassEx(&Wcl))
		return 0;

	hwnd = CreateWindow(
		Name,					// name of window class
		Title,					// title 
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

	// Initialize Globals
	// -----------------------------------------------------------------------

	BOOL bProgramDone = FALSE;
	/*HANDLE hAck = CreateEvent(NULL, FALSE, FALSE, TEXT("BCP_ACK"));
	HANDLE hNak = CreateEvent(NULL, FALSE, FALSE, TEXT("BCP_NAK"));
	HANDLE hEnq = CreateEvent(NULL, FALSE, FALSE, TEXT("BCP_ENQ"));
	HANDLE hEot = CreateEvent(NULL, FALSE, FALSE, TEXT("BCP_EOT"));
	HANDLE hDataReceived = CreateEvent(NULL, FALSE, FALSE, TEXT("BCP_DATA_RECEIVED"));
	HANDLE hBadDataReceived = CreateEvent(NULL, FALSE, FALSE, TEXT("BCP_BAD_DATA_RECEIVED"));
	HANDLE hInputAvailable = CreateEvent(NULL, FALSE, FALSE, TEXT("BCP_INPUT_AVAILABLE"));
	HANDLE hOutputAVailable = CreateEvent(NULL, FALSE, FALSE, TEXT("BCP_OUTPUT_AVAILABLE"));
	HANDLE hEndProgram = CreateEvent(NULL, TRUE, FALSE, TEXT("BCP_END_OF_PROGRAM"));*/
	HANDLE hReadComplete = CreateEvent(NULL, TRUE, FALSE, TEXT("BCP_READ_COMPLETE"));
	HANDLE hWriteComplete = CreateEvent(NULL, TRUE, FALSE, TEXT("BCP_WRITE_COMPLETE"));


	ovrWritePort.hEvent = hWriteComplete;
	ovrReadPort.hEvent = hReadComplete;

	// -----------------------------------------------------------------------

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