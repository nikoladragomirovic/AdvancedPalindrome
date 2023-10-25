#include <stdio.h>
#include <inttypes.h>

#pragma CHECK_MISRA("-20.9")

#define OCTAL (uint_least8_t)8
#define DECIMAL (uint_least8_t)10
#define HEXADECIMAL (uint_least8_t)16

#define TRUE (uint_least8_t)1
#define FALSE (uint_least8_t)0

#define PALINDROME_TRESHOLD (intmax_t)0

#define PALINDROME_SUCCESS (uint_least8_t)0
#define PALINDROME_INVALID_TARGET (uint_least8_t)1
#define PALINDROME_INVALID_BASE (uint_least8_t)2

uint_least8_t print_palindromes(const intmax_t target, const uint_least8_t base);
static uint_least8_t is_palindrome(const intmax_t num, const uint_least8_t base);

static uint_least8_t is_palindrome(const intmax_t num, const uint_least8_t base)
{
    intmax_t temp = num;
    intmax_t reversed_num = PALINDROME_TRESHOLD;

    while (temp > PALINDROME_TRESHOLD)
    {
        reversed_num = reversed_num * base + (temp % base);
        temp /= base;
    }

    return num == reversed_num ? TRUE : FALSE;
}

uint_least8_t print_palindromes(const intmax_t target, const uint_least8_t base)
{
    if ((target < (intmax_t)base))
    {
        return PALINDROME_INVALID_TARGET;
    }

    if ((base != OCTAL) && (base != DECIMAL) && (base != HEXADECIMAL))
    {
        return PALINDROME_INVALID_BASE;
    }

    for (intmax_t i = (intmax_t)base; i < target; i++)
    {
        if (is_palindrome(i, base))
        {
            switch (base)
            {
            case OCTAL:
                printf("%" PRIoMAX "\n", i);
                break;
            case DECIMAL:
                printf("%" PRIdMAX "\n", i);
                break;
            case HEXADECIMAL:
                printf("%" PRIXMAX "\n", i);
                break;
            default:
                break;
            }
        }
    }
    
    return PALINDROME_SUCCESS;
}