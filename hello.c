#include <stdio.h>

int main(void)
{
    int x = 12;
    float y = 3.14;
    printf("x is %d, y is %f\n", x, y);

    char *s = "Hello, world!";
    printf("%s\n", s);

    for (int i = 0; i < 5; i++)
    {
        int product = 5 * i;
        printf("%d x 5 = %d\n", i, product);
    }
}