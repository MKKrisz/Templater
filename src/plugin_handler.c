#include "plugin_handler.h"

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

    
void MassEnable(PluginArray* arr, const char* str){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].CheckEnable != NULL && (*arr->Elements[i].CheckEnable)(str)){
            arr->Elements[i].enabled = true;
        }
    }
}

void CMake_MassInclusion(PluginArray* arr, FILE* f){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].CMake_Inclusion != NULL){
            (*arr->Elements[i].CMake_Inclusion)(f);
        }
    }
}
void CMake_MassAddition(PluginArray* arr, FILE* f){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].CMake_Addition != NULL){
            (*arr->Elements[i].CMake_Addition)(f);
        }
    }
}
void CMake_MassLinking(PluginArray* arr, FILE* f){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].CMake_Linking != NULL){
            (*arr->Elements[i].CMake_Linking)(f);
        }
    }
}

void Main_MassInclude(PluginArray* arr, FILE* f){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].Main_Include != NULL){
            (*arr->Elements[i].Main_Include)(f);
        }
    }
}

void Main_MassExtend_Start(PluginArray* arr, FILE* f){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].Main_ExtendBody_Start != NULL){
            (*arr->Elements[i].Main_ExtendBody_Start)(f);
        }
    }
}

void Main_MassExtend_End(PluginArray* arr, FILE* f){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].Main_ExtendBody_End != NULL){
            (*arr->Elements[i].Main_ExtendBody_End)(f);
        }
    }
}

void Files_MassManipulate(PluginArray* arr){
    for(int i = 0; i<arr->Count; i++){
        if(arr->Elements[i].Files_Manipulate != NULL){
            (*arr->Elements[i].Files_Manipulate)();
        }
    }
}



PluginArray* PluginArray_LoadAll(){
    PluginArray* arr = PluginArray_Make();
    //TODO: this
    return arr;
}

void PluginArray_Dealloc(PluginArray* arr){
    free(arr->Elements);
    free(arr);
}
