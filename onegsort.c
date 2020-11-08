#include "text.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

const char* SKIP_SYMBOLS = "!?.,;:-_\"'«»() ";

int directStrCmp(const string* x1, const string* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);

    char* s1 = x1->p;
    char* s2 = x2->p;

    do
    {
        s1 += strspn(s1, SKIP_SYMBOLS);
        s2 += strspn(s2, SKIP_SYMBOLS);

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
        while(strspn(s1.p, SKIP_SYMBOLS)) --s1.p;
        while(strspn(s2.p, SKIP_SYMBOLS)) --s2.p;

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

