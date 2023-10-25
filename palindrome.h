#ifndef PALINDROME_H
#define PALINDROME_H

#include <stdio.h>
#include <inttypes.h>

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

#endif
