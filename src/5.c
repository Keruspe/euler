#include <stdbool.h>
#include <stdio.h>

bool
ok (unsigned long number)
{
    for (unsigned int i = 20; i > 1; --i)
    {
        if (number % i)
            return false;
    }

    return true;
}

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 2520;

    while (!ok (++result));

    printf ("Result: %lu\n", result);

    return 0;
}
