#include "1-print.h"

void output(int *);

int main(void) {
    int arr[ARRAY_SIZE];
    int desired_arr[ARRAY_SIZE] = {
        1, 5, 7, 2, 4
    };
    output(arr);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] != desired_arr[i]) {
            return 1;
        }
    }

    return 0;
}
