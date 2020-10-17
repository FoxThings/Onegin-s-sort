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
    size_t size;
    if ((fin = fopen(name, "r")) == NULL)
    {
        return -1;
    }

    struct stat info;
    stat(name, &info);

    *buffer = (char*) calloc(info.st_size + 2, sizeof(char));
    assert(buffer != NULL);

    size = fread(*buffer, sizeof(char), info.st_size, fin);
    assert(size > 0);

    *(*buffer + size) = '\n';
    *(*buffer + size + 1) = '\0';

    fclose(fin);
    return 0;
}

int output(const char* name, string* text, int count)
{
    assert(name != NULL);
    assert(text != NULL);
    assert(count > 0);

    FILE* fout;
    if ((fout = fopen(name, "a")) == NULL)
    {
        return -1;
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
    return 0;
}

int nativeOutput(const char* name, const char* string)
{
    assert(name != NULL);
    assert(string != NULL);

    FILE* fout;
    if ((fout = fopen(name, "a")) == NULL)
    {
        return -1;
    }

    fprintf(fout, string);

    fclose(fout);
    return 0;
}

int clearFile(const char* name)
{
    assert(name != NULL);

    FILE* fout;
    if ((fout = fopen(name, "w")) == NULL)
    {
        return -1;
    }
    fclose(fout);
    return 0;
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
    assert(text != NULL);

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
