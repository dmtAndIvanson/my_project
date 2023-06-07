#include <stdio.h>
#include <string.h>

// Defines for work with bits.
#define INT_1_ONE_MASK ~0
#define INT_4_ZERO_MASK {{0,0,0,0}}
#define INT_3_LEN 3 * sizeof(int)
#define BUFF_SIZE 4

// Function returns.
#define CORRECT_RETURN 0
#define INCORRECT_RETURN 1
#define INF_RETURN 1
#define NEG_INF_RETURN 2
#define ZERO_DIVISION 3

// True/False
#define S21_TRUE 21
#define S21_FALSE 0

// Structures.
typedef struct
{
    int bits[BUFF_SIZE];
} s21_decimal;

// Arithmetic functions.
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_sum_bits(int val_1[BUFF_SIZE], int val_2[BUFF_SIZE], int res[BUFF_SIZE]);
void s21_sub_bits(int val_1[BUFF_SIZE], int val_2[BUFF_SIZE], int res[BUFF_SIZE]);

int main(void)
{
    s21_decimal val_1 = {{0,1,~0,0}};
    s21_decimal val_2 = {{0,1,1,0}};
    s21_decimal res = INT_4_ZERO_MASK;
    s21_add(val_1, val_2,&res);
    int *ptr = (int*)(&res);
    for (int i = 0; i < BUFF_SIZE; i++)
    {
        printf("int %i: %i\n", i, ptr[i]);
    }
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
{
    // Check numbers are correct.
    // Normalize numbers.
    // Initialize long value for calculations.
    int long_value_1[BUFF_SIZE] = {0};
    int long_value_2[BUFF_SIZE] = {0};
    int long_result[BUFF_SIZE] = {0};
    // Copy significant parts to long values.
    memcpy(long_value_1+1, &value_1, INT_3_LEN);
    memcpy(long_value_2+1, &value_2, INT_3_LEN);
    // Check signs of numbers. And determine sign.
    // Sum numbers to long value.
    s21_sum_bits(long_vslue_1, long_value_2, long_result);
    // Check overflow.
    memcpy(result, long_result+1, INT_3_LEN);
    return 0;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
{
    // Check numbers are correct.
    // Normalize numbers.
    // Initialize long value for calculations.
    int long_value_1[6] = {0};
    int long_value_2[6] = {0};
    int long_result[6] = {0};                                     
    // Copy significant parts to long values.
    memcpy(long_value_1+3, &value_1, INT_3_LEN);
    memcpy(long_value_2+3, &value_2, INT_3_LEN);
    // Check signs of numbers. And determine sign.
    // Sub numbers to long value.


    memcpy(result, long_result+3, INT_3_LEN);
    // Check overflow.
    return 0;
}

void s21_sum_bits(int val_1[BUFF_SIZE], int val_2[BUFF_SIZE], int res[BUFF_SIZE])
{
    if ((val_1[0] & INT_1_ONE_MASK) < 2 && (val_2[0] & INT_1_ONE_MASK) < 2)
    {
        int setter = 1;
        int remember_bit = 0;
        for (size_t i = 3; i > 1; i--)
        {
            int tmp_res = 0;
            for (size_t j = 0; j < 8; j++)
            {
                int sum = ((val_1[i] & (setter << j)) >> j) + ((val_2[i] & (setter << j)) >> j) + remember_bit;
                tmp_res |= ((sum % 2) << j);
                remember_bit = sum > 1 ? 1 : 0;
            }
            res[i] = tmp_res;
        }
    }
}

void s21_sub_bits(int val_1[BUFF_SIZE], int val_2[BUFF_SIZE], int res[BUFF_SIZE])
{
    if ((memcmp(val_1, val_2, INT_3_LEN) >= 0) && !val_1[0])
    {
        int *add_to_ones = {0, INT_1_ONE_MASK, INT_1_ONE_MASK, INT_1_ONE_MASK};
        for (int i = 3; i > 1; i--)
        {
            add_to_ones[i] ^= val_2;
            s21_sum_bits(val_1, add_to_ones, res);
            res[0] &= 0;
        }
    }
}