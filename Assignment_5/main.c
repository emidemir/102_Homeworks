#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define P_I_ 3.14

typedef enum {Triangle = 1, Quadrilatedral, Circle, Pyramid, Cyclinder} Shapes;
typedef enum {Area = 1, Perimeter, VOlume} Calculators;


/*THIS ATOI FUNCTION WORKS BETTER THAN ORIGINAL ATOI I GUESS*/
/* hmmmmm MAYBE I HOPE :/   */


double atoi_num()    /* TO CONVERT STRING NUMBER INPUT INTO INT TYPE*/
{
    double sum = 0, flag = 0;
    char c;
    int keep_reading;

    if ((c = getchar()) == '-') /* IF NUMBER IS NEGATIVE*/
        flag = 1;
    else if (c <= '9' && c >= '0')
        sum = sum*10 + (c - 48);

    else
        return (-1);


    while ((c = getchar()) != '\n')
    {
        if (c <= '9' && c >= '0')
            sum = sum*10 + (c - 48);

        else if (c == '.')
        {
            double denominator = 10; /*This variable is used only if user tries to enter double type.*/
            while ((c = getchar()) != '\n') /*Purpose is , we will devide every number after '.' by 10-100-1000... and so on to make it double type*/
            {
                if (c <= '9' && c >= '0')
                {
                    sum = sum + (c-48)/denominator;
                    denominator = denominator*10;
                }
                else
                    return (-1);    /*ERROR CODE -1*/
            }
            break; /*After '.',we must get numbers and when user is done, loop must stop*/
        }
        
        else
            return (-1);    /*ERROR CODE -1*/
    }

    if (flag == 1)  
        sum *= -1;
    
    return (sum);
}

int calculate(int (*)(), int (*)());

int select_shape () 
{
    printf("Select a shape to calculate :\n");
    printf("-----------------------------\n");
    printf("1. Triangle\n");
    printf("2. Quadrialteral\n");
    printf("3. Cİrcle\n");
    printf("4. Pyramid\n");
    printf("5. Cyclinder\n");
    printf("0. EXit\n");

    double choice = atoi_num();  /*get number from user*/

    if (choice == -1)   /* -1 is error code*/
        return (-1);

    return (choice);
}

int select_calc ()
{
    double choice;
    do
    {
        printf("Select calculator:\n");
        printf("-----------------------------\n");
        printf("1. Area\n");
        printf("2. Perimeter\n");
        printf("3. Volume\n");
        printf("0. EXit\n");

        choice = atoi_num();  /*get number from user*/

        if (choice == -1)   /* INVALID ENTRY RETURN -1 FOR SHAPE TYPE*/ 
        {
            printf("!!! YOU ENTERED WRONG CHOICE !!!\n");
            while(getc(stdin) != '\n');
            choice = 8; /*to contiuny loop*/
        }

        else if (choice != 0)  /* if input is valid*/
        {
           return (choice);
        }

    }while (choice != 0);   /* Untill user enter 0, this loop will g-contiuny*/
    
    return (choice);
}

