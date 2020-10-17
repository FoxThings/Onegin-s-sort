#include "text.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int punctCheck(char c)
{
    if (c == '!' || c == '?' || c == '.' || c == '"' || c == ':' || c == '—' || c == ',' || c == ';' || c == '»' || c == '«' || c == '(' || c == ')' || c == ' ')
        return 1;
    return 0;
}

int directStrCmp(const string* x1, const string* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);

    char* s1 = x1->p;
    char* s2 = x2->p;

    do
    {
        while(punctCheck(*s1)) ++s1;
        while(punctCheck(*s2)) ++s2;

        if (*s1 == '\n')
            return 0;

        if (*s1 == *s2)
        {
            ++s1;
            ++s2;
        }

    } while(*s1 == *s2);

    return (unsigned char)*s1 - (unsigned char)*s2;
}

int inverseStrCmp(const string* x1, const string* x2)
{
   assert(x1 != NULL);
   assert(x2 != NULL);

    string s1 = *x1;
    string s2 = *x2;

    s1.p += s1.length - 1;
    s2.p += s2.length - 1;

    do
    {
        while(punctCheck(*(s1.p))) --s1.p;
        while(punctCheck(*(s2.p))) --s2.p;

        if (*(s1.p) == '\n')
            return 0;

        if ((*(s1.p) == *(s2.p)))
        {
            --s1.p;
            --s2.p;
        }

    } while (*(s1.p) == *(s2.p));

    return (unsigned char)*(s1.p) - (unsigned char)*(s2.p);
}

void stringSort(string* vector, int count, int (*cmp)(const void*, const void*))
{
    assert(vector != NULL);
    assert(count > 0);

    for(int i = 0; i < count -1; ++i)
        for(int j = i; j < count; ++j)
        {
            if (cmp(vector + i, vector + j) > 0)
            {
                string temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }

}

void oneginSort(const char* in, const char* out)
{
    assert(in != NULL);
    assert(out != NULL);

    char* buffer = NULL;

    assert(!input(in, &buffer));
    assert(!clearFile(out));

    int count;
    string* text = bufferParse(buffer, &count, '\n');

    stringSort(text, count, (int(*) (const void *, const void *))directStrCmp);
    assert(!output(out, text, count));

    qsort(text, count, sizeof(string), (int(*) (const void *, const void *))inverseStrCmp);
    assert(!output(out, text, count));

    assert(!nativeOutput(out, buffer));

    free(buffer);
    free(text);
}

