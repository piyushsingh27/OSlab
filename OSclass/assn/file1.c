#include<stdio.h>
int external;               //
int fglobal = 10;           //data (initialised global)
int internal;               
int ninternal = 0;          //bss  (equivalent to uninitialised (but not extern) global)

static int variable;        //bss  (uninitialised static variable)
static int svariable = 0;   //bss  (equivalent to uninitialised static variable)
static int ivariable = 10;  //data (initialised static variable)

static void lfunction();     
void function();
void scope_function();

int main()
{
    int local;              // no where before loading
    register int reg;       // no where before loading
    static int slocal = 50; // data (initialised static variable)
    printf("External variable : %d",external);
    printf("\nInternal variable : %d",internal);
    function();             // it expects the body to be in some other file
    lfunction();            // lfunction is static and so the body can't be anywhere else except in this file
}

void scope_function()
{
    //printf("Local = %d",local);
    //printf("Register = %d"reg);
    printf("Global variable : %d",external);
    //printf("Static local = %d",slocal);
    printf("Static global(to the file) = %d",variable);
}