//Contents of ${PLUGIN_NAME}.h
//Comment out unused features, implement ${PLUGIN_NAME}.h accordingly
//Methods marked with * are mostly necessary to implement


#pragma once

#include <stdbool.h>
#include <stdio.h>

// * Returns the name of the plugin
char* GetName();

// * Returns wether the plugin should be enabled based on the current argument (please stick to POSIX standard)
bool CheckEnable(const char* c);

// * Prints the help entry, in the format: (without the spaces...)
// \t [FLAGS] \t\t [DESCRIPTION]
void PrintHelp();

//   Prints all the things required before the "add_executable..." line for your plugin to work
void CMake_Inclusion(FILE* f);

//   Adds header/source files to the "add_executable..." entry (in standard cmake format)
// PLEASE DON'T FORGET PUTTING LEADING SPACES
void CMake_Addition(FILE* f);

//   Prints everything that goes after "add_executable..." (so links, etc...)
void CMake_Linking(FILE* f);

//   Adds optional "#include..." lines to the main.c
void Main_Include(FILE* f);

//   Adds lines to the beginning of the main function
// MIND THE INDENTATION
void Main_ExtendBody_Start(FILE* f);

//   Adds lines to the end of the main function
// MIND THE INDENTATION
void Main_ExtendBody_End(FILE* f);

//   Do Whatever other setting-ups you need to do, like file copying, script running, etc...
void Files_Manipulate(const char* root_path);

