#pragma once

#include <stdio.h>

#include "plugin_handler.h"

void MakeCMake(PluginArray* arr, FILE* f, const char* projName);
void MakeMain(PluginArray* arr, FILE* f);

void BuildProject(PluginArray* arr, const char* name);
