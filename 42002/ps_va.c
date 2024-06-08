//it begins

//first a little inclusion strategy to bring arguments to bear
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
//TODO:put into separate .h file


//function definitions
int ps_va(va_list args, char *format);
int ps_va_util(char *str, int num);

//the old timer
void main(void)
{
    int i;
    va_list args;

    i = 0;

    while (i < 10)
    {
        printf("Test index %d", i);
        i++;
    }
    ps_va()
    return;
}