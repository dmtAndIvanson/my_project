#include "s21_decimal.h"

void s21_sum_bits(int val_1[BUFF_SIZE], int val_2[BUFF_SIZE], int res[BUFF_SIZE])
{
    int min = 0;
    int max = 66;
    if (val_1 && val_2 && NUMBER_BETWEEN(val_1[0], min, max) && NUMBER_BETWEEN(val_2[0], min, max))
    {
        int setter = 1;
        int remember_bit = 0;
        for (int i = BUFF_SIZE-1; i >= 0; i--)
        {
            int tmp_res = 0;
            for (size_t j = 0; j < BITS_IN_INT-1; j++)
            {
                int sum = ((val_1[i] & (setter << j)) >> j) + ((val_2[i] & (setter << j)) >> j) + remember_bit;
                tmp_res |= ((sum % 2) << j);
                remember_bit = sum > 1 ? 1 : 0;
            }
            res[i] = tmp_res;
        }
    }
}

int s21_divide_10_bits(int bits[BUFF_SIZE])
{
    int return_value = INCORRECT_RETURN;
    if (bits)
    {
        return_value = CORRECT_RETURN;
        int dividend = 0;
        int divisor = 10;
        int result[BUFF_SIZE] = {0};
        for (int i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < BITS_IN_INT-1; j++)
            {
                // Make bit shift.
                dividend |= s21_bit_shift_buffer(bits);
                s21_bit_shift_buffer(result);
                if (dividend >= divisor)
                {
                    dividend %= 10;
                    result[3] |= 1;
                }
                dividend <<= 1;
            } 
        }
        memcpy(bits, result, INT_4_LEN);
    }
    return return_value;
}

int s21_bit_shift_buffer(int buffer[BUFF_SIZE])
{
    int return_value = 0;
    if (buffer)
    {
        int num1 = GET_FIRST_BIT(buffer[1]);
        int num2 = GET_FIRST_BIT(buffer[2]);
        int num3 = GET_FIRST_BIT(buffer[3]);
        buffer[1] <<= 1;
        buffer[2] <<= 1;
        buffer[3] <<= 1;
        return_value = num1;
        buffer[1] |= num2;
        buffer[2] |= num3;
    }
    return return_value;
}

void s21_output_bits(int *num, int len)
{
    if (num)
    {
        int setter = 1;
        for (int j = 0; j < len; j++)
        {
            for (int i = (int)sizeof(int)*8 - 1; i >= 0; i--)
            {
                if (num[j] & (setter << i))
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
            }
            printf(" ");
        }
        printf("\n");
    }
}

int s21_get_decimal_exp(s21_decimal number)
{
    int exponent = 0;
    int *ptr = (int *)(&number);
    exponent = ptr[3];
    exponent <<= LEAD_ZERO_LEN;
    exponent >>= (LEAD_ZERO_LEN+TRAIL_ZERO_LEN+SIGN_LEN);
    return exponent;
}

void s21_set_decimal_exp(s21_decimal *number, int exponent)
{
    if (number)
    {
        int *ptr = (int *)(&number);
        exponent <<= (TRAIL_ZERO_LEN+SIGN_LEN);
        ptr[3] &= 1;
        ptr[3] |= exponent;
    }
}