#include <stdio.h>

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;
    unsigned long sum = 0;
    unsigned long sqsum = 0;

    for (unsigned int i = 1; i <= 100; ++i)
    {
        sum += i;
        sqsum += i * i;
    }

    result = sum * sum - sqsum;

    printf ("Result: %lu\n", result);

    return 0;
}
