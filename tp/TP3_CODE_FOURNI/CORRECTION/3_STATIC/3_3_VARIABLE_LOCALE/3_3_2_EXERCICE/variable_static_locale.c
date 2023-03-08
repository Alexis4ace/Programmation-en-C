#include <stdio.h>
#include <stdlib.h>

void f_correct()
{
    static int n = 3;
    n ++;
    printf("%d\n", n);
}

void f_faux()
{
    static int n;
    n = 3;
    n ++;
    printf("%d\n", n);
}

int main()
{
    f_correct();
    f_correct();
    f_correct();

    f_faux();
    f_faux();
    f_faux();

    return EXIT_SUCCESS;
}
