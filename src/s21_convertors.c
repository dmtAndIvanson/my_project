#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst)
{
    // Check sign of number.
    // If negative, convert to positive and add one to significant part.
    // Copy significant part to first byte.
    // Set exponent to zero.
    // Set sign.
}