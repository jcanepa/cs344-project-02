#include <stdio.h>

int main(int argc, char **argv)
{
    // argv[0] is always the function name; in this case "main"
    // thus, the first argument will be argv[1]
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}