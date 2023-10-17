#include <unistd.h>
#include <dirent.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#include "plugin_handler.h"

char* GetPluginPath(){
    char* home = getenv("HOME");
    int homelen = strlen(home);
    char* op = malloc(sizeof(char) * (homelen + 30));
    strcpy(op, home);
    strcat(op, "/.config/");
    strcat(op, "templater/");
    mkdir(op, 0700);
    strcat(op, "Plugins/");
    mkdir(op, 0700);
    return op;
}

PluginArray* PluginArray_Make(){
    PluginArray* op = malloc(sizeof(PluginArray));
    
    op->Elements = malloc(sizeof(Plugin));
    op->Count = 0;
    op->Capacity = 1;

    return op;
}

void PluginArray_Extend(PluginArray* arr, int size){
    arr->Elements = realloc(arr->Elements, sizeof(Plugin) * size);
    arr->Capacity = size;
}
void PluginArray_Add(PluginArray* arr, Plugin p){
    while(arr->Count >= arr->Capacity){
        PluginArray_Extend(arr, 2*arr->Capacity);
    }
    arr->Elements[arr->Count] = p;
    arr->Count++;
}

    
bool MassEnable(PluginArray* arr, const char* str){
    bool noneEnabled = true;
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].CheckEnable != NULL && (*arr->Elements[i].CheckEnable)(str)){
            arr->Elements[i].enabled = true;
            noneEnabled = false;
        }
    }
    return noneEnabled;
}

void MassPrintHelp(PluginArray* arr){
    for(int i = 0; i < arr->Count; i++){
        if(arr->Elements[i].PrintHelp != NULL){
            (*arr->Elements[i].PrintHelp)();
        }
    }
}

void CMake_MassInclusion(PluginArray* arr, FILE* f){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].enabled && arr->Elements[i].CMake_Inclusion != NULL){
            (*arr->Elements[i].CMake_Inclusion)(f);
        }
    }
}
void CMake_MassAddition(PluginArray* arr, FILE* f){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].enabled && arr->Elements[i].CMake_Addition != NULL){
            (*arr->Elements[i].CMake_Addition)(f);
        }
    }
}
void CMake_MassLinking(PluginArray* arr, FILE* f){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].enabled && arr->Elements[i].CMake_Linking != NULL){
            (*arr->Elements[i].CMake_Linking)(f);
        }
    }
}

void Main_MassInclude(PluginArray* arr, FILE* f){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].enabled && arr->Elements[i].Main_Include != NULL){
            (*arr->Elements[i].Main_Include)(f);
        }
    }
}

void Main_MassExtend_Start(PluginArray* arr, FILE* f){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].enabled && arr->Elements[i].Main_ExtendBody_Start != NULL){
            (*arr->Elements[i].Main_ExtendBody_Start)(f);
        }
    }
}

void Main_MassExtend_End(PluginArray* arr, FILE* f){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].enabled && arr->Elements[i].Main_ExtendBody_End != NULL){
            (*arr->Elements[i].Main_ExtendBody_End)(f);
        }
    }
}

void Files_MassManipulate(PluginArray* arr, const char* root_path){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].enabled && arr->Elements[i].Files_Manipulate != NULL){
            (*arr->Elements[i].Files_Manipulate)(root_path);
        }
    }
}


PluginArray* PluginArray_LoadAll(){
    PluginArray* arr = PluginArray_Make();

    char* pluginpath = GetPluginPath();
    int pplen = strlen(pluginpath);
    DIR* plugindir = opendir(pluginpath);

    //printf("%d\n", errno);

    struct dirent* entry;
    assert(plugindir != NULL);
    entry = readdir(plugindir);
    while(entry != NULL){
        if(strstr(entry->d_name, ".so") != NULL){
            int elen = strlen(entry->d_name);
            char path[elen + pplen + 1];
            strcpy(path, pluginpath);
            strcat(path, entry->d_name);
            PluginArray_Add(arr, loadPlugin(path));
        }
        entry = readdir(plugindir);
    }
    free(pluginpath);


    return arr;
}

void PluginArray_Dealloc(PluginArray* arr){
    free(arr->Elements);
    free(arr);
}
