#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "includeDebugmalloc.h"

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

char* GetName(){
    return "IncludeDebugmalloc";
}

bool CheckEnable(const char* c){
    return strcmp(c, "-d") == 0 || strcmp(c, "--debugMalloc") == 0;
}

void PrintHelp(){
    printf("\t-d, -debugMalloc\tIncludes the debugmalloc.h header file into the project\n");
}

void CMake_Addition(FILE* f){
    fprintf(f, " debugmalloc.h");
}

void Main_Include(FILE* f){
    fprintf(f, "#include \"debugmalloc.h\"\n");
}

void Copy(const char* srcpath, const char* dstpath);

void Files_Manipulate(const char* root_path){
    int rpLen = strlen(root_path);
    char dstpath[rpLen + 15];
    strcpy(dstpath, root_path);
    strcat(dstpath, "/debugmalloc.h");

    char* pp = GetPluginPath();
    int pplen = strlen(pp);
    char dmp[pplen + 15];
    strcpy(dmp, pp); strcat(dmp, "debugmalloc.h");
    Copy(dmp, dstpath);

    free(pp);
}

void Copy(const char* srcpath, const char* dstpath){
    FILE* src = fopen(srcpath, "r");
    FILE* dst = fopen(dstpath, "a");
    printf("%d", errno);

    char c = fgetc(src);
    while(c != EOF){
        fputc(c, dst);
        c = fgetc(src);
    }

    fclose(src);
    fclose(dst);
}
