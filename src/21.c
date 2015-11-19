#include <stdio.h>

unsigned int
d (unsigned int a)
{
    unsigned int sum = 0;

    for (unsigned int i = 1; i <= a/2; ++i)
    {
        if (!(a % i))
            sum += i;
    }

    return sum;
}

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;

    for (unsigned int a = 1; a < 10001; ++a)
    {
        unsigned int b = d (a);

        if (b <= a)
            continue;

        if (d (b) == a)
            result += a + b;
    }

    printf ("Result: %lu\n", result);

    return 0;
}
