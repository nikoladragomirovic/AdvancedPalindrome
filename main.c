#include "palindrome.h"

int main()
{
    intmax_t target = PALINDROME_TRESHOLD;
    uint_least8_t base = DECIMAL;

    while (TRUE)
    {
        printf("\nEnter a target number: \n");
        scanf(" %" SCNiMAX, &target);

        printf("\nEnter the base: \n");
        scanf(" %" SCNuLEAST8, &base);

        uint_least8_t result = print_palindromes(target, base);

        switch (result)
        {
        case PALINDROME_SUCCESS:
            printf("Palindrome(s) found.\n");
            break;
        case PALINDROME_INVALID_TARGET:
            printf("Invalid target (must be a natural number).\n");
            break;
        case PALINDROME_INVALID_BASE:
            printf("Invalid base (must be 8, 10 or 16).\n");
            break;
        default:
            printf("Unknown error.\n");
            break;
        }
    }

    return 0;
}
