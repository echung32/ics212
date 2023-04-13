#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, *pa;

    pa = &a;
    *pa = 7;

    /* Print the value of a here */
    printf("%d\n", a);
    
    return 0;
}

