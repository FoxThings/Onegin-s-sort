#ifndef ONEGSORT_H_INCLUDED
#define ONEGSORT_H_INCLUDED

#include "text.h"
//! @file

/*!
    Compare fileStrings directly
    @param[in] x1 first fileString pointer
    @param[in] x2 second fileString pointer

    @return if x1 > x2 return >0 else if x1 < x2 returns <0 else returns 0
    @version 1.0
    @authors Zvezdin Nikita
*/
int directStrCmp(const fileString* x1, const fileString* x2);

/*!
    Compare fileStrings inverted
    @param[in] x1 first fileString pointer
    @param[in] x2 second fileString pointer

    @return if x1 > x2 return >0 else if x1 < x2 returns <0 else returns 0
    @version 1.0
    @authors Zvezdin Nikita
*/
int inverseStrCmp(const fileString* x1, const fileString* x2);

/*!
    Sorting fileString data
    @param[in] vector collection of fileString data
    @param[in] count number of fileStrings
    @param[in] cmp pointer to cmp func

    @version 1.0
    @authors Zvezdin Nikita
*/
void stringSort(fileString* vector, int count, int (*cmp)(const void*, const void*));

#endif // ONEGSORT_H_INCLUDED
