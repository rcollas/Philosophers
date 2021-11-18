#include "../philosophers.h"

int checkArgsNumbers(int argc)
{
    if (argc < 5 || argc > 6)
    {
        putStrFd("Please check the number of arguments.\n", STDERR_FILENO);
        return (ERROR);
    }
    return (0);
}

int checkArgsType(char **argv)
{
    size_t i;

    i = 1;
    while (argv[i])
    {
        if (isNotNumeric(argv[i]))
        {
            putStrFd("Please check that all parameters are positive int.\n", STDERR_FILENO);
            return (ERROR);
        }
        i++;
    }
    return (0);
}

int checkInput(int argc, char **argv)
{
    if (checkArgsNumbers(argc) == ERROR)
        return (ERROR);
    if (checkArgsType(argv) == ERROR)
        return (ERROR);
    return (0);
}