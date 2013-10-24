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


// Function Declarations
// ----------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
DWORD WINAPI ThreadProc(LPVOID threadParams);


// Global Stores
// ----------------------------------------------------------------------------
byte _output[1024];
byte _input[1024];

// Global events
// ----------------------------------------------------------------------------


// Global Sycronization objects
// ----------------------------------------------------------------------------
HANDLE hInputMutex	= CreateMutex(NULL, FALSE, TEXT("PROTOCOL_X_INPUT_BUFFER"));
HANDLE hOutputMutex = CreateMutex(NULL, FALSE, TEXT("PROTOCOL_X_OUTPUT_BUFFER"));
HANDLE hSerialIO	= CreateMutex(NULL, FALSE, TEXT("PROTOCOL_X_SERIAL_IO"));