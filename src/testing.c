#include <stdio.h>

#include "decimal.h"

int main(void)
{
    s21_decimal val_1 = {{0,0,20,29<<(EXP_TRAIL_ZEROS+1)}};
    int *tmp_1 = (int *)(&val_1);
    for (int i = 0; i < BUFF_SIZE; i++)
    {
        output_bits(tmp_1[i]);
    }
    printf("\n");
    s21_decimal_devide_10(&val_1);
    for (int i = 0; i < BUFF_SIZE; i++)
    {
        output_bits(tmp_1[i]);
    }
    printf("\n");
}

/* Check exponent.
int main(void)
{
    s21_decimal val_1 = {{1,1,1,29<<(EXP_TRAIL_ZEROS+1)}};
    int *tmp_1 = (int *)(&val_1);
    for (int i = 0; i < BUFF_SIZE; i++)
    {
        output_bits(tmp_1[i]);
    }
    printf("\n");
    printf("Exp: %d\n", s21_get_decimal_exp(val_1));
}*/

/* Check sign
int main(void)
{
    s21_decimal val_1 = {{1,1,1,2}};
    int *tmp_1 = (int *)(&val_1);
    for (int i = 0; i < BUFF_SIZE; i++)
    {
        output_bits(tmp_1[i]);
    }
    printf("\n");
    printf("Sign: %d\n", s21_get_decimal_sign(val_1));
}*/

/* Check sub
int main(void)
{
    s21_decimal val_1 = {{0,1,2,0}};
    s21_decimal val_2 = {{0,0,1,1}};
    s21_decimal res = INT_4_ZERO_MASK;
    int *tmp_1 = (int *)(&val_1);
    int *tmp_2 = (int *)(&val_2);
    int *tmp_3 = (int *)(&res);
    s21_add(val_1, val_2,&res);
    int *ptr = (int*)(&res);
    for (int i = 0; i < BUFF_SIZE; i++)
    {
        output_bits(tmp_1[i]);
    }
    printf("\n");
    for (int i = 0; i < BUFF_SIZE; i++)
    {
        output_bits(tmp_2[i]);
    }
    printf("\n");
    for (int i = 0; i < BUFF_SIZE; i++)
    {
        output_bits(tmp_3[i]);
    }
    printf("\n");
    for (int i = 0; i < BUFF_SIZE; i++)
    {
        printf("int %i: %i\n", i, ptr[i]);
    }
}*/