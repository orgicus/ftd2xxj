/**
 * @file d2xx_debug.h
 * API to print diagnostics information and to determin whether printing is
 * enabled, or not.
 */
#ifndef D2XX_DEBUG_H_
#define D2XX_DEBUG_H_

/**
 * Defines the linkage of declared functions. If this file is included by an 
 * application they're marked as <code>external</code>.
 */
#ifdef D2XX_DEBUG_IMPLEMENTATION
#define D2XX_DEBUG_DECL
#else
#define D2XX_DEBUG_DECL extern
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    D2XX_DEBUG_DECL int IsDebugEnabled(void);
    D2XX_DEBUG_DECL void DebugTrace(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif /* D2XX_DEBUG_H_ */
