#include <stdio.h>
#include <string.h>
#include "assert.h"

inline void print_failed(const char *reason)
{
    printf(RED "  Assert Failed ! %s \n" RESET, reason);
}

void assert_str_eq(char *T1, char *T2)
{
    if (strcmp(T1, T2) == 0)
        SUCCESS;
    else
        FAIL(T1, "!=", T2);
}

void assert_str_not_eq(char *T1, char *T2)
{
    if (strcmp(T1, T2) != 0)
        SUCCESS;
    else
        FAIL(T1, " ==", T2);
}

void assert_int_eq(int T1, int T2)
{
    if (T1 == T2)
        SUCCESS;
    else
        FAIL_INT(T1, "!=", T2);
}

void assert_int_not_eq(int T1, int T2)
{
    if (T1 != T2)
        SUCCESS;
    else
        FAIL_INT(T1, "==", T2);
}

void assert_eq(int result)
{
    if (result == 1)
        SUCCESS;
    else
        FAIL("expect True", "", "actual False");
}
