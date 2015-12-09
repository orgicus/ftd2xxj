#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Define linkage to be non-external for implementation purpose.
 */
#define D2XX_TABLE_IMPLEMENTATION
#include "d2xx_table.h"
#include "d2xx_debug.h"
#include "d2xx_init.h"

/**
 * Macro to determine the number of elements an array consists of.
 */
#define SIZEOF(x) (sizeof(x)/sizeof(x[0]))

/**
 * The maximum number of devices that can be managed by this API.
 */
#define MAX_NUM_DEVICES 127

/**
 * Declares the libnraries constructor called right after the library was loaded.
 */
void __attribute__ ((constructor)) d2xx_table_initialize(void);

/**
 * Declares the libnraries deconstructor called prior to the library is unloaded.
 */
void __attribute__ ((destructor)) d2xx_table_cleanup(void);

/**
 * Table of all known products. 
 */
static ProductDescriptor ID_TABLE[MAX_NUM_DEVICES] = { {0, 0} };

/**
 * Default IDs from FTDI
 */
static const int DEFAULT_ID_TABLE[][2] = {
    {0x0403, 0x6010},   /* 2232C */
    {0x0403, 0x6001},   /* AM or BM */
    {0x0403, 0x6006},   /* Direct Driver PID */
    {0x0403, 0xFAC1}    /* Scope */
};

/**
 * Retrieves the table of all known products.
 * 
 * @return the entire array of #ProductDescriptor items to store new descriptors
 * in.
 */
ProductDescriptor *GetProductDescriptorTable()
{
    return ID_TABLE;
}

/**
 * Retrieves the number of elements the product descriptor table consits of.
 * 
 * @return the number of array elements.
 * @see #GetProductDescriptorTable
 */
int GetProductDescriptorTableSize()
{
    return SIZEOF(ID_TABLE);
}

/**
 * Retrieves the number of default #ProductDescriptor items.
 */
int GetNumDefaultProductDescriptors()
{
    return SIZEOF(DEFAULT_ID_TABLE);
}

/**
 * Initializes the table of known product descriptors with the default 
 * descriptors.
 */
static void InitializeDefaultIDs()
{
    int i = 0;

    for(i = 0; i < SIZEOF(DEFAULT_ID_TABLE); i++) {
        ID_TABLE[i].vendorID = DEFAULT_ID_TABLE[i][0];
        ID_TABLE[i].productID = DEFAULT_ID_TABLE[i][1];
    }
}

/**
 * Opens the configuration file, stores the product descriptors read to the 
 * product descriptor table and finally closes the file.
 */
static void InitializeSystemIDs()
{
    FILE *file = D2xx_OpenConfigFile();

    if(file != NULL) {
        D2xx_ReadTable(file, GetProductDescriptorTable(),
                       GetProductDescriptorTableSize(),
                       GetNumDefaultProductDescriptors());
                       
        D2xx_CloseConfigFile(file);
    }
}

/**
 * Initializes the known VID/PID pairs. First the deafult VID/PID pairs are added. 
 * And finally the ones read from .d2xx_table.
 */
void d2xx_table_initialize(void)
{
    InitializeDefaultIDs();
    InitializeSystemIDs();
}

/**
 * 
 */
void d2xx_table_cleanup(void)
{
    memset(ID_TABLE, 0, sizeof(ID_TABLE));
}

/**
 * Determines whether a <em>VID</em>/<em>PID</em> pair is known or not.
 * 
 * @param vendorID the vendor ID.
 * @param productID the productID.
 * @return <code>1</code> if the product is known, <code>0</code> otherwise.
 */
int lib_check_device(int vendorID, int productID)
{
    int i = 0;
    int result = 0;

    DebugTrace("d2xx_table: Check device\n");
    DebugTrace("\tVID: 0x%X\n", vendorID);
    DebugTrace("\tPID: 0x%X\n", productID);

    for(i = 0;
        i < MAX_NUM_DEVICES && ID_TABLE[i].vendorID != 0
        && ID_TABLE[i].productID != 0; i++) {

        if((ID_TABLE[i].vendorID == vendorID)
           && (ID_TABLE[i].productID == productID)) {

            result = 1;
            break;
        }
    }

    DebugTrace("\tDevice was %sFOUND.\n", ((result == 0) ? "NOT " : ""));

    return result;  /* no match */
}
