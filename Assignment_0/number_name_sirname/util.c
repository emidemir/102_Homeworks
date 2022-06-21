#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
   *n3 = n1*d2 - n2*d1;
   *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*n2;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    if (n2 == 0) // if nominator of second number is 0, it causes denominator the be 0. 
    {
    printf("!!!NOMINATOR OF SECOND NUM CAN NOT BE 0 FOR DEVISION!!!");
    return ;
    }
    *n3 = n1*d2;
    *d3 = n2*d1;
    fraction_simplify(n3, d3);    
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int *n, int *d) {
    int i;
    if (*n < 0 && *d < 0) // if both are -, make it + by deviding - / - = +;
    {
    *n *= (-1);
    *d *= (-1);
    }
    if (*n <= *d)
    i = *n;
    else if (*d < *n)
    i = *d;
    if (i < 0) // if one or more num is '-' , treat gcd as '+'
    i *= (-1);
    if (i == 0) // if one of the numbers is 0, gcd is the greater one.
    {
        i = 5;
        *n = *n / i;
        *d = *d / i;
    }
    while (!(*n % i == 0 && *d % i == 0))
    i--;
    *n = *n / i;
    *d = *d / i;
} /* end fraction_div */
