#include <stdio.h>
#include "utils.h"

int find_divisible(int x, int y, int z)
{
    int f_i = x;
    while (f_i % z != 0)  // FIRST INT WILL START FROM SMALL NUMBER AND COUNTIUNY UNTILL FIND THE FIRST VALID NUMBER
        f_i++;
    return (f_i);
}

int find_nth_divisible(int n, int f_I, int z) // This function is defined inside find_devisible funtion because we need x and y !
{
        if ( n == 0) // IF USER WANTS THE 0TH ELEMENT, RETURN THE FIRST INT.
        return (f_I);
        f_I++; // BELOW PROGRAM WOULD GET THE FIRST INT WE HAD NOT INCREASED FIRST INT BY ONE BECAUSE CONTROL WOULD BE INCREASED AT FIRST INT. 
                //BUT WE DO NOT WANT TO RETURN FIRST INT FOR N = 1. THIS IS A TRICK ACTUALLY :)
        int control = 0;
        while (control != n)
        {
            if (f_I % z == 0)
            {
                control ++;
                if (control == n) // WHENEVER PROGRAM FIND A VALID NUMBER,
                return (f_I);    //INCREASES THE CONTROL AND OF THE CONMTROL IS EQUAL TO N(USER ENTERED NUMBER) IT RETURNS THAT VALUE
            }
            f_I++;
        }
        return (f_I);
}

int validate_identity_number(char identity_number [])
{
    if (identity_number[0] == '0')
        return (0);
    int i = 0;
    while (identity_number[i] >= '0' && identity_number[i] <= '9')
        i++;
    if (i != 11) // DIGIT NUMBER AND DIGIT OR NOT CONTROL. FIRST AND SECOND CONTROL AT THE SAME TIME
        return (0);
    int odd = ((identity_number[0] - 48) + (identity_number[2] - 48) + (identity_number[4] - 48) + (identity_number[6] - 48) + (identity_number[8] - 48));
    int even = ((identity_number[1] - 48) + (identity_number[3] - 48)+ (identity_number[5] - 48) + (identity_number[7] - 48));
    if ((odd * 7 - even) % 10 != (identity_number[9] - 48)) // 4TH CONTROL
        return (0);
    if ((odd + even + (identity_number[9] - 48)) % 10 != (identity_number[10] - 48)) // 5TH CONTROL
        return 0;
    return 1;
}

int create_customer(char identity_number[], int password)
{
    if (password < 10000 && password > 999) // USER CAN ENTER 0 AT THE BEGINNING. FOR EX. 0569 WİLL CAUSE PASSWORD TO BE 569
    {FILE *ptr = fopen("customeraccount.txt","w");
    fprintf(ptr,"%s,%d",identity_number,password);
    fclose(ptr);
    return (1);
    }
    return (0);
}

int check_login(char identity_number [], int password)
{
    int i = 0;
    int temp_int = 0;
    char temp[16];
    FILE *ptr = fopen("customeraccount.txt","r");
    fscanf(ptr, "%s",temp);              // GET ALL OF THE TEXT,
    while (i < 16)
    {
        if (i < 11 && temp[i] != identity_number[i])  // CONTROL THE TEXT FOR 11 CHARACTER WHIC IS ID. IF ID DOES NOT FIT , RETURN 0
        return (0);
        else if (i > 11 && i < 16) // AFTER 11 CHARACTER CHECK FOR THE PASSWORD WHICH IS IN THE FORM OF CHARACTER AND MAKE IT INT
        {
            temp_int = temp_int * 10 + (temp[i] - 48);
        }
        i++;
    }
    if (password != temp_int) // CHECK PASSWOR IF IT IS TRUE OR NOT
    return (0);
    return (1);
}

int withdrawable_amount(float cash_amount)
{
        if ((int)cash_amount < cash_amount || (int)cash_amount % 10 != 0)
        {
            return (0);
        }
        return (1);
}