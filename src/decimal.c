#include <stdio.h>
#include <string.h>

// Defines for work with bits.
#define INT_4_ZERO_MASK {{0,0,0,0}}
#define INT_6_ZERO_MASK {{0,0,0,0,0,0}}
#define INT_6_LAST_BIT_ONE {{0,0,0,0,0,1}}
#define INT_3_LEN (sizeof(int) * 3)

// Structures.
typedef struct
{
    int bits[4];
} s21_decimal;

typedef struct
{
    int bits[6];
} s21_unsigned_long_decimal;

// Arithmetic functions.
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int main(void)
{
    s21_decimal val_1 = INT_4_ZERO_MASK;
    int *ptr = (void *)(&val_1);
    for (int i = 0; i < 4; i++)
    {
        printf("digit %d: %d\n", i, ptr[i]);
    }
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
{
    // TODO: Normalize values.

    // Initialize long value for calculations.
    s21_unsigned_long_decimal long_value_1 = INT_6_ZERO_MASK;
    s21_unsigned_long_decimal long_value_2 = INT_6_ZERO_MASK;
    s21_unsigned_long_decimal long_result = INT_6_ZERO_MASK;
    s21_unsigned_long_decimal setter = INT_6_LAST_BIT_ONE;

    // Copy significant parts to long values.
    memcpy(&long_value_1, &value_1, INT_3_LEN);
    memcpy(&long_value_2, &value_2, INT_3_LEN);
    long_value_1 >>= INT_3_LEN;
    long_value_2 >>= INT_3_LEN;

    // Sum numbers to long value.
    int remember_bit = 0;
    for (size_t i = 0; i < INT_3_LEN; i++)
    {
        
    }
}