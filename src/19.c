#include <stdio.h>

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;
    unsigned int dow = 1;

    for (unsigned int year = 1900; year < 2001; ++year)
    {
        for (unsigned month = 0; month < 12; ++month)
        {
            unsigned int days = 31;

            switch (month)
            {
            case 3:
            case 5:
            case 8:
            case 10:
                days = 30;
                break;
            case 1:
                if (!(year % 4) && (year % 100 || !(year % 400)))
                    days = 29;
                else
                    days = 28;
                break;
            }

            if (year > 1900 && !dow)
                ++result;

            dow = (dow + (days % 7)) % 7;
        }
    }

    printf ("Result: %lu\n", result);

    return 0;
}
