#include <stdio.h>
#include <stdlib.h>

void s21_output_bits(int *num, int len);

int main(void)
{
    int bits[] = {2147483647};
    s21_output_bits(bits, 1);
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