#include <math.h>
#include <stdbool.h>

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
