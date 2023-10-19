#ifndef PALINDROME_H
#define PALINDROME_H

#include <stdio.h>
#include <inttypes.h>

#define OCTAL 8
#define DECIMAL 10
#define HEXADECIMAL 16

void print_palindromes(const int32_t target, const int32_t base);
static int8_t is_palindrome(const int32_t num, const int32_t base);

#endif