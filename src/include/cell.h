#ifndef __CELL_H
#define __CELL_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define CELL_SINGLE_DIGIT_MASK(_digit) (1U << ((_digit) - 1))
#define CELL_DIGIT_MASK_TEST(_mask, _digit) (((_mask) >> ((_digit) - 1)) & 1U)
#define CELL_DIGIT_MASK_REMOVE(_mask, _digit) ((_mask) & ~(CELL_SINGLE_DIGIT_MASK(_digit)))
#define CELL_DIGIT_MASK_COUNT(_mask) (__builtin_popcount(_mask))
#define CELL_DIGIT_MASK_GET(_mask) ((CELL_DIGIT_MASK_COUNT(_mask) == 1) ? (__builtin_ctz(_mask) + 1) : 0)

#define CELL_ALL_POSSIBLE_DIGITS_MASK (0x1ff)

typedef struct _CELL {
    uint16_t mask;
} cell_t;

cell_t cell_init_all_digits();
cell_t cell_init_as_digit(int digit);

// remove a digit from the available pool
void cell_eliminate_possible_digit(cell_t* cell, int digit);

// check if a digit is allowed in the cell
bool cell_is_digit_allowed(const cell_t cell, int digit);

// get the number of allowed digits
int cell_get_possible_digit_count(const cell_t cell);

// get the digit the cell has been fully collapsed to
int cell_get_collapsed_digit(const cell_t cell);

void cell_print(const cell_t cell);

#endif