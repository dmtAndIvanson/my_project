#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

int main(void)
{
    int bits[BUFF_SIZE] = {0,0,0,-1};
    s21_divide_10_bits(bits);
    s21_output_bits(bits, 4);
    printf("\n");
}