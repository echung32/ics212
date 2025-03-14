#include <stdio.h>

void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{
    int num1, num2 = 10;
    char c1 = 'A';
    char c2 = 'B';
    float score1 = 20.5;
    char ca[3] = "Hi";

    printf("%p %d argc\n", &argc, argc);
    printf("%p %s argv\n", &argv, *argv);
    printf("%p %d num1\n", &num1, num1);
    printf("%p %d num2\n", &num2, num2);
    printf("%p %c c1\n", &c1, c1);
    printf("%p %c c2\n", &c2, c2);
    printf("%p %f score1\n", &score1, score1);
    printf("%p %c ca[0]\n", &ca[0], ca[0]);
    printf("%p %c ca[1]\n", &ca[1], ca[1]);
    printf("%p %c ca[2]\n", &ca[2], ca[2]);

    dummy(num2, c1, ca, score1);
   
    return 0;
}

void dummy(int x, char y, char* z, float w)
{
    x++;
    y++;
    w = w + 2.1;

    printf("%p %d x\n", &x, x);
    printf("%p %c y\n", &y, y);
    printf("%p %s z\n", &z, z);
    printf("%p %f w\n", &w, w);

    /* pause here */
}
