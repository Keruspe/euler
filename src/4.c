#include <stdbool.h>
#include <stdio.h>

bool
palindrome (unsigned long number)
{
    return (((number / 100000) % 10) == (number % 10)) &&
           (((number / 10000) % 10) == ((number % 100) / 10)) &&
           (((number / 1000) % 10) == ((number % 1000) / 100));
}

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;

    for (unsigned int i = 100; i < 1000; ++i)
    {
        for (unsigned int j = i; j < 1000; ++j)
        {
            unsigned long candidate = i * j;

            if (palindrome (candidate) && candidate > result)
                result = candidate;
        }
    }

    printf ("Result: %lu\n", result);

    return 0;
}
