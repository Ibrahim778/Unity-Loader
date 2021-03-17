#include <vitasdk.h>
extern "C" 
{
    #include "usb.h"
    //#include "launcher.h"
}
#include <common/debugScreen.h>

#include "utils/vitaPackage.h"

#define print psvDebugScreenPrintf
#define exitDelay 1000
#define vpkPath "ux0:data/sent.vpk"
//char modulePath[] = "ux0:app/UNITYLOAD/ds4vita.skprx";


SceUID usbID = -2;

void InstallPackage()
{
    print("Installing now...\n");
    VitaPackage *package = new VitaPackage(vpkPath);
    if(checkFileExist("ux0:data/UnityLoader/EXTRACTED"))
    {
        print("Installing already extracted folder...\n");
        package->InstallExtracted();
    }
    else
    {
        package->Install();
    }
    
    SceUID file = sceIoOpen("ux0:data/UnityLoader/RUNCOMPLETE", SCE_O_WRONLY | SCE_O_CREAT, 0777);
    sceIoClose(file);
}

void CloseUponComplete()
{
    if(usbID == -2)
    {
        print("USB ID not set you did not start usb first always run this after you have started USB.\n");
        return;
    }
    sceKernelDelayThread(100);
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

void launchThread()
{
    sceClibPrintf("Launch thread started!");
	char uri[32];
	snprintf(uri, sizeof(uri), "psgm:play?titleid=%s", getTitleID().c_str());

	int res = sceAppMgrLaunchAppByUri(0x20000, uri);
	sceKernelExitDeleteThread(res);
}

void openApp() {
	SceUID ThreadID = sceKernelCreateThread("Launchthread", (SceKernelThreadEntry)launchThread, 0x10000100, 0x10000, 0, 0, NULL);
    int res = sceKernelStartThread(ThreadID, 0, NULL);
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

    

    if(!checkFileExist("ux0:data/UnityLoader/CONFIG_READY") || checkFileExist("ux0:data/UnityLoader/RUNCOMPLETE"))
    {
        print("Configuration folder not present or configured incorrectly only run this app from unity unless you have made the config beforehand and you know what you're doing.\n");
        goto EXIT;
    }
    
    if(checkFileExist("ux0:data/UnityLoader/USB"))
    {
        USBMode();
    }
    if(checkFileExist("ux0:data/UnityLoader/INSTALL"))
    {
        InstallPackage();
        openApp();
    }

    goto EXIT;

    EXIT:
        //print("closing in %d seconds\n", exitDelay);
        sceKernelDelayThread(exitDelay);
        print("Exiting now!\n");
        sceKernelExitProcess(0);
}