#ifndef ONEGSORT_H_INCLUDED
#define ONEGSORT_H_INCLUDED

#include "text.h"
//! @file

/*!
    Compare strings directly
    @param[in] x1 first string pointer
    @param[in] x2 second string pointer

    @return if x1 > x2 return >0 else if x1 < x2 returns <0 else returns 0
    @version 1.0
    @authors Zvezdin Nikita
*/
int directStrCmp(const string* x1, const string* x2);

/*!
    Compare strings inverted
    @param[in] x1 first string pointer
    @param[in] x2 second string pointer

    @return if x1 > x2 return >0 else if x1 < x2 returns <0 else returns 0
    @version 1.0
    @authors Zvezdin Nikita
*/
int inverseStrCmp(const string* x1, const string* x2);

/*!
    Sorting string data
    @param[in] vector collection of string data
    @param[in] count number of strings
    @param[in] cmp pointer to cmp func

    @version 1.0
    @authors Zvezdin Nikita
*/
void stringSort(string* vector, int count, int (*cmp)(const void*, const void*));

#endif // ONEGSORT_H_INCLUDED
