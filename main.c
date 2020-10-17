#include <stdio.h>
#include <stdlib.h>
#include "onegsort.h"

int main()
{
    system("chcp 1251");
    system("cls");

    printf("-> Onegin's sort!\n");
    printf("-> Zvezdin Nikita 2020, all rights reserved(C)\n");

    const char input[] = "input.txt";
    const char output[] = "output.txt";

    oneginSort(input, output);

    return 0;
}
