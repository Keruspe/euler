#include <stdio.h>

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;
    unsigned long candidate = 1;
    unsigned int index = 0;
    char numbers[13];
    char c;
    FILE *f = fopen ("data/08", "r");

    while ((c = fgetc (f)) != EOF)
    {
        if (c < '0' || c > '9')
            continue;

        char val = c - '0';

        if (!val)
        {
            candidate = 1;
            index = 0;
            continue;
        }

        char old = numbers[index % 13];
        numbers[index++ % 13] = val;
        candidate *= val;

        if (index < 13)
            continue;

        if (index > 13)
            candidate /= old;

        if (candidate > result)
            result = candidate;
    }

    fclose (f);

    printf ("Result: %lu\n", result);

    return 0;
}
