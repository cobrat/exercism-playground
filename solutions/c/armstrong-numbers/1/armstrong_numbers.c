#include "armstrong_numbers.h"
#include <math.h>
#include <stdio.h>

bool is_armstrong_number(int candidate) {
    int temp = candidate;
    int a_sum = 0;
    int n = 0;

    while (temp > 0) {
        temp /= 10;
        // printf("Current temp: %d\n", temp);
        n++;
    }

    temp = candidate;
    while (temp > 0) {
        int digit = temp % 10;
        a_sum += (int)pow(digit, n);
        // printf("Current sum: %d\n", a_sum);
        temp /= 10;
    }

    return a_sum == candidate;
}

#ifdef TEST_MAIN
int main(void) {
    printf("9 is %d.\n", is_armstrong_number(9));
    printf("10 is %d.\n", is_armstrong_number(10));
    printf("153 is %d.\n", is_armstrong_number(153));
    printf("154 is %d.\n", is_armstrong_number(154));

    return 0;
}
#endif
