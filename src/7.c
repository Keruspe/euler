#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool
is_prime (unsigned long number, unsigned long *primes)
{
    for (unsigned long *i = primes; *i; ++i)
    {
        if (!(number % *i))
            return false;
    }

    return true;
}

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;
    unsigned long *primes = malloc (10001 * sizeof (unsigned int));
    unsigned int index = 0;

    memset (primes, 0, 10001 * sizeof (unsigned int));

    for (unsigned long i = 2; !result; ++i)
    {
        if (is_prime (i, primes))
        {
            if (index == 10000)
                result = i;
            else
                primes[index++] = i;
        }
    }

    free (primes);

    printf ("Result: %lu\n", result);

    return 0;
}
