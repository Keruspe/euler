#include <stdio.h>

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;

    for (unsigned int a = 1; a < 1000; ++a)
    {
        unsigned int asq = a * a;

        for (unsigned int b = a + 1; b < 1000; ++b)
        {
            unsigned int c = 1000 - (a + b);

            if (c <= b)
                continue;

            if ((c * c) == (asq + b * b))
            {
                result = a * b * c;
                goto result;
            }
        }
    }

result:
    printf ("Result: %lu\n", result);

    return 0;
}
