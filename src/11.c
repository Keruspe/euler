#include <stdio.h>

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;
    unsigned long candidate;
    int numbers[20][20];
    int x = 0, y = 0;
    FILE *f = fopen ("data/11", "r");
    int current = 0;
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

    for (y = 0; y < 20; ++y)
    {
        for (x = 0; x < 20; ++x)
        {
            if (x < 17)
            {
                candidate = 1;

                for (unsigned int i = 0; i < 4; ++i)
                    candidate *= numbers[y][x+i];

                if (candidate > result)
                    result = candidate;

                if (y < 17)
                {
                    candidate = 1;

                    for (unsigned int i = 0; i < 4; ++i)
                        candidate *= numbers[y+i][x+i];

                    if (candidate > result)
                        result = candidate;
                }
            }

            if (y < 17)
            {
                candidate = 1;

                for (unsigned int i = 0; i < 4; ++i)
                    candidate *= numbers[y+i][x];

                if (candidate > result)
                    result = candidate;

                if (x > 2)
                {
                    candidate = 1;

                    for (unsigned int i = 0; i < 4; ++i)
                        candidate *= numbers[y+i][x-i];

                    if (candidate > result)
                        result = candidate;
                }
            }
        }
    }

    printf ("Result: %lu\n", result);

    return 0;
}
