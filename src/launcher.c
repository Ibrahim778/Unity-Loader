#include <vitasdk.h>
#include <common/debugScreen.h>
#include "usb.h"
#include <psp2kern/kernel/modulemgr.h>
#include <malloc.h>
#include <taihen.h>
#include <stdio.h>
#include <stdlib.h>

#define print psvDebugScreenPrintf
#define idFilePath "ux0:data/UnityLoader/LoaderID"
#define launchedFilePath "ux0:data/UnityLoader/launched"
#define bigBuffer 16*1024*1024
#define Path "ux0:data/psvita/psvita.self"

/*
int launchByPath(char *Path)
{
    if(checkFileExist(Path))
    {
        print("The self exists at: %s\n", Path);
    }
    else print("There is no self at %s !\n", Path);

    int opt[52/4];
    memset(opt, 0, sizeof(opt));
    opt[0] = sizeof(opt);
    
    int res = sceAppMgrLaunchAppByPath4(Path, NULL, 0, 0x2000000, opt);
    if(res < 0)
        print("error: %x\n", res);
    
    return 0;
}
*/

int WriteFile(const char *file, const void *buf, int size) {
  SceUID fd = sceIoOpen(file, SCE_O_WRONLY | SCE_O_CREAT | SCE_O_TRUNC, 0777);
  if (fd < 0)
    return fd;

  int written = sceIoWrite(fd, buf, size);

  sceIoClose(fd);
  return written;
}

int ReadFile(const char *file, void *buf, int size) {
  SceUID fd = sceIoOpen(file, SCE_O_RDONLY, 0);
  if (fd < 0)
    return fd;

  int read = sceIoRead(fd, buf, size);

  sceIoClose(fd);
  return read;
}

int StartModule(char * path)
{
  /*
    if(checkFileExist(launchedFilePath))
    {
      return 0;
    }

    print("Starting module!\n");
    SceUID res = taiLoadStartKernelModule(path, 0, NULL ,0);
    if(res < 0)
    {
        print("Error starting Kernel Module! : %x\n", res);    
        return res;
    }
    print("SceUID is: %d\n", res);

    FILE *file = fopen(idFilePath,"w");
    if(file == NULL)
    {
      print("Couldn't open to write!\n");
      return -1;
    }

    fprintf(file,"%d",res);
    fclose(file);
  */
  int res = sceAppMgrLaunchAppByPath4("ux0:app/AUTOPLUG0/eboot.bin");
  print("%x", res);
      
    return 0;
}