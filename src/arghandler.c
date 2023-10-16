#include <assert.h>
#include <string.h>

#include "arghandler.h"

void HandleArgs(PluginArray* arr, int argc, char** argv){
    assert(argc >= 1);

    for(int i = 1; i < argc; i++){
        char* arg = argv[i];
        if(strcmp(arg, "-h") || strcmp(arg, "--help")){
            printf("USAGE: templater [flags] [project name]\n"
                   "FLAGS:\n"
                   "\t-h, --help\t\tPrint this message\n");
            MassPrintHelp(arr);
            printf("\n");
        }
        else MassEnable(arr, argv[i]);
    }
}
