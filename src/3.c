#include <alloca.h>
#include <stdio.h>
#include <string.h>

#include "util/prime.c"

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;
    unsigned long *primes = alloca (2048 * sizeof (unsigned long));
    unsigned long number = 600851475143;
    unsigned int index = 0;

    memset (primes, 0, 2048 * sizeof (unsigned long));

    while (number != 1)
    {
        for (unsigned long i = 2; i <= number; ++i)
        {
            if (is_prime (i, primes))
            {
                result = primes[index++] = i;

                while (!(number % i))
                    number /= i;
            }
        }
    }

    printf ("Result: %lu\n", result);

    return 0;
}
