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
#include <Windows.h>
#include <afxtempl.h>

// Definitions
// ----------------------------------------------------------------------------
#define TIMEOUT 2000

#define ACK 0x00000001
#define NAK 0x00000002
#define EOT 0x00000003
#define ENQ 0x00000004
#define SYN 0x00000005


// Function Declarations
// ----------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
DWORD WINAPI ThreadProc(LPVOID threadParams);


// Global Stores
// ----------------------------------------------------------------------------
CList<byte> outputCue;		// Cue for bytes to be sent


// Global events
// ----------------------------------------------------------------------------
HANDLE hAck				= CreateEvent(NULL, FALSE, FALSE, TEXT("PROTOCOLX_ACK"));
HANDLE hNak				= CreateEvent(NULL, FALSE, FALSE, TEXT("PROTOCOLX_NAK"));
HANDLE hEnq				= CreateEvent(NULL, FALSE, FALSE, TEXT("PROTOCOLX_ENQ"));
HANDLE hInputAvailable	= CreateEvent(NULL, FALSE, FALSE, TEXT("PROTOCOLX_INPUT_AVAILABLE"));
HANDLE hOutputAVailable	= CreateEvent(NULL, FALSE, FALSE, TEXT("PROTOCOLX_OUTPUT_AVAILABLE"));
HANDLE hEndProgram		= CreateEvent(NULL, TRUE, FALSE, TEXT("PROTOCOLX_END_OF_PROGRAM"));


// Global Sycronization objects
// ----------------------------------------------------------------------------
HANDLE hDatalinkControl		= CreateMutex(NULL, FALSE, TEXT("PROTOCOLX_LINK_OWNERSHIP"));


// Global Thread Handles
// ----------------------------------------------------------------------------
HANDLE hFileLoaderThread;
HANDLE hInputReaderThread;