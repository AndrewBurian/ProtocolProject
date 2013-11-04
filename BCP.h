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
extern queue<byte> quOutputQueue;		// Cue for bytes to be sent
extern queue<byte> quInputQueue;		// Cue for bytes recieved waiting to be written to file


// Global events
// ----------------------------------------------------------------------------
extern HANDLE hAck;
extern HANDLE hNak;
extern HANDLE hEnq;
extern HANDLE hEot;
extern HANDLE hInputAvailable;
extern HANDLE hOutputAVailable;
extern HANDLE hEndProgram;

// Global Comm Port Object and utils
// ----------------------------------------------------------------------------
extern HANDLE hCommPort;			// The IO port used for the medium
extern OVERLAPPED ovrReadPort;		// Overlapped Structure for reading to the comm port
extern OVERLAPPED ovrWritePort;
extern HANDLE hReadComplete;
extern HANDLE hWriteComplete;

// Global Sycronization objects
// ----------------------------------------------------------------------------
//extern HANDLE hDatalinkControl = CreateMutex(NULL, FALSE, TEXT("BCP_LINK_OWNERSHIP"));
//extern HANDLE hOutputBufferControl = CreateMutex(NULL, FALSE, TEXT("BCP_OUTPUT_OWNERSHIP"));


// Global Thread Handles
// ----------------------------------------------------------------------------
extern HANDLE hFileLoaderThread;
extern HANDLE hInputReaderThread;

// Global Flags
// ----------------------------------------------------------------------------
extern BOOL bProgramDone;