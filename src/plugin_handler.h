#pragma once

#include <stdio.h>

#include "plugin.h"

#define PLUGIN_DIR "Plugins/"


typedef struct{
    Plugin* Elements;
    int Count;
    int Capacity;
} PluginArray;

PluginArray* PluginArray_Make();
void PluginArray_Add(PluginArray* arr, Plugin p);

bool MassEnable(PluginArray* arr, const char* str);
void MassPrintHelp(PluginArray* arr);

void CMake_MassInclusion(PluginArray* arr, FILE* f);
void CMake_MassAddition(PluginArray* arr, FILE* f);
void CMake_MassLinking(PluginArray* arr, FILE* f);

void Main_MassInclude(PluginArray* arr, FILE* f);
void Main_MassExtend_Start(PluginArray* arr, FILE* f);
void Main_MassExtend_End(PluginArray* arr, FILE* f);
void Files_MassManipulate(PluginArray* arr, const char* root_path);

PluginArray* PluginArray_LoadAll();

void PluginArray_Dealloc(PluginArray* arr);
