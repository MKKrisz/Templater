#include <stdio.h>

#include "src/plugin_handler.h"
#include "src/arghandler.h"
#include "src/project_builder.h"

int main(int argc, char** argv){
    PluginArray* handle = PluginArray_LoadAll();

    char* projName = HandleArgs(handle, argc, argv);
    if(projName[0] != '\0') BuildProject(handle, projName);
    PluginArray_Dealloc(handle);
    return 0;
}
