/**
 * \mainpage
 * 
 * \section introduction Introduction
 * 
 * The <a href="http://www.ftdichip.com/Drivers/FT232-FT245Drivers.htm#D2XX">FTD2xx API</a> only supports generic devices, 
 * but it provides a mechanism to extend this device list. The way proposed by 
 * <a href="http://www.ftdichip.com">FTDI</a> is to develop a library called 
 * <b><i>libd2xx_table.so</i></b> which is used to determin whether a 
 * connected <em>USB</em> device should be considered as an 
 * <a href="http://www.ftdichip.com/FTProducts.htm">FTD2xx device</a> or not.<br>
 * <br>
 * When an application tries to determine which 
 * <a href="http://www.ftdichip.com">FTDI</a> devices are available on the 
 * <em>USB</em> bus the <em>FTD2xx API</em> takes every device connected and 
 * askes the <code>d2xx_table</code> API if it's particular VID/PID pair is 
 * known. This is done calling <code>lib_check_device(int, int)</code>.<br>
 * <br>
 * The problem with the suggested way is, that the list of known devices is fixed.
 * 
 * \section overview Overview
 * 
 * This <code>d2xx_table</code> library supports configuring known devices by a
 * special configuration file. It maintains a list of products described by 
 * their <em>USB</em> vendor and product ID.<br>
 * <br>
 * When the library is loaded it first initializes all default IDs. The devices
 * known by default are generic devices with no special purpose. 
 * Currently the following default IDs are set:<br>
 * <pre>
 *    VID     PID
 *  {0x0403, 0x6010} // 2232C
 *  {0x0403, 0x6001} // AM or BM
 *  {0x0403, 0x6006} // Direct Driver PID
 *  {0x0403, 0xFAC1} // Scope 
 * </pre>
 * After the default IDs are initialized the library tries to load user defined 
 * IDs.
 *  
 * \section configuration Configuration
 * 
 * The user can provide it's own IDs by placing a file named 
 * <em>ftd2xx.conf</em> at one of the following locations:
 * <ol>
 * <li>The applications working directory.</li>
 * <li>The user's home directory.</li>
 * <li>At <i>/etc/</i></li>
 * </ol>
 * The configuration file is searched in the above order. The first one found 
 * will be taken for initialization.<br>
 * <br>
 * This file contains line by line the specification of each product that will
 * be recognized by the <em>FTD2xx API</em>. The format of one line is as 
 * follows:<br>
 * <pre>
 *      {<em>0xVID</em>, <em>0xPID</em>} [comment]}
 * </pre>
 *   
 * The <em>VID</em> and <em>PID</em> values must be specified in hexadecimal 
 * notation. Theire values must match the range of <code>0 > ID <= 0xFFFF</code>.
 * After the VID/PID specification a comment describing the particular 
 * product may follow. This comment is just for documentation purpose within the 
 * file and will not be avaluated further. Each product must be placed on a 
 * separate line.
 * 
 * \subsection exampleFile Example
 * <pre>  
 *  {0x0403, 0xFB58} // FTDI FT8U2XX Device 
 *  {0x0403, 0xFB59} // ELV CLI7000
 *  {0x0403, 0xFB5A} // ELV USB-Modul UM100
 *  {0x0403, 0xFB5B} // ELV USB-Modul UO100
 *  {0x0403, 0xFB5C} // ELV PPS7330
 *  {0x0403, 0xFB5D} // ELV Temperatur-Feuchte-Messgeraet
 *  {0x0403, 0xFB5E} // ELV USB DCF Funkuhr UDF 77
 *  {0x0403, 0xFB5F} // ELV USB-I/O-Interface
 *  {0x0403, 0xF068} // ELV USB-AD-Wandler
 *  {0x0403, 0xF069} // ELV USB-DA-Wandler
 *  {0x0403, 0xF06A} // ELV USB-Schrittmotoren-Interface
 *  {0x0403, 0xF06B} // ELV Thermometer T 1100
 *  {0x0403, 0xF06C} // ELV PCD200
 *  {0x0403, 0xF06D} // ELV USB-LCD-Anzeige ULA 200
 * </pre>
 * 
 * \section diagnostics Diagnostics
 * The <em>d2xx_table API</em> is capeable of printing status information of 
 * what's going on (e.g. while initialisation). This is a useful tool to 
 * diagnose why your device isn't recognized by the <em>FTD2xx API</em> although 
 * it shows up on an <em>USB monitor</em> (e.g. 
 * <a href="http://sourceforge.net/projects/usbview">USBView</a>). In most cases 
 * the proper <em>VID</em>/<em>PID</em> pair is missing or the values are 
 * incorrect.<br>
 * <br>
 * To enable printing of diagnostics information an environment variable have to 
 * be specified:<br>
 * <br>
 * <code>FTD2XX_DEBUG=table</code><br>
 * <br>
 * This enables diagnostic output for <em>d2xx_table</em> operations.
 */
 
/**
 * @file d2xx_table.h
 * API used by the <em>FTD2xx API</em> to determine whether a devices is known 
 * ore not.
 */
#ifndef D2XX_TABLE_H_
#define D2XX_TABLE_H_

/**
 * Defines the linkage of declared functions. If this file is included by an 
 * application they're marked as <code>external</code>.
 */
#ifdef D2XX_TABLE_IMPLEMENTATION
#define D2XX_TABLE_DECL
#else
#define D2XX_TABLE_DECL extern
#endif

/**
 * Stores the vendor and product ID for a particular product.
 */
typedef struct
{
    /**
     * The vendor ID.
     */
    int vendorID;
    
    /**
     * The product ID.
     */
    int productID;
} ProductDescriptor;

#ifdef __cplusplus
extern "C"
{
#    endif
    
    D2XX_TABLE_DECL int lib_check_device(int vendorID, int productID);

#ifdef __cplusplus
}
#endif

#endif /* D2XX_TABLE_H_ */
