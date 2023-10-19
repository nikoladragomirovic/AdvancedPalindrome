#include <stdio.h>
#include <inttypes.h>

#define OCTAL 8
#define DECIMAL 10
#define HEXADECIMAL 16

static void print_palindromes(const int32_t, const int32_t);
static int8_t is_palindrome(const int32_t, const const int32_t);

static int8_t is_palindrome(const int32_t num, const int32_t base)
{

    int32_t temp = num;
    int32_t reversed_num = 0;

    while (temp > 0)
    {
        int32_t digit = temp % base;
        reversed_num = reversed_num * base + digit;
        temp /= base;
    }

    return num == reversed_num ? 1 : 0;
}

static void print_palindromes(const int32_t target, const int32_t base)
{
    if (target <= 0)
    {
        printf("Target number must be greater than 0.\n");
        return; 
    }

    const char *format_string = (base == DECIMAL) ? "%" PRId32 "\n" :
                                (base == HEXADECIMAL) ? "%" PRIX32 "\n" :
                                (base == OCTAL) ? "%" PRIo32 "\n" : "\n";

    for (int32_t i = 0; i < target; i++)
    {
        if (is_palindrome(i, base))
        {
            printf(format_string, i);
        }
    }
}

int main()
{
    int32_t target = 200000;

    print_palindromes(target, OCTAL);

    return 0;
}
