#include "BCP.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message,
	WPARAM wParam, LPARAM lParam)
{
	HWND edit;
	switch (Message)
	{
	case WM_CREATE:
		edit = CreateWindow(TEXT("EDIT"), 
			NULL, 
			WS_CHILD | ES_MULTILINE ,//| ES_READONLY ,
			10, 10, 200, 100, 
			hwnd, (HMENU)1, NULL, NULL);
		ShowWindow(edit, SW_SHOW);
		Edit_SetText(edit, (TCHAR*)TEXT("HELLO WORLD!"));
		break;
	case WM_DESTROY:		// message to terminate the program
		PostQuitMessage(0);
		break;

	default: // Let Win32 process all other messages
		return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}