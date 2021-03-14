#include <psp2kern/kernel/modulemgr.h>
#include <psp2kern/kernel/threadmgr.h>
#include <psp2kern/kernel/sysmem.h>
#include <psp2kern/kernel/suspend.h>
#include <psp2kern/bt.h>
#include <psp2kern/ctrl.h>
#include <psp2/touch.h>
#include <psp2/motion.h>
#include <taihen.h>
#include <vitasdkkern.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define printf ksceDebugPrintf
#define pathReady "ux0:data/UnityLoader/LaunchReady"
#define launchFilePath "ux0:data/UnityLoader/launched"
#define PathFileLocation "ux0:data/UnityLoader/KernelLaunchPath"
#define PathFileSizeLocaiton "ux0:data/UnityLoader/PathSize"
#define maxCharLength 4096

char location[maxCharLength];

int checkFileExist(const char *file) {
  SceUID fd = ksceIoOpen(file, SCE_O_RDONLY, 0);
  if (fd < 0)
    return 0;

  ksceIoClose(fd);
  return 1;
}

int getFileSize(const char *file) {
  SceUID fd = ksceIoOpen(file, SCE_O_RDONLY, 0);
  if (fd < 0)
    return fd;

  int fileSize = ksceIoLseek(fd, 0, SCE_SEEK_END);

  ksceIoClose(fd);
  return fileSize;
}


int LauncherThread()
{
    printf("Thread Started!\n");
    SceUID file = ksceIoOpen(launchFilePath, SCE_O_WRONLY | SCE_O_CREAT, 0777);
    ksceIoClose(file);
    printf("Running now!\n");

    while (1)
    {
        if(checkFileExist(pathReady))
        {
            ksceKernelDelayThread(100);

            int file = ksceIoOpen(PathFileLocation, SCE_O_RDONLY, 0777);
          
            ksceIoRead(file, &location, maxCharLength);
            ksceIoClose(file);
            printf("Got location :\n %s\n",location);
            ksceIoRemove(PathFileLocation);
            ksceIoRemove(pathReady);

            char recudedLocation[strlen(location)];
            
            strcpy(recudedLocation, location);

            printf("Location after removal :\n %s (end's one space before this)\n", recudedLocation);

            if(checkFileExist(recudedLocation))
            {
              printf("It exists looool\n");
              printf("Launching...\n");
              int opt[52/4];
              for (int i = 0; i < sizeof(opt)/4; i++) {
                opt[i] = 0;
              }
              opt[0] = sizeof(opt);
              //int res = ksceAppMgrLaunchAppByPath(recudedLocation, NULL, 0, 0, opt, NULL);
              int res = sceAppMgrLaunchAppByPath4(recudedLocation, NULL, 0, 0, opt,NULL);
              printf("launch result: %d\n", res);
            }
            else printf("Nop >_<\n");
        }
        ksceKernelDelayThread(1000);
    }
    
    /*
    AppMgrLaunchParam param;
    param.unk_4 = 0x80000000;
 
	int res = ksceAppMgrLaunchAppByPath("ux0:app/VITASHELL/eboot.bin", real_args, sizeof(launch_args), 0x80000000, &param, nullptr);
*/
    return 0;
}

int _start() __attribute__ ((weak, alias ("module_start")));

int module_start(SceSize argc, const void *args)
{
    printf("Launcher Loaded!\n");

    printf("Creating Thread...\n");


    SceUID launchThread = ksceKernelCreateThread("LauncherThread\n", (SceKernelThreadEntry)LauncherThread, 0x3C, 0x1000, 0, 0x10000, 0);

    printf("Starting Thread\n");
    ksceKernelStartThread(launchThread,0,NULL);

    return SCE_KERNEL_START_SUCCESS;
}

int module_stop(SceSize argc, const void *args)
{
    printf("Stopping Launcher!\n");
    ksceIoRemove(launchFilePath);
    return SCE_KERNEL_STOP_SUCCESS;
}