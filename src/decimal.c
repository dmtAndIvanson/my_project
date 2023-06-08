#include <stdio.h>
#include <string.h>

#include "decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
{
    int return_value = CORRECT_RETURN;
    // Check numbers are correct.
    // Check signs of numbers. And determine sign.
    if ((s21_get_decimal_sign(value_1) + s21_get_decimal_sign(value_2)) == 1)
    {
        if (s21_get_decimal_sign(value_1))
        {
            s21_decimal tmp = {0};
            memcpy(&tmp, &value_1, sizeof(s21_decimal));
            memcpy(&value_1, &value_2, sizeof(s21_decimal));
            memcpy(&value_2, &tmp, sizeof(s21_decimal));
        }
        return_value = s21_sub(value_1, value_2, result);
    }
    else
    {
        // Normalize numbers.
        // Initialize long value for calculations.
        int long_value_1[BUFF_SIZE] = {0};
        int long_value_2[BUFF_SIZE] = {0};
        int long_result[BUFF_SIZE] = {0};
        // Copy significant parts to long values.
        memcpy(long_value_1+1, &value_1, INT_3_LEN);
        memcpy(long_value_2+1, &value_2, INT_3_LEN);
        // Sum numbers to long value.
        s21_sum_bits(long_value_1, long_value_2, long_result);
        // Check overflow.
        memcpy(result, long_result+1, INT_3_LEN);
    }
    return return_value;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
{
    // Check numbers are correct.
    // Check signs of numbers. And determine sign.
    if ((s21_get_decimal_sign(value_1) + s21_get_decimal_sign(value_2)) == 1)
    {
        // Change sign.
        int *ptr = (int *)(&value_2);
        if (s21_get_decimal_sign(value_1))
        {
            ptr[3] |= 1;
        }
        else
        {
            ptr[3] ^= 1;
        }
        // Calculate sum.
        return_value = s21_add(value_1, value_2, result);
    }
    else
    {
        // Normalize numbers.
        // Initialize long value for calculations.
        int long_value_1[BUFF_SIZE] = {0};
        int long_value_2[BUFF_SIZE] = {0};
        int long_result[BUFF_SIZE] = {0};                                     
        // Copy significant parts to long values.
        memcpy(long_value_1+1, &value_1, INT_3_LEN);
        memcpy(long_value_2+1, &value_2, INT_3_LEN);
        // Sub numbers to long value.
        s21_sub_bits(long_value_1, long_value_2, long_result);
        memcpy(result, long_result+1, INT_3_LEN);
        // Check overflow.
    }
    return 0;
}

void s21_sum_bits(int val_1[BUFF_SIZE], int val_2[BUFF_SIZE], int res[BUFF_SIZE])
{
    if ((val_1[0] & INT_1_ONE_MASK) < 2 && (val_2[0] & INT_1_ONE_MASK) < 2)
    {
        int setter = 1;
        int remember_bit = 0;
        for (size_t i = BUFF_SIZE-1; i > 1; i--)
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
        int add_to_ones[] = {0, INT_1_ONE_MASK, INT_1_ONE_MASK, INT_1_ONE_MASK};
        for (int i = BUFF_SIZE-1; i > 1; i--)
        {
            add_to_ones[i] ^= val_2[i];
        }
        s21_sum_bits(val_1, add_to_ones, res);
        memcpy(add_to_ones, res, INT_4_LEN);
        int one[] = {0,0,0,1};
        s21_sum_bits(add_to_ones, one, res);
        res[0] &= 0;
    }
}

/*int s21_is_decimal(s21_decimal number)
{
    return number == 21;
}*/

void output_bits(int val)
{
    int setter = 1;
    for (size_t i = 1; i <= sizeof(int)*8; i++)
    {
        if (val & (setter << (sizeof(int)*8-i)))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}

int s21_get_decimal_sign(s21_decimal number)
{
    int answer = S21_FALSE;
    int *ptr = (int *)(&number);
    if (ptr[3] & 1)
    {
        answer = S21_TRUE;    
    }
    return answer;
}