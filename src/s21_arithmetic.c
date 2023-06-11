#include "s21_decimal.h"

void s21_sum_bits(int val_1[BUFF_SIZE], int val_2[BUFF_SIZE], int res[BUFF_SIZE])
{
    int min = 0;
    int max = 66;
    if ((val_1[0] >= min && val_1[0] <= max) && (val_2[0] >= min && val_2[0] <= max))
    {
        int setter = 1;
        int remember_bit = 0;
        for (int i = BUFF_SIZE-1; i > 0; i--)
        {
            int tmp_res = 0;
            for (int j = 0; j < 8; j++)
            {
                int sum = ((val_1[i] & (setter << j)) >> j) + ((val_2[i] & (setter << j)) >> j) + remember_bit;
                tmp_res |= ((sum % 2) << j);
                remember_bit = sum > 1 ? 1 : 0;
            }
            res[i] = tmp_res;
        }
    }
}