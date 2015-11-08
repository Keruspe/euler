#include <stdio.h>

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;
    unsigned long longest = 0;
    
    for (unsigned long i = 1; i < 1000000; ++i)
    {
        unsigned long length = 1;

        for (unsigned long j = i; j != 1; ++length)
        {
            if (j % 2)
                j = 3 * j + 1;
            else
                j /= 2;
        }

        if (length >= longest)
        {
            longest = length;
            result = i;
        }
    }

    printf ("Result: %lu\n", result);

    return 0;
}
