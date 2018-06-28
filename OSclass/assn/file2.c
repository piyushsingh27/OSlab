#include<stdio.h>
int external = 100;

static void lfunction();
static void lfunction()
{
    printf("\nStatic Function");
}
void function()
{
    printf("\nFunction");
    lfunction();
}
