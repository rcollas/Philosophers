#include "../philosophers.h"

int main(int argc, char **argv)
{
    if (checkInput(argc, argv) == ERROR)
        return (ERROR);
    return (0);
}