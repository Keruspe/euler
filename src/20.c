#include <stdio.h>

#define SIZE 200

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;
    unsigned int number[SIZE] = {0};

    number[SIZE - 1] = 1;

    for (unsigned int i = 1; i < 101; ++i)
    {
        unsigned int carry = 0;

        for (unsigned int _index = 0; _index < SIZE; ++_index)
        {
            unsigned int index = SIZE - (_index + 1);

            number[index] *= i;
            number[index] += carry;
            carry = number[index] / 10;
            number[index] %= 10;
        }
    }

    for (unsigned int i = 0; i < SIZE; ++i)
        result += number[i];

    printf ("Result: %lu\n", result);

    return 0;
}
