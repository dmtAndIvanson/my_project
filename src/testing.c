#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

void s21_output_bits(int *num, int len);

int main(void)
{
    int bits1[4] = {0,0,0,1};
    int bits2[4] = {0,0,0,1};
    int bits3[4] = {0};
    s21_sum_bits(bits1,bits2,bits3);
    s21_output_bits(bits3, 4);
    printf("\n");
}

void s21_output_bits(int *num, int len)
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
    }
    printf("\n");
}