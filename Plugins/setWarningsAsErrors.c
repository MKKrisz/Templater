#include <string.h>

#include "setWarningsAsErrors.h"

char* GetName(){
    return "SetWarningsAsErrors";
}

bool CheckEnable(const char* c){
    return strcmp(c, "-e") == 0 || strcmp(c, "-Werror") == 0;
}

void PrintHelp(){
    printf("\t-e, -Werror\t\tSets the \"-Wall -Werror\" compiler arguments");
}

void CMake_Linking(FILE* f){
    fprintf(f, "target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror)");
}
