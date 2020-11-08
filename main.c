#include <stdio.h>
#include <stdlib.h>
#include "onegsort.h"
#include "text.h"
#include <assert.h>

#define RUN_CHECK(FUNC, OK_CODE)        \
{                                       \
    int code = FUNC;                    \
    if (code != OK_CODE) return code;   \
}

int oneginSort(const char* in, const char* out)
{
    assert(in != NULL);
    assert(out != NULL);

    char* buffer = NULL;

    RUN_CHECK(input(in, &buffer), FILE_OK);

    RUN_CHECK(clearFile(out), FILE_OK);

    int count;
    string* text = bufferParse(buffer, &count, '\n');
    if (text == NULL) return NO_MEMORY;

    stringSort(text, count, (int(*) (const void *, const void *))directStrCmp);
    RUN_CHECK(output(out, text, count), FILE_OK);

    qsort(text, count, sizeof(string), (int(*) (const void *, const void *))inverseStrCmp);
    RUN_CHECK(output(out, text, count), FILE_OK);

    RUN_CHECK(nativeOutput(out, buffer), FILE_OK);

    free(buffer);
    free(text);

    return FILE_OK;
}

int main()
{
    system("chcp 1251");
    system("cls");

    printf("-> Onegin's sort!\n");
    printf("-> Zvezdin Nikita 2020, all rights reserved(C)\n");

    const char input[] = "input.txt";
    const char output[] = "output.txt";

    int code = oneginSort(input, output);
    if (code == FILE_OK)
    {
        printf("Success!\n");
        return 0;
    }

    char* errorCode = "";
    switch(code)
    {
    case CANNOT_OPEN_FILE:
        errorCode = "Couldn't open the file :(";
        break;
    case CANNOT_READ_FILE:
        errorCode = "Couldn't read the file :/";
        break;
    case NO_MEMORY:
        errorCode = "Not enough memory :<";
        break;
    default:
        errorCode = "Something went wrong... :P";
        break;
    }

    printf("\nAn error occurred!\n\tError code: %s\n", errorCode);

    return 0;
}
