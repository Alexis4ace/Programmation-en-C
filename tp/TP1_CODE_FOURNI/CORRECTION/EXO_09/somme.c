#include <stdio.h>
#include <stdlib.h>

float somme(float a, float b)
{
    return a+b;
}

int main()
{
    float a = 1.12032003;
    float b = 2.02127003;
    printf("%g\n", somme(a, b));

    return EXIT_SUCCESS;
}
