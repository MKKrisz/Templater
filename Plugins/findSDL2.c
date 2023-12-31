#include <string.h>
#include <stdlib.h>

#include "findSDL2.h"

bool IsArchBased = true;

char* GetName(){
    if(system("pacman -V") == -1) IsArchBased = false;;
    return "FindSDL2";
}

bool CheckEnable(const char* c){
    return strcmp(c, "-S") == 0 || strcmp(c, "--SDL2") == 0;
    
}

void PrintHelp(){
    printf("\t-S, --SDL\t\tSets up a simple SDL project\n");
}

void CMake_Inclusion(FILE* f){
    fprintf(f, "find_package(SDL2 REQUIRED)\n"
               "find_package(SDL2_image REQUIRED)\n"
               "find_package(SDL2_ttf)\n"
               "include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})\n\n"
               );
}

void CMake_Linking(FILE* f){
    if(IsArchBased) 
        fprintf(f, "target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)\n\n");
    else
        fprintf(f, "target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})\n\n");
}

