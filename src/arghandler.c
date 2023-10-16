#include <assert.h>
#include <string.h>

#include "arghandler.h"

char* HandleArgs(PluginArray* arr, int argc, char** argv){
    assert(argc >= 1);
    char* retstr = "";
    for(int i = 1; i < argc; i++){
        char* arg = argv[i];
        if(strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0){
            printf("USAGE: templater [flags] [project name]\n"
                   "FLAGS:\n"
                   "\t-h, --help\t\tPrint this message\n");
            MassPrintHelp(arr);
            printf("\n");
        }
        else if(MassEnable(arr, argv[i])){
            retstr = argv[i];
        }
    }
    return retstr;
}