int calc_triangle(Calculators flag)
{
    double result;

    switch(flag)
    {
        int keep_reading; /*bool variable to keep reading*/
        double s1,s2,s3; /*side1 side2 side3*/

        /* CASES HAVE NEARLY SAME CODE*/

        case Area:
            printf(" "); /*THIS IS HERE BECAUSE OF LABEL DECLERATION ERROR*/
            keep_reading = 1;

            while (keep_reading)
            {
                printf("ENTER SIDES:\n");
                s1 = atoi_num();
                s2 = atoi_num();
                s3 = atoi_num();
                if (s1 <= 0 || s2 <= 0 || s3 <= 0)
                {
                    printf("INVALID NUMBER,TRY AGAIN\n");
                    while(getc(stdin) != '\n'); /*clear buffer*/
                }

                /* Checking the variables if it fits in for a triangle*/
                if (!(s1 + s2 > s3) || !(s2 + s3 > s3) || !(s3 + s1 > s2))
                {
                    printf("Values are not valid for creating a triangle");
                    while(getc(stdin) != '\n'); /*clear buffer*/
                }
                else
                {
                    double heron = (double)(s1 + s2 + s3) / 2;
                    result = sqrt(heron*(heron-s1)*(heron-s2)*(heron-s3));
                    printf("RESULT IS : %.2lf\n",result);
                    keep_reading = 0;
                }
            }
            break;

        case Perimeter:
            keep_reading = 1;

            while (keep_reading)
            {
                printf("ENTER SIDES:\n");
                s1 = atoi_num();
                s2 = atoi_num();
                s3 = atoi_num();
                if (s1 <= 0 || s2 <= 0 || s3 <= 0)
                {
                    printf("INVALID NUMBER,TRY AGAIN\n");
                    while(getc(stdin) != '\n');
                }
                else
                {
                    result = s1 + s2 + s3;
                    printf("RESULT IS : %.2lf\n",result);
                    keep_reading = 0;
                }
            }

            break;

        case VOlume:
            printf("YOU CAN NOT CALCULATE THIS, IT BROKES THE PHYSIC\n");
            break;

    }

    return (0);
}

int calc_quadrilateral(Calculators flag)
{
    double result;

    switch(flag)
    {
        int keep_reading; /*bool variable to keep reading*/
        double s1,s2,s3,s4; /*side1 side2 side3 side4*/

        /* CASES HAVE NEARLY SAME CODE*/

        case Area:
            printf(" ");    /*THIS IS HERE BECAUSE OF LABEL DECLERATION ERROR*/
            keep_reading = 1;

            while (keep_reading)
            {
                printf("ENTER SIDES:\n");
                s1 = atoi_num();
                s2 = atoi_num();
                s3 = atoi_num();
                s4 = atoi_num();
                if (s1 <= 0 || s2 <= 0 || s3 <= 0 || s4 <= 0)
                {
                    printf("INVALID NUMBER,TRY AGAIN\n");
                    while(getc(stdin) != '\n'); /*clear buffer*/
                }
                else
                {
                    double brahma = (s1 + s2 + s3 + s4) / 2;
                    result = sqrt((brahma - s4)*(brahma-s1)*(brahma-s2)*(brahma-s3));
                    printf("RESULT IS : %.2lf\n",result);
                    keep_reading = 0;
                }
            }
            break;

        case Perimeter:
            keep_reading = 1;

            while (keep_reading)
            {
                printf("ENTER SIDES:\n");
                s1 = atoi_num();
                s2 = atoi_num();
                s3 = atoi_num();
                s4 = atoi_num();
                if (s1 <= 0 || s2 <= 0 || s3 <= 0 || s4 <= 0)
                {
                    printf("INVALID NUMBER,TRY AGAIN\n");
                    while(getc(stdin) != '\n');
                }
                else
                {
                    result = s1 + s2 + s3 + s4;
                    printf("RESULT IS : %.2lf\n",result);
                    keep_reading = 0;
                }
            }

            break;

        case VOlume:
            printf("YOU CAN NOT CALCULATE THIS, IT BROKES THE PHYSIC\n");
            break;

    }

    return (0);
}

