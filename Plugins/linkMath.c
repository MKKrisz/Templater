#include <string.h>

#include "linkMath.h"

char* GetName(){
    return "LinkMath";
}
bool CheckEnable(const char* c){
    return strcmp(c, "-m") == 0 || strcmp(c, "-math") == 0;
}
void PrintHelp(){
    printf("\t-m, --math\t\tLinks the C standard math library.\n");
}
void CMake_Linking(FILE* f){
    fprintf(f, "target_link_libraries(${PROJECT_NAME} m)\n\n");
}

