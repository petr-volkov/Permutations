//
// Created by petr_v on 30/11/2015.
//


#include "str2int.h"
#include <sys/errno.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

STR2INT_ERROR str2int(long int &i, char const *s, int base)
{
    char *end;
    long  l;
    errno = 0;
    l = strtol(s, &end, base);
    if ((errno == ERANGE && l == LONG_MAX) || l > LONG_MAX) {
        return STR2INT_OVERFLOW;
    }
    if ((errno == ERANGE && l == LONG_MIN) || l < LONG_MIN) {
        return STR2INT_UNDERFLOW;
    }
    if (*s == '\0') { //  || *end != '\0') { - this doesn't work (in windows maybe?) I don't know why, no time for this now.
        return STR2INT_INCONVERTIBLE;
    }
    i = l;
    return STR2INT_SUCCESS;
}