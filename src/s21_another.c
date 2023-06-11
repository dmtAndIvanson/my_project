#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result)
{
    int return_value = CALCULATION_ERROR;
    if (result && s21_is_decimal(value))
    {
        int exponent = s21_get_decimal_exp(value);
        if (NUMBER_BETWEEN(exponent, MIN_EXPONENT, MAX_EXPONENT))
        {
            return_value = CORRECT_RETURN;
            int *ptr = (int *)(&value);
            int buffer[BUFF_SIZE] = {0};
            memcpy(buffer+1, ptr, INT_3_LEN);
            for (int i = exponent; i > 0; i--)
            {
                s21_divide_10_bits(buffer);
            }
            if (exponent > 1 && ptr[2] > 1 && (ptr[3] & 1))
            {
                int one[BUFF_SIZE] = {0,0,0,1};
                int floor[BUFF_SIZE] = {0};
                s21_sum_bits(buffer, one, floor);
                memcpy(buffer, floor, INT_4_LEN);
            }
            memcpy(result, buffer+1, INT_3_LEN);
            int *ptr_2 = (int *)result;
            ptr_2[3] = 0;
            ptr_2[3] = (ptr[3] & 1);
        }
    }
    return return_value;
}

int s21_is_decimal(s21_decimal value)
{
    int return_value = S21_TRUE;
    int *ptr = (int *)(&value);
    if (ptr[3] & NOT_DECIMAL)
        return_value = S21_FALSE;
    return return_value;
}