int calc_circle(Calculators flag)
{
    double result;

    switch(flag)
    {
        double keep_reading; /*bool variable to keep reading*/
        double r1; /*radius */

        /* CASES HAVE NEARLY SAME CODE*/

        case Area:
            printf(" ");    /*THIS IS HERE BECAUSE OF LABEL DECLERATION ERROR*/
            keep_reading = 1;

            while (keep_reading)
            {
                printf("ENTER RADIUS:\n");
                r1 = atoi_num();

                if (r1 <= 0)
                {
                    printf("INVALID NUMBER,TRY AGAIN\n");
                    while(getc(stdin) != '\n'); /*clear buffer*/
                }

                else
                {
                    printf("RESULT IS : %.2lf\n",P_I_*(r1*r1));
                    keep_reading = 0;
                }
            }
            break;

        case Perimeter:
           printf(" ");    /*THIS IS HERE BECAUSE OF LABEL DECLERATION ERROR*/
            keep_reading = 1;

            while (keep_reading)
            {
                printf("ENTER RADIUS:\n");
                r1 = atoi_num();

                if (r1 <= 0)
                {
                    printf("INVALID NUMBER,TRY AGAIN\n");
                    while(getc(stdin) != '\n'); /*clear buffer*/
                }
                else
                {
                    result = 2*P_I_*r1; 
                    printf("RESULT IS : %.2lf\n",result);
                    keep_reading = 0;
                }
            }
            break;

        case VOlume:
            printf("YOU CAN NOT CALCULATE THIS, IT BROKES THE PHYSIC\n");
            break;
    }

    return (0);
}

int calc_pyramid(Calculators flag)
{
    switch(flag)
    {
        double keep_reading; /*bool variable to keep reading*/
        double b_side, s_heigh; /* base side, heigh*/

        /* CASES HAVE NEARLY SAME CODE*/

        case Area:
            printf(" ");    /*THIS IS HERE BECAUSE OF LABEL DECLERATION ERROR*/
            keep_reading = 1;

            while (keep_reading)
            {
                printf("Please Enter BAse Side and Slant Height of Pyramid:\n");
                b_side = atoi_num();
                s_heigh = atoi_num();

                if (b_side <= 0 || s_heigh <= 0)
                {
                    printf("INVALID NUMBER,TRY AGAIN\n");
                    while(getc(stdin) != '\n'); /*clear buffer*/
                }

                else
                {
                    double base_surface = b_side*b_side;
                    double lateral_area = 2*b_side*s_heigh; 
                    printf("BASE SURFACE AREA OF PYRAMID IS : %.2lf\n",base_surface);
                    printf("LATERAL SURFACE OF PYRAMID IS : %.2lf\n",lateral_area);
                    printf("SURFACE AREA IS : %.2lf\n",base_surface+lateral_area);
                    keep_reading = 0;
                }
            }
            break;

        case Perimeter:
           printf(" ");    /*THIS IS HERE BECAUSE OF LABEL DECLERATION ERROR*/
            keep_reading = 1;

            while (keep_reading)
            {
                printf("ENTER BASE SIDE:\n");
                b_side = atoi_num();

                if (b_side <= 0)
                {
                    printf("INVALID NUMBER,TRY AGAIN\n");
                    while(getc(stdin) != '\n'); /*clear buffer*/
                }

                else
                {
                    double perimeter = 4*b_side;
                    printf("PERIMETER OF PYRAMID IS : %.2lf\n",perimeter);
                    keep_reading = 0;
                }
            }
            break;

        case VOlume:
           printf(" ");    /*THIS IS HERE BECAUSE OF LABEL DECLERATION ERROR*/
            keep_reading = 1;

            while (keep_reading)
            {
                printf("ENTER BASE SIDE AND HEIGH:\n");
                b_side = atoi_num();
                s_heigh = atoi_num();

                if (b_side <= 0 || s_heigh <= 0)
                {
                    printf("INVALID NUMBER,TRY AGAIN\n");
                    while(getc(stdin) != '\n'); /*clear buffer*/
                }

                else
                {
                    double volume = (b_side*b_side*s_heigh)/3;
                    printf("VOLUME OF PYRAMID IS : %.2lf\n",volume);
                    keep_reading = 0;
                }
            }
            break;
    }

    return (0);
}

