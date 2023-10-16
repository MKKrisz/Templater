#include <stdio.h>

#include "src/plugin_handler.h"
#include "src/arghandler.h"

int main(int argc, char** argv){
    PluginArray* handle = PluginArray_LoadAll();
    HandleArgs(handle, argc, argv);
    return 0;
}
