#include "BCP.h"

GUIDATA* dat = NULL;
int sent = 0, received = 0, lost = 0;

VOID SetupGUI(GUIDATA* data)
{
	dat = data;
	ShowWindow(dat->pcktStat_Sent, SW_SHOW);
	ShowWindow(dat->pcktStat_Received, SW_SHOW);
	ShowWindow(dat->pcktStat_Lost, SW_SHOW);

	LPWSTR buf[10];
	wsprintf(buf[0], TEXT("%d"), 10);
	//Edit_SetText(dat->pcktStat_Sent, buf[0]);//(TCHAR*)TEXT("0"));

	//Edit_SetText(dat->pcktStat_Sent, (TCHAR*)TEXT("10"));
	//UpdateWindow(dat->pcktStat_Sent);
}

VOID update()
{

}

VOID GUI_Sent()
{
	++sent;
	update();
}

VOID GUI_Received()
{
	++received;
	update();
}

VOID GUI_Lost()
{
	++lost;
	update();
}