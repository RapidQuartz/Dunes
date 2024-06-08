
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
int ps_argmac(int data);
int main(void)
{
    int var;
    int nix;

    var = 1;
    nix = 0;

    //ps_argument_machine(1);
    if (ps_argmac(var))
    {
        printf("nice device! %d", ps_argmac(nix));  
        return (0);
    }
    printf("no dice homeslice %d", ((ps_argmac(var))));
    printf("nice device! %d", ps_argmac(nix)); 
    return (1);
}
int ps_argmac(int data)
{
    if (!data)
        return (1);
    else
        return (0);
}