#include <stdio.h>

#define SIZE 350

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;
    unsigned int number[SIZE] = { 0 };

    number[SIZE - 1] = 1;

    for (unsigned int i = 1; i <= 1000; ++i)
    {
        unsigned int r = 0;
        for (unsigned int j = 0; j < SIZE; ++j)
        {
            unsigned int index = SIZE - (j + 1);
            unsigned int tmp = number[index] * 2 + r;
            
            r = tmp / 10;
            number[index] = tmp % 10;
        }
    }

    for (unsigned int i = 0; i < SIZE; ++i)
        result += number[i];

    printf ("Result: %lu\n", result);

    return 0;
}
