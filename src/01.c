#include <stdio.h>

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;

    for (unsigned int i = 0; i < 1000; ++i)
    {
        if (!(i % 3) || !(i % 5))
            result += i;
    }

    printf ("Result: %lu\n", result);

    return 0;
}
