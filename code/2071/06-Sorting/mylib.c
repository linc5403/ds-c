/*
 * ============================================================================
 *
 *       Filename:  mylib.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/18/2020 03:58:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%4d", a[i]);
    printf("\n");
}


#include "mylib.h"
