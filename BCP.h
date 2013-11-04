/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: BCP.h - 	header file for the Protocol Project
--
-- PROGRAM: 
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
-- Notes Section
----------------------------------------------------------------------------------------------------------------------*/

// includes
// ----------------------------------------------------------------------------
using namespace std;
#include <Windows.h>
#include <queue>

// Definitions
// ----------------------------------------------------------------------------
#define TIMEOUT 200
#define SEND_LIMIT 5

#define ACK 0x
#define NAK 0x
#define EOT 0x
#define ENQ 0x
#define SYN 0x
#define DC1 0x12
#define DC2 0x13


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

// Global Stores
// ----------------------------------------------------------------------------
queue<byte> quOutputCue;	// Cue for bytes to be sent
queue<byte> quInputCue;		// Cue for bytes recieved waiting to be written to file


// Global events
// ----------------------------------------------------------------------------
HANDLE hAck				= CreateEvent(NULL, FALSE, FALSE, TEXT("BCP_ACK"));
HANDLE hNak				= CreateEvent(NULL, FALSE, FALSE, TEXT("BCP_NAK"));
HANDLE hEnq				= CreateEvent(NULL, FALSE, FALSE, TEXT("BCP_ENQ"));
HANDLE hEot				= CreateEvent(NULL, FALSE, FALSE, TEXT("BCP_EOT"));
HANDLE hInputAvailable	= CreateEvent(NULL, FALSE, FALSE, TEXT("BCP_INPUT_AVAILABLE"));
HANDLE hOutputAVailable	= CreateEvent(NULL, FALSE, FALSE, TEXT("BCP_OUTPUT_AVAILABLE"));
HANDLE hEndProgram		= CreateEvent(NULL, TRUE,  FALSE, TEXT("BCP_END_OF_PROGRAM"));


// Global Sycronization objects
// ----------------------------------------------------------------------------
HANDLE hDatalinkControl		= CreateMutex(NULL, FALSE, TEXT("BCP_LINK_OWNERSHIP"));
HANDLE hOutputBufferControl = CreateMutex(NULL, FALSE, TEXT("BCP_OUTPUT_OWNERSHIP"));


// Global Thread Handles
// ----------------------------------------------------------------------------
HANDLE hFileLoaderThread;
HANDLE hInputReaderThread;

// Global Flags
// ----------------------------------------------------------------------------
BOOL bProgramDone = FALSE;