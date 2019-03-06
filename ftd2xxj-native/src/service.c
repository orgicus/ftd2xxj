#include "com_ftdichip_ftd2xx_Service.h"

#include <stdlib.h>

#include <ftd2xx.h>
#include "error.h"
#include "ftd2xxj.h"

#define LOGGER_IMPLEMENTATION
#include "logger.h"

static const char DEVICE_CLASS[] = "com/ftdichip/ftd2xx/Device";

#ifdef MAX_NUM_DEVICES
#undef MAX_NUM_DEVICES // defined in WinTypes.h
#endif

static const int MAX_NUM_DEVICES = 127;

JNIEXPORT jobjectArray JNICALL Java_com_ftdichip_ftd2xx_Service_listDevices
(JNIEnv *env, jclass service)
  {

    jclass deviceClass = NULL;
    jobjectArray devices = NULL;
    jmethodID deviceConstructor = NULL;
    DWORD numDevices = 0;
    DWORD i = 0;

    FT_DEVICE_LIST_INFO_NODE deviceList[MAX_NUM_DEVICES];
    FT_STATUS result = FT_CreateDeviceInfoList(&numDevices);

    Logger_Fine("(%s: %i) - FT_CreateDeviceInfoList(%i): %i", __FILE__, __LINE__,
        (int)numDevices, (int)result);

    if(result != FT_OK)
      {
        HandleError(env, result);
        return NULL;
      }

    result = FT_GetDeviceInfoList(deviceList, &numDevices);

    Logger_Fine("(%s: %i) - FT_GetDeviceInfoList(deviceList, %i): %i", __FILE__, __LINE__,
        (int)numDevices, (int)result);

    if(result != FT_OK)
      {
        HandleError(env, result);
        return NULL;
      }

    deviceClass = (*env)->FindClass(env, DEVICE_CLASS);
    if(deviceClass == NULL)
      {
        /* an exception has already been thrown. */
        return NULL;
      }

    devices = (*env)->NewObjectArray(env, numDevices, deviceClass, NULL);
    if(devices == NULL)
      {
        /* an exception has already been thrown. */
        return NULL;
      }

    deviceConstructor = (*env)->GetMethodID(env, deviceClass, "<init>", "(JJ)V");
    if(deviceConstructor == NULL)
      {
        /* an exception has already been thrown. */
        return NULL;
      }

    /* Create devices by their location IDs and fill devices array  */
    for(i = 0; i < numDevices; i++)
      {
        jobject device = NULL;

        Logger_Fine("(%s: %i) - Create device:\n\tDescription: %s\n\tSerialNumber: %s\n\tType: %i\n\tftHandle: %X\n\tID: %i\n\tLocId: %X\n\tFlags: %X\n", __FILE__, __LINE__,
            deviceList[i].Description,
            deviceList[i].SerialNumber,
            (int)deviceList[i].Type,
            (unsigned int)deviceList[i].ftHandle,
            (unsigned int)deviceList[i].ID,
            (unsigned int)deviceList[i].LocId,
            (unsigned int)deviceList[i].Flags);

        device = (*env)->NewObject(env, deviceClass, deviceConstructor, (jlong)i, (jlong)deviceList[i].Type);
        if(device == NULL)
          {
            /* an exception has already been thrown. */
            return NULL;
          }

        (*env)->SetObjectArrayElement(env, devices, i, device);
        if((*env)->ExceptionCheck(env) == JNI_TRUE)
          {
            /* an exception has already been thrown. */
            return NULL;
          }
      }

    return devices;
  }

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Service_startInputTask
(JNIEnv *env, jclass service, jlong handle)
  {

    FT_STATUS result = FT_RestartInTask(ToNativeHandle(handle));

    Logger_Fine("(%s: %i) - FT_RestartInTask(%X): %i", __FILE__, __LINE__,
        (unsigned int)ToNativeHandle(handle), (int)result);

    HandleError(env, result);
  }

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Service_stopInputTask
(JNIEnv *env, jclass service, jlong handle)
  {

    FT_STATUS result = FT_StopInTask(ToNativeHandle(handle));

    Logger_Fine("(%s: %i) - FT_StopInTask(%X): %i", __FILE__, __LINE__,
        (unsigned int)ToNativeHandle(handle), (int)result);

    HandleError(env, result);
  }

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Service_rescan
(JNIEnv *env, jclass service)
  {
    FT_STATUS result = FT_OK;

#ifdef _WINDOWS
    result = FT_Rescan();

    Logger_Fine("(%s: %i) - FT_Rescan(): %i", __FILE__, __LINE__,
        (int)result);
#else
    result = FT_NOT_SUPPORTED;
    Logger_Severe("(%s: %i) - FT_Rescan() is not supported on this OS.", __FILE__, __LINE__);
#endif

    HandleError(env, result);
  }

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Service_reload
(JNIEnv *env, jclass service, jint vid, jint pid)
  {
    FT_STATUS result = FT_OK;

#ifdef _WINDOWS
        result = FT_Reload((WORD)vid, (WORD)pid);

        Logger_Fine("(%s: %i) - FT_Reload(): %i", __FILE__, __LINE__,
            (int)result);
#else
        result = FT_NOT_SUPPORTED;
        Logger_Severe("(%s: %i) - FT_Reload() is not supported on this OS.", __FILE__, __LINE__);
#endif

        HandleError(env, result);
  }
