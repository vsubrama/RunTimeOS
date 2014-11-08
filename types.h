#pragma once
#include <stdbool.h>
#include <stdint.h>

/* Booleans */
typedef enum {
  Yes = 1,
  No = 0
} boolean_t;

/* Bytes */
typedef uint8_t byte_t;

/* Characters */
typedef char character_t;

/* Natural Numbers */
typedef uint8_t natural8_t;
typedef uint16_t natural16_t;
typedef uint32_t natural32_t;
typedef uint64_t natural64_t;
typedef natural32_t natural_t;

/* Integers */
typedef int8_t integer8_t;
typedef int16_t integer16_t;
typedef int32_t integer32_t;
typedef int64_t integer64_t;
typedef integer32_t integer_t;

/* Math Types */
typedef struct
{
  natural_t x;
  natural_t y;
} natural_position_t;

typedef struct
{
  integer_t x;
  integer_t y;
} integer_position_t;
