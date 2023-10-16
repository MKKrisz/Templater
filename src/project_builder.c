#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#include "project_builder.h"

char* BaseCMakePath = "/CMakeLists.txt";
char* BaseMainPath = "/main.c";
char* BaseBuildDir = "/build/";

void MakeCMake(PluginArray* arr, FILE* f, const char* projName){
    if(f == NULL) return;

    fprintf(f, "cmake_minimum_required(VERSION 3.25)\n"
               "project(%s C)\n"
               "\n"
               "set(CMAKE_C_STANDARD 99)\n"
               "\n", projName);

    CMake_MassInclusion(arr, f);
    
    fprintf(f, "add_executable(${PROJECT_NAME} main.c");
    CMake_MassAddition(arr, f);
    fprintf(f, ")\n");

    CMake_MassLinking(arr, f);

}

void MakeMain(PluginArray* arr, FILE* f){
    if(f == NULL) return;

    fprintf(f, "#include <stdio.h>\n");
    Main_MassInclude(arr, f);
    
    fprintf(f, "\n"
               "int main(void){\n");
    Main_MassExtend_Start(arr, f);

    //TODO: Make this one line a plugin aswell
    fprintf(f, "    printf(\"Hello World!\")\n");
    Main_MassExtend_End(arr, f);
    fprintf(f, "    return 0;\n"
               "}\n");
}

void BuildProject(PluginArray* arr, const char* name){
    
    //Create project root dir
    struct stat st = {0};
    if(stat(name, &st) != -1) {
        printf("Project root directory could not be made!");
        return;
    }
    mkdir(name, 0700);
    
    int pnLen = strlen(name);
    char CMakePath[pnLen + 17];
    char MainPath[pnLen + 7];
    char BuildDir[pnLen + 7];

    strcpy(CMakePath, name);
    strcpy(MainPath, name);
    strcpy(BuildDir, name);

    strcat(CMakePath, BaseCMakePath);
    strcat(MainPath, BaseMainPath);
    strcat(BuildDir, BaseBuildDir);

    FILE* CMake = fopen(CMakePath, "w");
    FILE* Main = fopen(MainPath, "w");

    MakeCMake(arr, CMake, name);
    MakeMain(arr, Main);
    mkdir(BuildDir, 0700);

    fclose(Main);
    fclose(CMake);

    Files_MassManipulate(arr, name);

    chdir(BuildDir);
    system("cmake ..");

}
