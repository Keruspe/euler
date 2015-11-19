#include <stdio.h>

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned int numbers[15][15];
    unsigned int x = 0, y = 0;
    FILE *f = fopen ("data/18", "r");
    unsigned int current = 0;
    char c;

    while ((c = fgetc (f)) != EOF)
    {
        if (c == ' ' || c == '\n')
        {
            numbers[y][x] = current;
            current = 0;
            if (c == ' ')
            {
                ++x;
            }
            else
            {
                ++y;
                x = 0;
            }
            continue;
        }

        current *= 10;
        current += c - '0';
    }

    fclose (f);

    for (y = 14; y; --y)
    {
        for (x = 0; x < y; ++x)
        {
            unsigned int n1 = numbers[y][x];
            unsigned int n2 = numbers[y][x+1];
            unsigned int max = (n1 > n2) ? n1 : n2;

            numbers[y-1][x] += max;
        }
    }

    printf ("Result: %u\n", numbers[0][0]);

    return 0;
}
