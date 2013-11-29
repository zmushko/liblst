#include <stdio.h>
#include <errno.h>
#include <stdarg.h>

#include "rnotify.h"

int executeShellFormat(const char* format, ...)
{
	if(!format)
	{
		errno = EINVAL;
		return -1;
	}

	va_list ap, apn;
        va_start(ap, format);
	va_copy(apn, ap);

	char* shell = (char*)malloc(vsnprintf(NULL, 0, format, apn) + 1);
        if(!shell)
	{
	        va_end(ap);
	        va_end(apn);
		errno = ENOMEM;
		return -1;
	}
	vsprintf(shell, format, ap);
        va_end(apn);
        va_end(ap);

	int rval = system(shell);
	free(shell);

	return rval;
}

