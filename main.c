#include "palindrome.h"

int main()
{
    int32_t target, base;

    while (1)
    {
        printf("Enter a target number (or -1 to exit): ");
        scanf("%" SCNd32, &target);

        if (target == -1)
        {
            break;
        }

        printf("Enter the base (8 for octal, 10 for decimal, 16 for hexadecimal): ");
        scanf("%" SCNd32, &base);

        print_palindromes(target, base);
    }

    return 0;
}