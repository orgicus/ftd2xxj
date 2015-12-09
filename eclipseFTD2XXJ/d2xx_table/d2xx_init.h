/**
 * @file d2xx_init.h
 * API for initialisation of user defined <em>VID</em>/<em>PID</em> pairs.
 */
#ifndef D2XX_INIT_H_
#define D2XX_INIT_H_

#include <stdio.h>
#include "d2xx_table.h"


/**
 * Defines the linkage of declared functions. If this file is included by an 
 * application they're marked as <code>external</code>.
 */
#ifdef D2XX_INIT_IMPLEMENTATION
    #define D2XX_INIT_DECL
#else
    #define D2XX_INIT_DECL extern
#endif

#ifdef __cplusplus
extern "C" {
#endif

    D2XX_INIT_DECL FILE *D2xx_OpenConfigFile(void);
    D2XX_INIT_DECL void D2xx_CloseConfigFile(FILE * file);
    D2XX_INIT_DECL void D2xx_ReadTable(FILE * file, ProductDescriptor* table, int tableSize, int tableOffset);

#ifdef __cplusplus
}
#endif

#endif /*D2XX_INIT_H_*/
