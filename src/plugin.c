#include <dlfcn.h>

#include "plugin.h"


Plugin loadPlugin(const char* path){
    Plugin op;

    op.handle = dlopen(path, RTLD_NOW);

    char* (*GetName)(void);
    GetName = dlsym(op.handle, "GetName");
    if(GetName != NULL) op.name = (*GetName)();
    else op.name = "";

    op.enabled = false;
    op.CheckEnable = dlsym(op.handle, "CheckEnable");
    op.PrintHelp = dlsym(op.handle, "PrintHelp");
    op.CMake_Inclusion = dlsym(op.handle, "CMake_Inclusion");
    op.CMake_Addition = dlsym(op.handle, "CMake_Addition");
    op.CMake_Linking = dlsym(op.handle, "CMake_Linking");
    op.Main_Include = dlsym(op.handle, "Main_Include");
    op.Main_ExtendBody_Start = dlsym(op.handle, "Main_ExtendBody_Start");
    op.Main_ExtendBody_End = dlsym(op.handle, "Main_ExtendBody_End");
    op.Files_Manipulate = dlsym(op.handle, "Files_Manipulate");

    return op;
}
