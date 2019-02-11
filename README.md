FTD2XXJ Java JNI Wrapper for the FTDI D2XX driver
=================================================

Original source code is available [here](http://sourceforge.net/projects/ftd2xxj/)

The current project has been setup on a Raspberry PI 2 (arm-v7)
and has updated CDT C++ project settings to compile the library on this architecture.

*Warning* To correctly access the ports please ensure these conditions:

* The default serial driver has been disabled ( run ```sudo lsmod``` and if you see ```ftdi_sio``` and ```usbserial``` unload these drivers: ```sudo rmmod ftdi_sio``` then ```sudo rmmod usbserial```
* The application is run as ```sudo```.

If you don't run the application as sudo, the correct number of ports may be listed, but they won't be accessible.
A basic c++ test will ouput this (for a 4 port RS485 converter) without sudo:
```
Number of FTDI devices is 4
Dev 0:
 Flags=0x1
 Type=0x3
 ID=0x0
 LocId=0x0
 SerialNumber=
 Description=
 ftHandle=0x0
Dev 1:
 Flags=0x1
 Type=0x3
 ID=0x0
 LocId=0x0
 SerialNumber=
 Description=
 ftHandle=0x0
Dev 2:
 Flags=0x1
 Type=0x3
 ID=0x0
 LocId=0x0
 SerialNumber=
 Description=
 ftHandle=0x0
Dev 3:
 Flags=0x1
 Type=0x3
 ID=0x0
 LocId=0x0
 SerialNumber=
 Description=
 ftHandle=0x0

``` 
while with sudo everything works as expected:
```
Number of FTDI devices is 4
Dev 0:
 Flags=0x2
 Type=0x7
 ID=0x4036011
 LocId=0x1061
 SerialNumber=FTURXP83A
 Description=USB2-H-5004-M A
 ftHandle=0x0
Dev 1:
 Flags=0x2
 Type=0x7
 ID=0x4036011
 LocId=0x1062
 SerialNumber=FTURXP83B
 Description=USB2-H-5004-M B
 ftHandle=0x0
Dev 2:
 Flags=0x2
 Type=0x7
 ID=0x4036011
 LocId=0x1063
 SerialNumber=FTURXP83C
 Description=USB2-H-5004-M C
 ftHandle=0x0
Dev 3:
 Flags=0x2
 Type=0x7
 ID=0x4036011
 LocId=0x1064
 SerialNumber=FTURXP83D
 Description=USB2-H-5004-M D
 ftHandle=0x0

```
Using the java wrapper, this may throw an error calling ```Service.listDevices()```

Eclipse project details
=======================

Version: 3.8.1
Build id: debbuild

It included the following plugins:

Eclipse CVS Client

Version: 1.3.200.dist-7B79FJJ9exZ_
Build id: debbuild

Eclipse Java Development Tools

Version: 3.8.1.dist-8-8nFqrFFgQGJ
Build id: debbuild

Eclipse Platform

Version: 3.8.1.dist-A8F8_IVSG4VZSDmg7oLVfBs5JohYFyJZcMPL9
Build id: debbuild

Eclipse Project SDK

Version: 3.8.1.dist-7Q85DOBoMDElVYJXaEcz0e0aY6Tnt0Ra0eDROJ9IBeOgk
Build id: debbuild

Eclipse RCP

Version: 3.8.1.dist-8LA2GODFTJUDJ21934
Build id: debbuild


Eclipse Help

Version: 1.4.1.dist-8v7oFRvFCmSPZkILLj597H
Build id: debbuild

Eclipse Plug-in Development Environment

Version: 3.8.1.dist-7c7vFiyFALX8A
Build id: debbuild

CDT details:

Eclipse GCC Cross Compiler Support

Version: 8.5.0.dist
GDB Common

Version: 8.5.0.dist

CDT GCC compiler setup
======================

C Compiler
----------

Includes
--------
The main ones are the jni.h and other JNI headers in JDK_PATH/include
and the ftd2xx.h and WinTypes.h headers for ftd2xx
```
/usr/lib/jvm/java-7-openjdk-armhf/include
/usr/lib/jvm/java-7-openjdk-armhf/include/linux
"${workspace_loc:/${ProjName}/external/include}"
```

Warnings
--------
all (```-Wall```)

Miscaleneous > Other Flags
--------------------------

```
-c -fmessage-length=0 -fPIC -march=armv7-a -mfloat-abi=hard -ftree-vectorize -Wno-psabi -pipe
```


C Linker
--------

Libraries (-l)
--------------
jvm
ftd2xx

Libraries search path(-L)
-------------------------
!!The Java7JDK client path got erased (perhaps eclipse project settings for the clean phase ?)

```
/usr/lib/jvm/jdk-8-oracle-arm-vfp-hflt/jre/lib/arm/client
../external
"${workspace_loc:/${ProjName}/external}"
```

Miscaleneous > Other Flags
--------------------------
```
--no-undefined
```

Shared library settings
-----------------------
Shared is on (-shared)
Shared object name
```
lib${BuildArtifactFileName}.${MAJOR_VERSION}
```
**Note:** MAJOR_VERSION and MINOR_VERSION are defined in C/C++ Build > Build Variables (as Strings)
