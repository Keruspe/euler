#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool
is_prime (unsigned long number, unsigned long *primes)
{
    unsigned long sq = (unsigned long) sqrt (number);

    for (unsigned long *i = primes; *i && *i <= sq; ++i)
    {
        if (!(number % *i))
            return false;
    }

    return true;
}

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result;
    unsigned long *primes = malloc (150000 * sizeof (unsigned long));
    unsigned int index = 0;

    memset (primes, 0, 150000 * sizeof (unsigned long));
    result = primes[index++] = 2;

    for (unsigned long i = 3; i < 2000000; i += 2)
    {
        if (is_prime (i, primes))
        {
            primes[index++] = i;
            result += i;
        }
    }

    free (primes);

    printf ("Result: %lu\n", result);

    return 0;
}
