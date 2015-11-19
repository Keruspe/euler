#include <stdio.h>

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;
    int prev = 1, cur = 2;

    while (cur < 4000000)
    {
        if (!(cur % 2))
            result += cur;

        cur += prev;
        prev = cur - prev;
    }

    printf ("Result: %lu\n", result);

    return 0;
}
