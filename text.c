#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <malloc.h>
#include "text.h"
#include <assert.h>

int input(const char* name, char** buffer)
{
    assert(name != NULL);
    assert(buffer != NULL);

    FILE* fin;
    if ((fin = fopen(name, "r")) == NULL)
    {
        return CANNOT_OPEN_FILE;
    }

    struct stat info;
    if(stat(name, &info)) return CANNOT_OPEN_FILE;

    *buffer = (char*) calloc(info.st_size + 2, sizeof(char));
    if (buffer == NULL)
        return NO_MEMORY;

    size_t size = fread(*buffer, sizeof(char), info.st_size, fin);
    if (size < 0)
        return CANNOT_READ_FILE;

    *(*buffer + size) = '\n';
    *(*buffer + size + 1) = '\0';

    fclose(fin);
    return FILE_OK;
}

int output(const char* name, string* text, int count)
{
    assert(name != NULL);
    assert(text != NULL);
    assert(count > 0);

    FILE* fout;
    if ((fout = fopen(name, "a")) == NULL)
    {
        return CANNOT_OPEN_FILE;
    }

    for (int i = 0; i < count; ++i)
    {
        char* temp = text[i].p;
        while(*temp != '\n')
        {
            fputc(*temp, fout);
            ++temp;
        }
        fputc('\n', fout);
    }

    fputc('\n', fout);
    fclose(fout);
    return FILE_OK;
}

int nativeOutput(const char* name, const char* string)
{
    assert(name != NULL);
    assert(string != NULL);

    FILE* fout;
    if ((fout = fopen(name, "a")) == NULL)
    {
        return CANNOT_OPEN_FILE;
    }

    fprintf(fout, string);

    fclose(fout);
    return FILE_OK;
}

int clearFile(const char* name)
{
    assert(name != NULL);

    FILE* fout;
    if ((fout = fopen(name, "w")) == NULL)
    {
        return CANNOT_OPEN_FILE;
    }
    fclose(fout);
    return FILE_OK;
}

string* bufferParse(char* buffer, int* count, char symbol)
{
    assert(buffer != NULL);
    assert(count != NULL);

    char *p = buffer;
    *count = 0;

    while((p = strchr(p, symbol)) != NULL)
    {
        while(*p == symbol)
            ++p;
         ++(*count);
    }

    string* text = (string*) calloc(*count, sizeof(string));
    if (text == NULL)
        return NULL;

    p = buffer;
    char* last;
    size_t length;
    for (int i = 0; i < *count; ++i)
    {
        (text + i)->p = p;
        last = p;

        p = strchr(p, symbol);
        length = p - last;
        (text + i)->length = length;

        while(*p == symbol)
            ++p;
    }

    return text;
}
