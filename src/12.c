#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 3;

    for (unsigned long i = 3; ; ++i)
    {
        result += i;

        unsigned int nb_div = 0;
        unsigned long sq = (unsigned long) sqrt (result);

        for (unsigned int j = 1; j <= sq; ++j)
        {
            if (!(result % j))
            {
                nb_div += 2;

                if (sq * sq == result)
                    --nb_div;
            }
        }

        if (nb_div > 500)
            break;
    }

    printf ("Result: %lu\n", result);

    return 0;
}
