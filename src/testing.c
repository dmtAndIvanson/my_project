#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

int main(void)
{
    // int s21_floor(s21_decimal value, s21_decimal *result)
    s21_decimal num1 = {{0}};
    s21_from_int_to_decimal(-10, &num1);
    int dst = 0;
    s21_from_decimal_to_int(num1, &dst);
    printf("num = %d\n", dst);
}