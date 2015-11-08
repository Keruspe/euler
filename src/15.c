#include <stdio.h>

#define MAX 20

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long previous[MAX + 1];

    for (unsigned int i = 0; i <= MAX; ++i)
        previous[i] = 1;

    for (unsigned int i = 1; i <= MAX; ++i)
    {
        for (unsigned int j = 1; j <= MAX; ++j)
            previous[j] += previous[j - 1];
    }
    
    printf ("Result: %lu\n", previous[MAX]);

    return 0;
}
