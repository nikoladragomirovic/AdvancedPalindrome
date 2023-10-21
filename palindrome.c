#include <stdio.h>
#include <inttypes.h>

/* can't avoid using std input/output lib so disabled MISRA-C rule */
#pragma CHECK_MISRA("-20.9")

#define OCTAL 8
#define DECIMAL 10
#define HEXADECIMAL 16

/* function prototypes to align with MISRA-C */
/* working with natural numbers, hence uint */
void print_palindromes(const uintmax_t target, const uint_least8_t base);
static uint_least8_t is_palindrome(const uintmax_t num, const uint_least8_t base);

/* uint_least8_t used since output is only either 1 or 0 to conserve memory */
/* static for compiler optimization */
/* uintmax_t used to allow as big natural numbers as possible */
/* base can only be 8, 10, 16 so used uint_least8_t to concerve memory */
/* used const since num and base will not get changed inside the function */
static uint_least8_t is_palindrome(const uintmax_t num, const uint_least8_t base)
{
    /* need temporary number to create a reverse without changing original, define reverse as 0 for now*/
    uintmax_t temp = num;
    /* MISRA-C 2004 10.1 (avoid implicit conversion of different sing/underlying type)*/
    uintmax_t reversed_num = UINTMAX_C(0);

    while (temp > UINTMAX_C(0))
    {
        /* didn't init digit outside loop to conserve memory, uint_least8_t since it only need to store one digit */
        uint_least8_t digit = UINT8_C(temp % base);
        reversed_num = (reversed_num * base) + digit;
        temp /= base;
    }
    /* cast to uint_least8_t to align with function type */
    return (uint_least8_t)(num == reversed_num ? 1 : 0);
}

/* Using unsigned int naturally takes care of negative numbers */
void print_palindromes(const uintmax_t target, const uint_least8_t base)
{
    /* check for base */
    if ((base == UINT8_C(OCTAL)) || (base == UINT8_C(DECIMAL)) || (base == UINT8_C(HEXADECIMAL)))
    {
        /* skips single digit numbers since they are always palindromes */
        for (uintmax_t i = (uintmax_t)base; i < target; i++)
        {
            if (is_palindrome(i, base))
            {
                /* opted for switch instead of lookup table since switch is simple and lookup table would take up more memory*/
                switch (base)
                {
                case UINT8_C(OCTAL):
                    printf("%" PRIoMAX "\n", i);
                    break;
                case UINT8_C(DECIMAL):
                    printf("%" PRIuMAX "\n", i);
                    break;
                case UINT8_C(HEXADECIMAL):
                    printf("%" PRIXMAX "\n", i);
                    break;
                /* default condition to account for non-defined bases */
                default:
                    break;
                }
            }
        }
    }
    else
    {
        printf("Invalid base\n");
    }
}