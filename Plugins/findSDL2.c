#include <string.h>

#include "findSDL2.h"

char* GetName(){
    return "FindSDL2";
}

bool CheckEnable(const char* c){
    return strcmp(c, "-S") || strcmp(c, "--SDL2");
    
}

void PrintHelp(){
    printf("\t-S, --SDL\t\tSets up a simple SDL project\n");
}

void CMake_Inclusion(FILE* f){
    fprintf(f, "#SDL inclusion on arch\n"
               "find_package(SDL2, REQUIRED)\n"
               "find_package(SDL2_image, REQUIRED)\n"
               "find_package(SDL2_ttf)\n"
               "include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})\n\n"
               );
}

void CMake_Linking(FILE* f){
    fprintf(f, "#SDL linking\n"
               "target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)\n\n"
               );
}

