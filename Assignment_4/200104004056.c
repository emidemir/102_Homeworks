#include <stdio.h>




/*  PLEASE READ LINE 25 :)  */
/******
/********
/**********
/************
/***************/



int found_digit(int a) // Will be used for deletin numbers whic are stored in file as characters
{
	int sum = 1;
	if(a < 0)   
	{
		a *= -1;
		sum += 1;
	}

	if (a <= 9 && a >= 0)
	return (1);
                                        
	else if (a >= 10){                  /* this equal sign is worth 2 hours of work. Please consider this while asessing my HW sir :) because before = sign., -10 had 2 digit*/
		sum += found_digit(a / 10);
	}

	if(a)
	return (sum);
}

void graph_print(int a, int b, int c)
{
    int i,j;

    /*used only for printing ^*/
    for (i = 0; i < 50; i++)
    printf(" ");

    printf("^\n");

    /*main graph*/
    for (j = 15; j >= -15; j--)
    {
        for (i = -50; i < 55; i++)
        {
            if (i == a*j*j + j*b +c) 
                printf("\033[1;34m#\033[0m");
            
            else
            {
                 if (i == 0){ /*y axis*/
                    printf("|");
                    }

                else if (i == -1) /*y axis numbers*/
                {
                    if (j % 5 == 0)
                    {
                        if (j >= 10) /*2 digit cause 2 digit deviatiion*/
                            printf("\b\b\033[1;33m%d\033[0m",j);
                        else if (j < 10 && j > 0) /*1 digit cause 1 digit deviatiion*/
                            printf("\b\033[1;33m%d\033[0m",j);
                        else if (j < 0 && j > -10) /*2 digit cause 2 digit deviatiion ('-' is a character)*/
                            printf("\b\b\033[1;33m%d\033[0m",j);
                        else if (j <= -10)  /*3 digit cause 3 digit deviatiion*/
                            printf("\b\b\b\033[1;33m%d\033[0m",j);
                    }     
                }

                if (j == 0 && i != 0) /* x axis*/
                {
                    if (i == -50)
                        printf("<");
                    else if (i == 54)
                        printf(">");
                    else
                        printf("-");
                }

                else if (j == -1) /*x axis numbers*/
                {
                    if (i == -1 ) /* - had a problem I added this part to prevent that*/
                        printf("\b\033[1;33m0\033[0m");
                    if (i % 10 == 0 && i != 0)
                    {
                        int temp = i;
                        int t;
                        printf("\033[1;33m%d\033[0m",i);
                        int digit = found_digit(i); /*if while printing the numbers of axis, it can skip #. to prevent this, I check next numbers. if number is 3 digit (-40), ı check the next 3 digit if # should be printed*/
                        while (digit > 0)
                        {
                            i++; 
                            if (i == a*j*j + j*b +c)
                            {
                               for (t= 0; t < digit -(temp-i) ; t++)
                                printf("\b");

                                printf("\033[1;34m#\033[0m\033[1;33m0\033[0m");
                            }
                            digit--;
                        }
                    }
                }

                if (i != 0 && j != 0)
                printf(" ");
            }   
        }   
        printf("\n");
    }
    /*used only for printing v*/
    for (i = 0; i < 50; i++)
    printf(" ");

    printf("v\n");
    
}

void print_file()
{
    FILE *ptr = fopen("coefficients.txt","r");
    FILE *fp = fopen("graph.txt","w");
    int a, b, c;
    fscanf(ptr,"%d%d%d\n",&a,&b,&c);

    int i,j;

    for (i = 0; i < 55; i++)
    fprintf(fp," ");
    fprintf(fp,"^\n");

    for (j = 15; j >= -15; j--)
    {
        for (i = -55; i < 55; i++)
        {
            if (i == a*j*j + j*b +c) 
                fprintf(fp,"#");
            else
            {
                if (i == 0)
                    fprintf(fp,"|");
                else if (j == 0)
                {
                    if (i == -55)
                        fprintf(fp,"<");
                    else if (i == 54)
                        fprintf(fp,">");
                    else 
                        fprintf(fp,"-");
                }
                if (i != 0 && j != 0)
                fprintf(fp," ");
            }
        }
        
        fprintf(fp,"\n");
    }
    for (i = 0; i < 55; i++)
    fprintf(fp," ");
    fprintf(fp,"v\n");

    fclose(fp);
}


int main()
{
    int choice ;
    do{
    printf("**********************************************\n");
    printf("0 -> Enter the coefficients.\n");
    printf("1 -> Draw the graph.\n");
    printf("2 -> Print the graph into a .text file.\n");
    printf("3 -> Exit.\n");
    printf("Choice :");
    scanf("%d",&choice);
    switch (choice)
    {
    case 0:

        printf("Please enter the coefficient for the following equation : x = a*(y*y) + b*y + c\n");
        int a,b,c;
        printf("a:");
        scanf("%d",&a);
        printf("\n");
        printf("b:");
        scanf("%d",&b);
        printf("\n");
        printf("c:");
        scanf("%d",&c);
        printf("\n");

        FILE *coef_pt = fopen("coefficients.txt","w");
        fprintf(coef_pt,"%d\n%d\n%d",a,b,c);
        printf("coefficients.txt file has been created.\n");
        fclose(coef_pt);
        break;

    case 1:

        int co_a, co_b, co_c;
        FILE *fp = fopen("coefficients.txt","r");
        
        if (fp == NULL){
            printf("Uppsss I guess something went wrong with the file !!!\n");   
        }
        else{
            printf("Coefficients has been read from the coefficients.txt file.\n");
            fscanf(fp,"%d%d%d\n",&co_a, &co_b, &co_c);
            printf("Printing the graph of x = %d*(y*y) + %d*y + %d\n",co_a, co_b, co_c);
            graph_print(co_a, co_b, co_c);
        }
        fclose(fp);
        break;
    case 2:
        printf("Coefficients has been read from the coefficient file.\n");
        print_file();
        break;
    
    case 3:
        return (0);
        break;
    default :
        printf("YOU ENTERED WRONG CHOICE");
    }

    }while(choice != 3);

return (0);
}