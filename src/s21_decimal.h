#include <string.h>
#include <stdio.h>

#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

// Return values for functions.
#define S21_TRUE 1
#define S21_FALSE 0

#define CORRECT_RETURN 0
#define INCORRECT_RETURN 1

#define CONVERT_ERROR 1
#define CALCULATION_ERROR 1

#define LARGE_NUMBER_ERROR 1
#define SMALL_NUMBER_ERROR 2
#define ZERO_DIVISION_ERROR 3

// Macros for utils.
#define NUMBER_BETWEEN(number, left, right) ((number) >= (left) && (number) <= (right))
#define GET_FIRST_BIT(number) (((number) & (1 << (BITS_IN_INT-2))) >> (BITS_IN_INT-2))

// Structure for decimal. And constants.
#define INT_3_LEN sizeof(int)*3
#define INT_4_LEN sizeof(int)*4
#define BITS_IN_INT sizeof(int)*8
#define BUFF_SIZE 4

typedef struct
{
    int bits[BUFF_SIZE];
} s21_decimal;

// Access decimal exponent and sign.
#define NOT_DECIMAL 0xFFFF00FE
#define LEAD_ZERO_LEN 16
#define EXP_LEN 8
#define TRAIL_ZERO_LEN 7
#define SIGN_LEN 1
#define MIN_EXPONENT 0
#define MAX_EXPONENT 28


// Converters and parsers.
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal, int *dst);

// Arithmetic.
// ...

// Another functions.
int s21_floor(s21_decimal value, s21_decimal *result);

// Utils functions.
void s21_sum_bits(int val_1[BUFF_SIZE], int val_2[BUFF_SIZE], int res[BUFF_SIZE]);
int s21_divide_10_bits(int bits[BUFF_SIZE]);
int s21_bit_shift_buffer(int buffer[BUFF_SIZE]);
int s21_get_decimal_exp(s21_decimal number);
void s21_set_decimal_exp(s21_decimal *number, int exponent);
int s21_is_decimal(s21_decimal value);

void s21_output_bits(int *num, int len);

#endif