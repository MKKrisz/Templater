#include <string.h>

#include "findMath.h"

char* GetName(){
    return "FindMath";
}
bool CheckEnable(const char* c){
    return strcmp(c, "-m") || strcmp(c, "-math");
}
void PrintHelp(){
    printf("\t-m, --math\t\tLinks the C standard math library.\n");
}
void CMake_Linking(FILE* f){
    fprintf(f, "target_link_libraries(${PROJECT_NAME} m)\n\n");
}

