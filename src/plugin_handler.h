#pragma once

#include <stdio.h>

#include "plugin.h"


typedef struct{
    Plugin* Elements;
    int Count;
    int Capacity;
} PluginArray;

PluginArray* PluginArray_Make();
void PluginArray_Add(PluginArray* arr, Plugin p);

void MassEnable(PluginArray* arr, const char* str);
void CMake_MassInclusion(PluginArray* arr, FILE* f);
void CMake_MassAddition(PluginArray* arr, FILE* f);
void CMake_MassLinking(PluginArray* arr, FILE* f);

void Main_MassInclude(PluginArray* arr, FILE* f);
void Main_MassExtend_Start(PluginArray* arr, FILE* f);
void Main_MassExtend_End(PluginArray* arr, FILE* f);
void Files_MassManipulate(PluginArray* arr);

PluginArray* PluginArray_LoadAll();

void PluginArray_Dealloc(PluginArray* arr);
