#include <stdio.h>
#include <string.h>

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    unsigned long result = 0;
    const char *names[] = {
#include "../data/22"
    };
    unsigned int nb_names = sizeof(names)/sizeof(*names);

    for (unsigned int i = 0; i < nb_names; ++i)
    {
        for (unsigned int j = 0; j < nb_names - 1; ++j)
        {
            if (strcmp (names[j], names[j + 1]) > 0)
            {
                const char *tmp = names[j];

                names[j] = names[j + 1];
                names[j + 1] = tmp;
            }
        }
    }

    for (unsigned int i = 0; i < nb_names; ++i)
    {
        const char *name = names[i];
        size_t len = strlen (name);

        for (unsigned int j = 0; j < len; ++j)
            result += (name[j] - 'A' + 1) * (i + 1);
    }

    printf ("Result: %lu\n", result);

    return 0;
}
