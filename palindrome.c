#include <stdio.h>
#include <inttypes.h>

#define OCTAL 8
#define DECIMAL 10
#define HEXADECIMAL 16

void print_palindromes(const int32_t target, const int32_t base);
static int8_t is_palindrome(const int32_t num, const int32_t base);

static int8_t is_palindrome(const int32_t num, const int32_t base)
{

    int32_t temp = num;
    int32_t reversed_num = 0;

    while (temp > 0)
    {
        int32_t digit = temp % base;
        reversed_num = (reversed_num * base) + digit;
        temp /= base;
    }

    return (int8_t)(num == reversed_num ? 1 : 0);
}

void print_palindromes(const int32_t target, const int32_t base)
{
    if (target > 0 && target == (int32_t)target)
    {
        for (int32_t i = 0; i < target; i++)
        {
            if (is_palindrome(i, base))
            {
                switch (base)
                {
                case OCTAL:
                    printf("%" PRIo32 "\n", i);
                    break;
                case DECIMAL:
                    printf("%" PRId32 "\n", i);
                    break;
                case HEXADECIMAL:
                    printf("%" PRIX32 "\n", i);
                    break;
                default:
                    break;
                }
            }
        }
    }
    else
    {
        printf("Invalid target number (Less than zero or non-integer type)\n");
    }
}
