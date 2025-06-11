#include <stdio.h>
#include <stdlib.h>

#include "include/cell.h"

int main() {
    cell_t cell = cell_init_all_digits();

    cell_eliminate_possible_digit(&cell, 3);
    cell_eliminate_possible_digit(&cell, 5);
    cell_eliminate_possible_digit(&cell, 9);

    cell_print(cell);

    return EXIT_SUCCESS;
}