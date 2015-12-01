#include <stdio.h>

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned int numbers[100][50] = { { 0 } };
    unsigned int cur = 0;
    unsigned int index = 0;
    unsigned int result_index = 0;
    unsigned int result[55] = { 0 };

    FILE *f = fopen ("data/13", "r");
    char c;

    while ((c = fgetc (f)) != EOF)
    {
        if (c == '\n')
        {
            ++cur;
            index = 0;
            continue;
        }

        numbers[cur][index++] = c - '0';
    }

    fclose (f);

    for (index = 0; index < 50; ++index)
    {
        unsigned int real_index = 50 - (index + 1);
        result_index = real_index + 5;
        unsigned int tot = result[result_index];

        for (cur = 0; cur < 100; ++cur)
            tot += numbers[cur][real_index];

        result[result_index] = tot % 10;

        while (tot / 10)
        {
            tot /= 10;
            --result_index;
            tot += result[result_index];
            result[result_index] = tot % 10;
        }
    }

    printf ("Result: ");
    for (unsigned int i = 0; i < 10; ++i)
        printf ("%u", result[result_index + i]);
    printf ("\n");

    return 0;
}
