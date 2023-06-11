#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

int main(void)
{
    // int s21_floor(s21_decimal value, s21_decimal *result)
    s21_decimal num1 = {{0}};
    s21_decimal num2 = {{0}};
    s21_from_int_to_decimal(-10, &num1);
    printf("Ret: %d\n",s21_floor(num1, &num2));
    int *ptr1 = (int*)(&num1);
    int *ptr2 = (int*)(&num2);
    s21_output_bits(ptr1, 4);
    s21_output_bits(ptr2, 4);
    printf("\n");
}