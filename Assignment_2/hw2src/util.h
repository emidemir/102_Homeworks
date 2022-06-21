#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, char s, int w);

char dt1a(double A, double B);
char dt1b(double A, double B);

double dt2a(double x1, double x2, double x3, int a, int b);
double dt2b(double x1, double x2, double x3, int a, int b);

/* Write the prototype of the functions implementing the decision trees for the third problem */
char dt3a(double x1, double x2, int binary, int char_choice, int wheather_choice);
char dt3b(double x1, double x2, int binary, int char_choice, int wheather_choice);

#endif /* _UTIL_H_ */