#include <alloca.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
is_prime (unsigned int number, unsigned int *primes)
{
    for (unsigned int *i = primes; *i; ++i)
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
    unsigned int *primes = alloca (2048 * sizeof (unsigned int));
    unsigned long number = 600851475143;
    unsigned int index = 0;

    memset (primes, 0, 2048 * sizeof (unsigned int));

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
