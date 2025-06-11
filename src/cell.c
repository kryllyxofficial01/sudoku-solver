#include "include/cell.h"

cell_t cell_init_all_digits() {
    return (cell_t) { .mask = CELL_ALL_POSSIBLE_DIGITS_MASK };
}

cell_t cell_init_as_digit(int digit) {
    cell_t cell = { .mask =  CELL_ALL_POSSIBLE_DIGITS_MASK };

    if (digit > 1 && digit < 9) {
        cell.mask = CELL_SINGLE_DIGIT_MASK(digit);
    }

    return cell;
}

void cell_eliminate_possible_digit(cell_t* cell, int digit) {
    if (digit >= 1 && digit <= 9) {
        cell->mask = CELL_DIGIT_MASK_REMOVE(cell->mask, digit);
    }
}

bool cell_is_digit_allowed(const cell_t cell, int digit) {
    return (digit >= 1 && digit <= 9) && CELL_DIGIT_MASK_TEST(cell.mask, digit);
}

int cell_get_possible_digit_count(const cell_t cell) {
    return CELL_DIGIT_MASK_COUNT(cell.mask);
}

int cell_get_collapsed_digit(const cell_t cell) {
    return CELL_DIGIT_MASK_GET(cell.mask);
}

void cell_print(const cell_t cell) {
    fprintf(stdout, "[");

    for (int i = 0; i < 9; i++) {
        if (cell_is_digit_allowed(cell, i)) {
            fprintf(stdout, "%i,", i);
        }
    }

    fprintf(stdout, "\b]\n");
}