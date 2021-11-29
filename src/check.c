#include "../include/philosophers.h"

int check_args_numbers(int argc)
{
    if (argc < 5 || argc > 6)
    {
        put_str_fd("Please check the number of arguments.\n", STDERR_FILENO);
        return (ERROR);
    }
    return (0);
}

int check_args_type(char **argv)
{
    size_t i;

    i = 1;
    while (argv[i])
    {
        if (is_not_numeric(argv[i]))
        {
            put_str_fd("Please check that all parameters are positive int.\n", STDERR_FILENO);
            return (ERROR);
        }
        i++;
    }
    return (0);
}

int check_input(int argc, char **argv)
{
    if (check_args_numbers(argc) == ERROR)
        return (ERROR);
    if (check_args_type(argv) == ERROR)
        return (ERROR);
    return (0);
}