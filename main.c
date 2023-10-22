#include "palindrome.h"

int main()
{
    uintmax_t target;
    uint_least8_t base;

    while (1)
    {

        printf("\nEnter a target number: ");
        if (scanf(" %" SCNiMAX, &target) != 1)
        {
            printf("Invalid input for target.\n");
            return 1;
        }

        printf("\nEnter the base: ");
        if (scanf(" %" SCNuLEAST8, &base) != 1)
        {
            printf("Invalid input for base.\n");
            return 1;
        }

        print_palindromes(target, base);
    }

    return 0;
}