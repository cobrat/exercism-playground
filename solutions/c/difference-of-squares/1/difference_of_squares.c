#include "difference_of_squares.h"
#include <stdio.h>

unsigned int sum_of_squares(unsigned int number){
    unsigned int sum = 0;
    unsigned int i = 1;
    while (i <= number){
        sum += i * i;
        printf("%u\n", sum);
        i++;
    }
    return sum;
}

unsigned int square_of_sum(unsigned int number){
    unsigned int sum = 0;
    unsigned int i = 1;
    while (i <= number){
        sum += i;
        printf("%u\n", sum);
        i++;
    }
    return sum * sum;
}

unsigned int difference_of_squares(unsigned int number){
    unsigned int s1 = sum_of_squares(number);
    unsigned int s2 = square_of_sum(number);

    printf("s1: %u s2: %u\n", s1, s2);

    return s2 - s1;
}
