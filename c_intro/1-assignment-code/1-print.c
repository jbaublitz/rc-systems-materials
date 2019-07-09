#include <stdio.h>

#include "1-print.h"

/*
 * Do not touch
 */
void change_by_reference(int *a, int v) {
    *a = v;
}

/*
 * Do not touch
 */
void change_by_value(int a, int v) {
    a = v;
}

/* 
 * NOTE
 *
 * Implement this function as follows:
 *
 * If val is greater than desired val, decrease val by 1 for each function call
 *
 * If val is less than desired val, increase val by 1 for each function call
 *
 * Ultimately this function should recursively bring val to the same value as desired_val
 */
int change_by_recursion(int val, int desired_val) {
    return val;
}

void output(int *storage) {
    // Keep the first and last lines the same
    // but change the other two to match desired output
    int zero = 0;
    change_by_reference(&zero, 5);
    change_by_value(zero, 1);
    storage[0] = zero;

    // Change this line without adding more to set the second value
    change_by_value(storage[1], 1);

    // Implement change_by_recursion and leave these three lines as they are
    storage[2] = change_by_recursion(10, 7);
    storage[2] = change_by_recursion(7, 7);
    storage[2] = change_by_recursion(2, 7);
    
    // Use pointer arithmetic to set the value properly for this line
    int *three = storage + 3;

    // Use pointer arithmetic in a for loop to set the last value
    //
    // CHANGE ME - Change the condition
    // Add here - Add the equivalent of incrementing an integer but for a pointer
    for (int *p = storage; /*CHANGE ME*/ p != storage /*CHANGE ME*/ ; /* Add here */) {
        // Add stuff here
    }
}

#ifdef PRINT_ADD_MAIN
/*
 * Do not touch
 */
int main(void) {
    int arr[ARRAY_SIZE] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    output(arr);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d\n", arr[i]);
    }
}
#endif
