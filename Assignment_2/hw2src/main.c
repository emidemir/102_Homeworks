#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main() {

    int problem;
    printf("WHICH PROBLEM YOU WANT TO SOLVE :");
    scanf("%d",&problem);

    if (problem == 1)   //PROBLEM 1
    {
        double PL,PW,SL,SW;
        printf("ENTER THE PL : ");
        scanf("%lf",&PL);
        printf("\n");
        printf("ENTER THE PW :");
        scanf("%lf",&PW);
        printf("\n");
        printf("ENTER THE SL : ");
        scanf("%lf",&SL);
        printf("\n");
        printf("ENTER THE SW : ");
        scanf("%lf",&SW);
        char result_1a = dt1a(PL,PW);
        char result_2a = dt1b(PL,PW);

        if (result_1a != result_2a)     // If outputs are different
        {
            if (result_1a == 'v')
            printf("VIRGINICA: result 1\n");
            else if (result_1a == 's')
            printf("SETOSA: result 1\n");
            else if (result_1a == 'y')
            printf("VERSICOLOR: result 1\n");

            if (result_2a == 'v')
            printf("VIRGINICA: result 2\n");
            else if (result_2a == 's')
            printf("SETOSA: result 2\n");
            else if (result_2a == 'y')
            printf("VERSICOLOR: result 2\n");
            
        }
        else if (result_1a == result_2a) //    If outputs are same
        {
             if (result_1a == 'v')
            printf("VIRGINICA\n");
            else if (result_1a == 's')
            printf("SETOSA\n");
            else if (result_1a == 'y')
            printf("VERSICOLOR\n");
        }
    }

    else if (problem == 2)  //PROBLEM 2
    {
        double x1,x2,x3;
        int a,b;

        printf("ENTER THE FIRST THREE REAL NUMBER :");
        scanf("%lf%lf%lf",&x1,&x2,&x3);
        printf("ENTER THE BINARY NUMBERS : ");
        scanf("%d%d",&a,&b);
        if (a != 1 || a != 0)
        {
            printf("THESE ARE NOT BINARY VALUES !!!");
            return (0);
        }

        if (b != 1 || b != 0)
        {
            printf("THESE ARE NOT BINARY VALUES !!!");
            return (0);
        }

        double result_2a = dt2a(x1,x2,x3,a,b);
        double result_2b = dt2b(x1,x2,x3,a,b);
        
        if (result_2a == result_2b)    // CHECKING THE VARIABLES WHETHER EQUAL OR NOT
        printf("%.1lf : OUTPUTS ARE SAME",result_2a);

        else
        {
            if (result_2a - result_2b <= CLOSE_ENOUGH || result_2b - result_2a <= CLOSE_ENOUGH )
                printf("%.1lf : AVARAGE OF THWO DIFFERENT ANSWER\n",(result_2a + result_2b) / 2);
            else
                printf("OUTPU OF FIRST dt : %.1lf\nOUTPUT OF SECOND dt : %.1lf",result_2a,result_2b);
        }
    }

    else if (problem == 3)  //PROBLEM 3
    {
        double heigh,weight;
        int fun_or_not,character,weather;

        printf("ENTER YOUR HEIGHT AND WEIGHT :");    //WIGHT AND HEIGHT
        scanf("%lf%lf",&heigh,&weight);
        printf("\n");
        printf("ARE YOU PESSIMISTIC(0) OR OPTIMISTIC(1) : ");  //OPTIMISTIC OR PESIMISTIC
        scanf("%d",&fun_or_not);
        printf("\n");
        if (fun_or_not != 1)
        {
            if (fun_or_not != 0)
            {
                 printf("%d",fun_or_not);
                printf("THIS VARIABLE MUST BE BINARY TYPE");
                return (0);
            }
        }
        printf("WHICH TYPE OF WEATHER YOU LIKE : ");    //WEATHER TYPE
        printf("\n");
        printf("(1)SNOWY, (2)SUNNY, (3)CLOUDY, (4)WINDY, (5)RAINY");
        scanf("%d",&weather);
        if (weather > 5 || weather < 1)
        {
            printf("YOU ENTERED WRONG FOR WEATHER");
            return (0);
        }
        printf("\n");
        printf("HOW WOULD YOU DEFINE YOURSELFE :");     //CHARACTERİSTİC
        printf("\n");
        printf("(1)FUNNY, (2)AMBITIOUS, (3)CONFIDENT, (4)CALM, (5)PESSIMISTIC");
        scanf("%d",&character);
         if (character > 5 || character < 1)
        {
            printf("YOU ENTERED WRONG FOR CHARACTER");
            return (0);
        }

        char result_dt1 = dt3a(heigh,weight,fun_or_not,character,weather);
        char result_dt2 = dt3b(heigh,weight,fun_or_not,character,weather);
        
        if (result_dt1 != result_dt2) //CHECKING IF THE ANSWERS ARE EQUAL OR NOT
        {
            if (result_dt1 == 'a')
                printf("RESULT OF FIRST TREE IS : BASKETBALL \n");
            else if (result_dt1 == 'b')
                printf("RESULT OF FIRST TREE IS : BICYCLE\n");
            else if (result_dt1 == 'c')
                printf("RESULT OF FIRST TREE IS : TEAM SPORT\n");
            else if (result_dt1 == 'd')
                printf("RESULT OF FIRST TREE IS : SELF DEFEND\n");
            else if (result_dt1 == 'e')
                printf("RESULT OF FIRST TREE IS : YOGA AND MEDITATION\n");
            else if (result_dt1 == 'f')
                printf("RESULT OF FIRST TREE IS : SKIING\n");
            else if (result_dt1 == 'g')
                printf("RESULT OF FIRST TREE IS : CLIMBING\n");
            else if (result_dt1 == 'l')
                printf("RESULT OF FIRST TREE IS : FITNESS\n");
            else if (result_dt1 == 'k')
                printf("RESULT OF FIRST TREE IS : SKY DIVING\n");
            else if (result_dt2 == 's')
                printf("RESULT OF FIRST TREE IS : SWIMMING\n");

            if (result_dt2 == 'a')
                printf("RESULT OF FIRST TREE IS : BASKETBALL \n");
            else if (result_dt2 == 'b')
                printf("RESULT OF FIRST TREE IS : BICYCLE\n");
            else if (result_dt2 == 'c')
                printf("RESULT OF FIRST TREE IS : TEAM SPORT\n");
            else if (result_dt2 == 'd')
                printf("RESULT OF FIRST TREE IS : SELF DEFEND\n");
            else if (result_dt2 == 'e')
                printf("RESULT OF FIRST TREE IS : YOGA AND MEDITATION\n");
            else if (result_dt2 == 'f')
                printf("RESULT OF FIRST TREE IS : SKIING\n");
            else if (result_dt2 == 'g')
                printf("RESULT OF FIRST TREE IS : CLIMBING\n");
            else if (result_dt2 == 'l')
                printf("RESULT OF FIRST TREE IS : FITNESS\n");
            else if (result_dt2 == 'k')
                printf("RESULT OF FIRST TREE IS : SKY DIVING\n");
            else if (result_dt2 == 's')
                printf("RESULT OF FIRST TREE IS : SWIMMING\n");
        }

        else if (result_dt1 == result_dt2)
        {
             if (result_dt1 == 'a')
                printf("RESULT OF YOUR CHOICE'S IS : BASKETBALL \n");
            else if (result_dt1 == 'b')
                printf("RESULT OF YOUR CHOICE'S IS : BICYCLE\n");
            else if (result_dt1 == 'c')
                printf("RESULT OF YOUR CHOICE'S IS : TEAM SPORT\n");
            else if (result_dt1 == 'd')
                printf("RESULT OF YOUR CHOICE'S IS : SELF DEFEND\n");
            else if (result_dt1 == 'e')
                printf("RESULT OF YOUR CHOICE'S IS : YOGA AND MEDITATION\n");
            else if (result_dt1 == 'f')
                printf("RESULT OF YOUR CHOICE'S IS : SKIING\n");
            else if (result_dt1 == 'g')
                printf("RESULT OF YOUR CHOICE'S IS : CLIMBING\n");
            else if (result_dt1 == 'l')
                printf("RESULT OF YOUR CHOICE'S IS : FITNESS\n");
            else if (result_dt1 == 'k')
                printf("RESULT OF YOUR CHOICE'S IS : SKY DIVING\n");
            else if (result_dt2 == 's')
                printf("RESULT OF YOUR CHOICE'S IS : SWIMMING\n");
        }
    }

    return 0;
}
