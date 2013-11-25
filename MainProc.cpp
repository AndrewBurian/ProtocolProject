#include "BCP.h"
#include <string>


LRESULT CALLBACK WndProc(HWND hwnd, UINT Message,
	WPARAM wParam, LPARAM lParam)
{
	GUIDATA guidata;
	HDC hdc;
	switch (Message)
	{
	case WM_CREATE:
		/*edit = CreateWindow(TEXT("EDIT"), 
			NULL, 
			WS_CHILD | ES_MULTILINE ,//| ES_READONLY ,
			10, 10, 200, 100, 
			hwnd, (HMENU)1, NULL, NULL);
		ShowWindow(edit, SW_SHOW);
		Edit_SetText(edit, (TCHAR*)TEXT("HELLO WORLD!"));*/
		
		guidata.pcktStat_Sent = CreateWindow(TEXT("EDIT"),
			NULL,
			WS_CHILD | ES_READONLY,
			500, 350, 70, 20,
			hwnd, (HMENU)1, NULL, NULL);
		guidata.pcktStat_Received = CreateWindow(TEXT("EDIT"),
			NULL,
			WS_CHILD | ES_READONLY,
			500, 380, 70, 20,
			hwnd, (HMENU)1, NULL, NULL);
		guidata.pcktStat_Lost = CreateWindow(TEXT("EDIT"),
			NULL,
			WS_CHILD | ES_READONLY,
			500, 410, 70, 20,
			hwnd, (HMENU)1, NULL, NULL);

		SetupGUI(&guidata);
		Edit_SetText(guidata.pcktStat_Sent, (TCHAR*)TEXT("10"));

		break;
	case WM_PAINT:
		hdc = GetDC(hwnd);
		SelectObject(hdc, GetStockBrush(NULL_BRUSH));
		Rectangle(hdc, 400, 300, 750, 550);	// left, top, right, bottom
		TextOut(hdc, 410, 310, TEXT("Packet stats"), 12);
		TextOut(hdc, 410, 350, TEXT("Sent:"), 5);
		TextOut(hdc, 410, 380, TEXT("Received:"), 9);
		TextOut(hdc, 410, 410, TEXT("Lost:"), 5);
		
		ReleaseDC(hwnd, hdc);
		break;
	case WM_DESTROY:		// message to terminate the program
		PostQuitMessage(0);
		break;

	default: // Let Win32 process all other messages
		return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}