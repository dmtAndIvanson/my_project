#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst)
{
    int return_value = CONVERT_ERROR;
    if (dst)
    {
        return_value = CORRECT_RETURN;
        int *dst_ = (int *)dst;
        int result[BUFF_SIZE] = {0};
        if (src < 0)
        {
            int one[BUFF_SIZE] = {0,0,0,1};
            int number[BUFF_SIZE] = {0};
            number[3] = (~src);
            s21_sum_bits(number, one, result);
            dst_[3] |= 1;
        }
        else
        {
            result[3] = src;
        }
        memcpy(dst, result+1, INT_3_LEN);
    }
    return return_value;
}

/*int s21_from_decimal_to_int(s21_decimal src, int *dst)
{
    int return_value = CONVERT_ERROR;
    // Check decimal is correct.
    if (dst)
    {
        // Convert decimal to 0 exponent, including rounding.
        // Check value can be stored in int type.
        // Copy value to integer.
        // Include sign logic.
    }
    return return_value;
}*/