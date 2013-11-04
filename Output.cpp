// output function library.
#include "BCP.h"

static byte dataFrame[1024] = { NULL };
static int SOTval = 1;


BOOL Resend()
{
	if (dataFrame[0] == NULL)
	{
		// no previously sent frame.
		// failed to resend
		return FALSE;
	}

	// send code here

	return TRUE;
}

BOOL SendNext()
{
	
}

