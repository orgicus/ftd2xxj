#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/**
 * Define linkage to be non-external for implementation purpose.
 */
#define D2XX_DEBUG_IMPLEMENTATION
#include "d2xx_debug.h"

/**
 * Determines whether debugging is enabled or not.
 * 
 * Values:
 * -1: Not initialized
 *  0: Disabled
 *  1: Enabled
 */
static int isDebugEnabled = -1;

/**
 * Name of the environment variable.
 */
static const char D2XX_DEBUG_NAME[] = "FTD2XX_DEBUG";

/**
 * Value to be set for the environment variable when d2xx_table should print 
 * debugging information.
 */
static const char D2XX_DEBUG_TABLE_VALUE[] = "table";

/**
 * Determines whether the environment variable <b>FTD2XX_DEBUG</b> is set 
 * to <b>table</b> or not.
 * 
 * @return <code>1</code> if the environmentvariable exists and is set to 
 * <b>table</b>, otherwise <code>0</code>.
 */
static int GetDebugEnabled(void)
{
    int result = 0;
    char *envString = getenv(D2XX_DEBUG_NAME);

    if(envString != NULL)
        result = strcmp(envString, D2XX_DEBUG_TABLE_VALUE) == 0;

    return result;
}

/**
 * Determines whether debugging for the d2xx_table library is enabled or not. 
 * Debugging can be enabled if the environment variable <b>FTD2XX_DEBUG</b> is 
 * set to <b>table</b>.
 * 
 * @return <code>1</code> if debugging is enabled, <code>0</code> 
 * otherwise.
 */
int IsDebugEnabled(void)
{
    if(isDebugEnabled == -1)
        isDebugEnabled = GetDebugEnabled();

    return isDebugEnabled;
}

/**
 * Calls <code>printf</code> using the format and all optional parameters, but 
 * only if debugging is enabled.
 * 
 * @param format the format specification recognized by <code>printf</code>.
 */
void DebugTrace(const char *format, ...)
{
    if(!IsDebugEnabled())
        return;

    va_list parameters = 0;

    va_start(parameters, format);

    /*
     * skip parameter "format" 
     */
    parameters = (va_list) va_arg(parameters, const char *);

    printf(format, parameters);

    va_end(parameters);
}
