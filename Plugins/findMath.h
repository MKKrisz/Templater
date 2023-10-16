#pragma once

#include <stdbool.h>
#include <stdio.h>

char* GetName();
bool CheckEnable(const char* c);
void PrintHelp();
void CMake_Inclusion(FILE* f);
// void CMake_Addition(FILE* f);
void CMake_Linking(FILE* f);
void Main_Include(FILE* f);
// void Main_ExtendBody_Start(FILE* f);
// void Main_ExtendBody_End(FILE* f);
// void Files_Manipulate();
