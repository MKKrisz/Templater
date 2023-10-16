#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Plugin{
    char* name;
    void* handle;
    bool enabled;
    bool (*CheckEnable)(const char* c);
    void (*CMake_Inclusion)(FILE* f);
    void (*CMake_Addition)(FILE* f);
    void (*CMake_Linking)(FILE* f);
    void (*Main_Include)(FILE* f);
    void (*Main_ExtendBody_Start)(FILE* f);
    void (*Main_ExtendBody_End)(FILE* f);
    void (*Files_Manipulate)();
} Plugin;

Plugin loadPlugin(const char* path);