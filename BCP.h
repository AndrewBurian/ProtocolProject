/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: BCP.h - 	header file for the Protocol Project
--
-- PROGRAM:		BCP
--
-- FUNCTIONS:
-- none
--
-- DATE: 		October 23, 2013
--
-- REVISIONS: 	none
--
-- DESIGNER: 	Andrew Burian
--
-- PROGRAMMER: 	Andrew Burian
--
-- NOTES:
-- 
----------------------------------------------------------------------------------------------------------------------*/

// includes
// ----------------------------------------------------------------------------
using namespace std;
#include <Windows.h>
#include <Windowsx.h>
#include <queue>

// Definitions
// ----------------------------------------------------------------------------
#define TIMEOUT 200
#define SEND_LIMIT 5

#define ACK 0x06
#define NAK 0x15
#define EOT 0x04
#define ENQ 0x05
#define SYN 0x16
#define DC1 0x11
#define DC2 0x12


// Function Declarations
// ----------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

DWORD WINAPI FileBufferThread(LPVOID threadParams);
DWORD WINAPI SerialReadThread(LPVOID threadParams);
DWORD WINAPI FileWriterThread(LPVOID threadParams);
DWORD WINAPI ProtocolControlThread(LPVOID threadParams);

//Output
BOOL SendNext();
BOOL Resend();
BOOL SendACK();
BOOL SendNAK();
BOOL SendEOT();
BOOL SendENQ();

//CRC
BOOL MakeCRC(byte* input, byte* crc);
BOOL CheckCRC(byte* input, byte* crc);

// Global Stores
// ----------------------------------------------------------------------------
extern queue<byte> quOutputQueue;		// Queue for bytes to be sent
extern queue<byte> quInputQueue;		// Queue for bytes received waiting to be written to file


// Global events
// ----------------------------------------------------------------------------
#define EVENT_ACK TEXT("BCP_ACK")
#define EVENT_NAK TEXT("BCP_NAK")
#define EVENT_ENQ TEXT("BCP_ENQ")
#define EVENT_EOT TEXT("BCP_EOT")
#define EVENT_DATA_RECEIVED TEXT("BCP_DATA_RECEIVED")
#define EVENT_BAD_DATA_RECEIVED TEXT("BCP_BAD_DATA_RECEIVED")
#define EVENT_END_PROGRAM TEXT("BCP_END_OF_PROGRAM")
#define EVENT_OUTPUT_AVAILABLE TEXT("BCP_OUTPUT_AVAILABLE")
#define EVENT_INPUT_AVAILABLE TEXT("BCP_INPUT_AVAILBLE")

// Global Comm Port Object and utils
// ----------------------------------------------------------------------------
extern HANDLE hCommPort;			// The IO port used for the medium
extern OVERLAPPED ovrReadPort;		// Overlapped Structure for reading to the comm port
extern OVERLAPPED ovrWritePort;
extern HANDLE hReadComplete;
extern HANDLE hWriteComplete;

// Global Sycronization objects
// ----------------------------------------------------------------------------
#define MUTEX_IO_PORT TEXT("BCP_IO_CONTROL")


// Global Flags
// ----------------------------------------------------------------------------
extern BOOL bProgramDone;

// GUI functionallity
// ----------------------------------------------------------------------------
struct GUIDATA{
	HWND pcktStat_Sent;
	HWND pcktStat_Received;
	HWND pcktStat_Lost;
};

VOID SetupGUI(GUIDATA* data);
VOID GUI_Sent();
VOID GUI_Received();
VOID GUI_Lost();
