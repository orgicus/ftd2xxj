#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

/**
 * Define linkage to be non-external for implementation purpose.
 */
#define D2XX_INIT_IMPLEMENTATION
#include "d2xx_init.h"
#include "d2xx_table.h"
#include "d2xx_debug.h"

/**
 * Minimum value of an ID.
 */
static const int MIN_ID_VALUE = 1;

/**
 * Maximum value of an ID.
 */
static const int MAX_ID_VALUE = 0xFFFF;

/**
 * The name of the configuration file.
 */
static const char FILE_NAME[] = "ftd2xx.conf";

/**
 * The number of search path entries.
 */
static const int SEARCH_PATH_LENGTH = 3;

/**
 * The index within #SEARCH_PATH for the user's home directory. The home 
 * directory can not be specified statically. So it is updated when the library 
 * is loaded.
 */
static const int USER_HOME_INDEX = 1;

/**
 * Array of file system locations to search for the configuration file.
 */
static char *SEARCH_PATH[] = {
    ".",
    NULL,
    "/etc"
};

/**
 * Pattern specifying all readable ASCII characters. this pattern is used to
 * read one line from the configuration file.
 */
static const char READ_LINE_PATTERN[] = "%[ -~\t\r]\n";

/**
 * Pattern specifying the format of VID/PID table within the configuration file.
 */
static const char LINE_SCAN_PATTERN[] = "%*[{\t ]0x%x%*[,\t ]0x%x%*[}\t ]";
static char readBuffer[1024] = { 0 };

/**
 * Determines the current user's home directory and updates the search path.
 */
static void UpdateSearchPath(void)
{
    SEARCH_PATH[USER_HOME_INDEX] = getenv("HOME");
}

/**
 * Reads the next line from a text file.
 * 
 * @param file the file to read from.
 * @buffer the buffer to store the read characters in.
 */
static int ReadLine(FILE * file, char *buffer)
{
    return fscanf(file, READ_LINE_PATTERN, buffer);
}

/**
 * Determines whether an ID value is valid or not.
 * 
 * @param id the ID to check for validity.
 * 
 * @return a positive value if the ID matches the range of values, 
 * <code>0</code> otherwise.
 */
static int IsValidID(unsigned int id)
{
    return (id > MIN_ID_VALUE && id <= MAX_ID_VALUE);
}

/**
 * Extracts the vendor and product ID from line read.
 * 
 * @param line the string containing the characters read from the configuration 
 *      file.
 * 
 * @param vendorId stores the vendor ID extracted from the <code>line</code>.
 * @param productId stores the product ID extracted from the <code>line</code>.
 * @return <code>2</code> if both ID were successfully extracted and their 
 *      values are valid, otherwise the number of valid IDs extracted.
 */
static int ExtractParameters(const char *line,
                  unsigned int *vendorID, unsigned int *productID)
{

    int result = sscanf(line, LINE_SCAN_PATTERN, vendorID, productID);

    if(result == 2 && (!IsValidID(*vendorID) || !IsValidID(*productID))) {
        DebugTrace
            ("\t Range Error: The VID/PID must match 0 > ID <= 0xFFFF.\n");

        result = 0;
    }

    return result;
}

/**
 * Opens the configuration file. The following locations are searched for the 
 * file:<br>
 * <ol>
 * <li>The current working directory.</li>
 * <li>The user's home directory.</li>
 * <li><code>/etc/</code></li>
 * </ol>
 * 
 * @return the opened file. <code>NULL</code> if the file was not found or could 
 *  not be opened.
 */
FILE *D2xx_OpenConfigFile()
{
    FILE *result = NULL;
    char filePath[FILENAME_MAX] = { 0 };
    int i = 0;

    UpdateSearchPath();

    DebugTrace("d2xx_table: Open configuration file...\n");
    for(i = 0; i < SEARCH_PATH_LENGTH; i++) {
        memset(filePath, 0, strlen(filePath));

        sprintf(filePath, "%s/%s", SEARCH_PATH[i], FILE_NAME);

        DebugTrace("\tTry to open %s - ", filePath);
        result = fopen(filePath, "r");

        DebugTrace("%s\n", strerror(errno));
        if(result != NULL)
            break;
    }

    return result;
}

/**
 * Closes an open file.
 * 
 * @param file the file to close.
 */
void D2xx_CloseConfigFile(FILE * file)
{
    fclose(file);

    DebugTrace("d2xx_table: Close configuration file - %s\n",
               strerror(errno));
}

/**
 * Reads the next #ProductDescriptor from a file.
 * 
 * @param file the file to read from.
 * @param desc the #ProductDescriptor to store the IDs in.
 * @return the results from #ReadLine or #Extractparameters.
 */
static int ReadNextProductDescriptor(FILE * file, ProductDescriptor * desc)
{
    int result = 0;

    memset(readBuffer, 0, strlen(readBuffer));
    result = ReadLine(file, readBuffer);

    if(result != EOF) {
        DebugTrace("\tRead: %s\n", readBuffer);
        result =
            ExtractParameters(readBuffer, (unsigned int*)&desc->vendorID,
                              (unsigned int*)&desc->productID);

        if(result != 2) {
            DebugTrace("\tInvalid product descriptor\n", readBuffer);
        } else {
            DebugTrace("\tVID: %X\n", desc->vendorID);
            DebugTrace("\tPID: %X\n", desc->productID);
        }
    } else {
        DebugTrace("\tRead: EOF\n");
    }

    return result;
}

/**
 * Reads all valid <em>VID</em>/<em>PID</em> specifications from a file and 
 * updates the product descriptor table.
 * 
 * @param file the file to read from.
 * @param table the table to store the read descriptors in.
 * @param tableSize the size of the table in array elements.
 * @param tableOffset the offset at which to start writing the descriptors to.
 */
void D2xx_ReadTable(FILE * file, ProductDescriptor* table, int tableSize, int tableOffset)
{
    int i = 0;
    
    for(i = tableOffset; i < tableSize; i++) {
        ProductDescriptor desc = { 0, 0 };

        DebugTrace("d2xx_table: Read product descriptor %i:\n",
                   (i - tableOffset) + 1);

        int result = ReadNextProductDescriptor(file, &desc);

        if(result == EOF)
            break;

        if(result > 0) {
            table[i].vendorID = desc.vendorID;
            table[i].productID = desc.productID;
        } else {
            i--;
        }
    }

    if(i >= tableSize)
        DebugTrace
            ("d2xx_table: Too much product descriptors specified. Only %i VID/PID pairs can be managed.\n",
             tableSize);
}
