/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: ProtocolX.h - 	header file for the Protocol Project
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


// Global Stores
// ----------------------------------------------------------------------------
queue<byte> outputCue;		// Cue for bytes to be sent
queue<byte> inputCue;		// Cue for bytes recieved waiting to be written to file


// Global events
// ----------------------------------------------------------------------------
HANDLE hAck				= CreateEvent(NULL, FALSE, FALSE, TEXT("PROTOCOLX_ACK"));
HANDLE hNak				= CreateEvent(NULL, FALSE, FALSE, TEXT("PROTOCOLX_NAK"));
HANDLE hEnq				= CreateEvent(NULL, FALSE, FALSE, TEXT("PROTOCOLX_ENQ"));
HANDLE hEot				= CreateEvent(NULL, FALSE, FALSE, TEXT("PROTOCOLX_EOT"));
HANDLE hInputAvailable	= CreateEvent(NULL, FALSE, FALSE, TEXT("PROTOCOLX_INPUT_AVAILABLE"));
HANDLE hOutputAVailable	= CreateEvent(NULL, FALSE, FALSE, TEXT("PROTOCOLX_OUTPUT_AVAILABLE"));
HANDLE hEndProgram		= CreateEvent(NULL, TRUE, FALSE, TEXT("PROTOCOLX_END_OF_PROGRAM"));


// Global Sycronization objects
// ----------------------------------------------------------------------------
HANDLE hDatalinkControl		= CreateMutex(NULL, FALSE, TEXT("PROTOCOLX_LINK_OWNERSHIP"));
HANDLE hOutputBufferControl = CreateMutex(NULL, FALSE, TEXT("PROTOCOLX_OUTPUT_OWNERSHIP"));


// Global Thread Handles
// ----------------------------------------------------------------------------
HANDLE hFileLoaderThread;
HANDLE hInputReaderThread;

// Global Flags
// ----------------------------------------------------------------------------
BOOL bProgramDone = FALSE;