int calc_cylinder(Calculators flag)
{
    switch(flag)
    {
        double keep_reading; /*bool variable to keep reading*/
        double radius, height;

        /* CASES HAVE NEARLY SAME CODE*/

        case Area:
            printf(" ");    /*THIS IS HERE BECAUSE OF LABEL DECLERATION ERROR*/
            keep_reading = 1;

            while (keep_reading)
            {
                printf("PLEASE ENTER RADIUS AND HEIGH OF CYCLENDER :\n");
                radius = atoi_num();
                height = atoi_num();

                if (radius <= 0 || height <= 0)
                {
                    printf("INVALID NUMBER,TRY AGAIN\n");
                    while(getc(stdin) != '\n'); /*clear buffer*/
                }

                else
                {
                    double base_surface = P_I_*radius*radius;
                    double lateral_area = 2*P_I_*radius*height; 
                    printf("BASE SURFACE AREA OF CYCLENDER IS : %.2lf\n",base_surface);
                    printf("LATERAL SURFACE OF CYCLENDER IS : %.2lf\n",lateral_area);
                    printf("SURFACE AREA IS : %.2lf\n",base_surface+lateral_area);
                    keep_reading = 0;
                }
            }
            break;

        case Perimeter:
            printf(" ");    /*THIS IS HERE BECAUSE OF LABEL DECLERATION ERROR*/
            keep_reading = 1;

            while (keep_reading)
            {
                printf("PLEASE ENTER RADIUS OF CYCLENDER :\n");
                radius = atoi_num();

                if (radius <= 0 || height <= 0)
                {
                    printf("INVALID NUMBER,TRY AGAIN\n");
                    while(getc(stdin) != '\n'); /*clear buffer*/
                }

                else
                {
                    double perimeter = 2*P_I_*radius; 
                    printf("PERIMETER IS : %.2lf\n",perimeter);
                    keep_reading = 0;
                }
            }
            break;

        case VOlume:
            printf(" ");    /*THIS IS HERE BECAUSE OF LABEL DECLERATION ERROR*/
            keep_reading = 1;

            while (keep_reading)
            {
                printf("PLEASE ENTER RADIUS AND HEIGH OF CYCLENDER :\n");
                radius = atoi_num();
                height = atoi_num();

                if (radius <= 0 || height <= 0)
                {
                    printf("INVALID NUMBER,TRY AGAIN\n");
                    while(getc(stdin) != '\n'); /*clear buffer*/
                }

                else
                {
                    double volume = P_I_*radius*radius*height;
                    printf("VOLUME OF CYCLENDER IS : %.2lf\n",volume);
                    keep_reading = 0;
                }
            }
            break;
    }

    return (0);
}


int main()
{

    calculate(select_shape,select_calc);


    return (0);
}

int calculate(int (*select_shape)(), int (*select_calc)())
{

    int choice_shape;
    Calculators choice_cal;     /*WAnted area , perimeter, volume enum type is storee in this variable*/ 

    do{
        /* SHAPE SELECTING PART*/
        choice_shape = select_shape();

        if (choice_shape == 0)
            return (0);

        else if (choice_shape == -1)   /* INVALID ENTRY RETURN -1 FOR SHAPE TYPE*/ 
            {
                printf("!!!YOU ENTERED WRONG CHOICE !!!\n");
                choice_shape = 8;
                while(getc(stdin) != '\n');
            }

                switch (choice_shape)
                {
                    case Triangle:
                        choice_cal = select_calc();
                        calc_triangle(choice_cal);      
                        break;
                        
                    case Quadrilatedral:
                        choice_cal = select_calc();
                        calc_quadrilateral(choice_cal);
                        break;

                    case Circle:
                        choice_cal = select_calc();
                        calc_circle(choice_cal);
                        break;

                    case Pyramid:
                        choice_cal = select_calc();
                        calc_pyramid(choice_cal);
                        break;

                    case Cyclinder:
                        choice_cal = select_calc();
                        calc_cylinder(choice_cal);
                        break;

                    case 0:
                        return (0);
                        break;
                }
    }while (choice_shape != 0);

    return (0);
}