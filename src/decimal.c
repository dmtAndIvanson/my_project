#include <stdio.h>
#include <string.h>

// Defines for work with bits.
#define INT_4_ZERO_MASK {{0,0,0,0}}
#define INT_3_LEN (sizeof(int) * 3)

// Structures.
typedef struct
{
    int bits[4];
} s21_decimal;

// Arithmetic functions.
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int main(void)
{
    s21_decimal val_1 = {{0,1,~0,0}};
    s21_decimal val_2 = {{0,1,1,0}};
    s21_decimal res = INT_4_ZERO_MASK;
    s21_add(val_1, val_2,&res);
    int *ptr = (int*)(&res);
    for (int i = 0; i < 4; i++)
    {
        printf("int %i: %i\n", i, ptr[i]);
    }
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
{
    // TODO: Normalize values.

    // Initialize long value for calculations.
    int long_value_1[6] = {0};
    int long_value_2[6] = {0};
    int long_result[6] = {0};

    // Copy significant parts to long values.
    memcpy(long_value_1+3, &value_1, INT_3_LEN);
    memcpy(long_value_2+3, &value_2, INT_3_LEN);

    // Check signs of numbers.

    // Sum numbers to long value.
    int setter = 1;
    int remember_bit = 0;
    for (size_t i = 5; i > 1; i--)
    {
        int tmp_res = 0;
        for (size_t j = 0; j < 8; j++)
        {
            int tmp_1 = *(long_value_1+i);
            int tmp_2 = *(long_value_2+i);
            
            int sum = ((tmp_1 & (setter << j)) >> j) + ((tmp_2 & (setter << j)) >> j) + remember_bit;
            tmp_res |= ((sum % 2) << j);
            remember_bit = sum > 1 ? 1 : 0;
        }
        *(long_result+i) = tmp_res;
    }
    memcpy(result, long_result+3, INT_3_LEN);

    // Check overflow.
    
    return 0;
}