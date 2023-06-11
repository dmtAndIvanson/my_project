#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

// Return values for functions.
#define S21_TRUE 1
#define S21_FALSE 0

#define CORRECT_RETURN 0

// Structure for decimal. And constants.
#define BUFF_SIZE 4

typedef struct
{
    int bits[BUFF_SIZE];
} s21_decimal;

#define LEAD_ZERO_LEN 16
#define EXP_LEN 8
#define TRAL_ZERO_LEN 7
#define SIGN_LEN 1


// Converters and parsers.
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decima_to_float(s21_decimal, int *dst);

#endif