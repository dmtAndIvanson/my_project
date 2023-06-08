#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

// Defines for work with bits.
#define INT_1_ONE_MASK ~0
#define INT_4_ZERO_MASK {{0,0,0,0}}
#define INT_3_LEN 3 * sizeof(int)
#define INT_4_LEN 4 * sizeof(int)
#define BUFF_SIZE 4

// Function returns.
#define CORRECT_RETURN 0
#define INCORRECT_RETURN 1
#define INF_RETURN 1
#define NEG_INF_RETURN 2
#define ZERO_DIVISION 3

// True/False
#define S21_TRUE 1
#define S21_FALSE 0

// Structures.
typedef struct
{
    int bits[BUFF_SIZE];
} s21_decimal;

// Arithmetic functions.
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Additional functions.
void s21_sum_bits(int val_1[BUFF_SIZE], int val_2[BUFF_SIZE], int res[BUFF_SIZE]);
void s21_sub_bits(int val_1[BUFF_SIZE], int val_2[BUFF_SIZE], int res[BUFF_SIZE]);
int s21_is_decimal(s21_decimal number);
int s21_get_decimal_sign(s21_decimal number);
void output_bits(int val);

#endif