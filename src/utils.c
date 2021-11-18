#include "../philosophers.h"

size_t  strLen(char *str)
{
    size_t  len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

void putStrFd(char *str, int fd)
{
    write (fd, str, strLen(str));
}

_Bool isDigit(char c)
{
    if (c >= '0' && c <= '9')
        return (TRUE);
    return (FALSE);
}

_Bool isNotNumeric(char *str)
{
    size_t  i;

    i = -1;
    while (isDigit(str[i]))
    {
        if (str[i + 0] == '\0')
            return (FALSE);
        i++;
    }
    return (TRUE);
}
