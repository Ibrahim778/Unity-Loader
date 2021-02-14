#include <vitasdk.h>
extern "C" 
{
    #include "usb.h"
}
#include <common/debugScreen.h>

#include "utils/vitaPackage.h"

#define print psvDebugScreenPrintf

#define vpkPath "ux0:data/sent.vpk"

SceUID usbID = -2;

void InstallPackage()
{
    print("Installing now...\n");
    VitaPackage *package = new VitaPackage(vpkPath);
    if(checkFileExist("ux0:data/UnityLoader/EXTRACTED"))
    {
        print("Installing already extracted folder...");
        package->InstallExtracted();
    }
    else
    {
        package->Install();
    }
}

void CloseUponComplete()
{
    if(usbID == -2)
    {
        print("USB ID not set you did not start usb first always run this after you have started USB.\n");
        return;
    }
    sceKernelDelayThread(3*1000000);
    if(checkFileExist("ux0:data/UnityLoader/COPYING"))
    {
        CloseUponComplete();
    }
    else
    {
        print("Copying should have completed closing USB\n");
        stopUsb(usbID);
    }
    return;
}

int USBMode()
{
    print("Starting USB\n");
    usbID = initUsb();
    if(usbID < 0)
    {
        print("Error loading USB with error code: %x\n", usbID);
        return -1;
    }
    else
    {
        CloseUponComplete();
    }
    return 0;
}

int main(int argc, char* argsv[])
{
    psvDebugScreenInit();
    psvDebugScreenSetFont(psvDebugScreenScaleFont2x(psvDebugScreenGetFont()));
    print("Welcome to UnityLoader C++\n");

    

    if(!checkFileExist("ux0:data/UnityLoader/CONFIG_READY"))
    {
        print("Configuration folder not present or configured incorrectly only run this app from unity unless you have made the config beforehand and you know what you're doing.\n");
        goto EXIT;
    }
    
    if(checkFileExist("ux0:data/UnityLoader/USB"))
    {
        USBMode();
        InstallPackage();
        openApp(getTitleID());
    }
    else
    {
        InstallPackage();
        openApp(getTitleID());
    }
    
    goto EXIT;

    EXIT:
        print("closing in 3 seconds\n");
        sceKernelDelayThread(3*1000000);
        print("Exiting now!\n");
        sceKernelExitProcess(0);
}