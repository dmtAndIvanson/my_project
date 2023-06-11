#include "s21_decimal.h"

#define NUMBER_BETWEEN(number, left, right) ((number) >= (left) && (number) <= (right))
#define GET_FIRST_BIT(number) (((number) & (1 << (BITS_IN_INT-2))) >> (BITS_IN_INT-2))

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
    int return_value = ZERO_DIVISION_ERROR;
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
                int num1 = GET_FIRST_BIT(bits[1]);
                int num2 = GET_FIRST_BIT(bits[2]);
                int num3 = GET_FIRST_BIT(bits[3]);
                bits[1] <<= 1;
                bits[2] <<= 1;
                bits[3] <<= 1;
                dividend |= num1;
                bits[1] |= num2;
                bits[2] |= num3;
                int res2 = GET_FIRST_BIT(result[2]);
                int res3 = GET_FIRST_BIT(result[3]);
                result[1] <<= 1;
                result[2] <<= 1;
                result[3] <<= 1;
                result[1] |= res2;
                result[2] |= res3;
                if (dividend >= divisor)
                {
                    dividend %= 10;
                    result[3] |= 1;
                    printf("1");
                }
                else
                {
                    printf("0");
                }
                dividend <<= 1;
            } 
        }
        memcpy(bits, result, INT_4_LEN);
    }
    printf("\n");
    return return_value;
} 