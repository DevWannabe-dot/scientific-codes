/**
 * @file    primeFactorDecomposition.c
 * @brief   Outputs what prime numbers multiply together to make the argv[1] number.
 * @author  Pedro Henrique Pinto de Oliveira
 * @date    2023-12-12
*/

/* Inclusions */
#include "headers/errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/* Constants */
#define TRUE    (1 == 1)
#define FALSE   (!TRUE)

/* Types */
typedef uint8_t bool_t;

/* Functions */
bool_t isPrime(unsigned long n) {
    int iterator = n;
    
    if(n != 1 && n != 2) {
        if(n % --iterator == 0) return FALSE;
    }
    return TRUE;
}
void DecomposePrimeFactors(unsigned long n) {
    unsigned long prime = 2;

    printf("%lu", n);

    while(n != 1) {
        if(n % prime == 0) {
            n /= prime;
            printf(" : %lu = %lu", prime, n);
        } else {
            do {
                prime++;
            } while (isPrime(prime) == FALSE);
        }
    }
    puts("");
}
int main(int argc, char ** argv) {
    unsigned long num;

    if(argc != NO_ARGS_PROVIDED + 1) return NOT_ENOUGH_ARGS;
    
    num = strtoul(argv[1], NULL, 0);

    DecomposePrimeFactors(num);

    return SUCCESS;
}