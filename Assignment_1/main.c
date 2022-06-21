#include <stdio.h>
#include "utils.c"

int main()
{
    int x, y, z, big, smal, result, n = 0; //N IS EQUAL TO ZERO AS DEMANDED BY TEACHER
    //INSERTING NUMBERS
    printf("Enter the first integer: ");     
    scanf("%d",&x);
    printf("\n");
    printf("Enter the second integer: ");
    scanf("%d",&y);
    printf("\n");
    printf("Enter the devisior: ");
    scanf("%d",&z);
    printf("\n");
    //CHECK WHIC IS BIGGER IN CASE USER ENTERED NUMBERS RANDOMLY
    big = y;
    smal = x;
    result = find_divisible(x,y,z);
    if (!(result <= big && result >= smal))
    {
        printf("There is not any integer between %d and %d can be divided by %d",big,smal,z);
        return (0);
    }
    printf("The first integer between %d and %d divided by %d is %d",smal,big,z,result);
    printf("\n");
    printf("Enter the number how many next: ");
    scanf("%d",&n);
    if (n < 0)
    {
        printf("n must be greater than 0");
        return (0);
    }
    printf("\n");
    result = find_nth_divisible(n,result,z);
    if (result > big)
    {
        printf("No possible to find Nth divisible between %d and %d divided by %d",smal,big,z);
        return (-999);
    }
    if (n % 10 == 1)        // IF USER WANTED THE FIRST NUMBER AS N = 1, PROGRAM WILL WRITE ST AT THE END OF %d (st), JUST LIKE FIRST n=2 (nd) , n=3 (rd).
        printf("The %dst integer between %d and %d divided by %d is %d ",n,smal,big,z,result);
        else if (n % 10 == 2)
        printf("The %dnd integer between %d and %d divided by %d is %d ",n,smal,big,z,result);
        else if (n % 10 == 3)
        printf("The %drd integer between %d and %d divided by %d is %d ",n,smal,big,z,result);
        else
        printf("The %dth integer between %d and %d divided by %d is %d ",n,smal,big,z,result);
    //****************************** PART 2*************************************************
    printf("\n");
    char ary[11];
    int psw;
    printf("ENTER YOUR ID NUM : ");
    scanf("%s",ary);
    if (validate_identity_number(ary) == 1)
    {
        printf("ENTER YOUR PASSWORD : ");
        scanf("%d",&psw);
        int create_cus = create_customer(ary,psw);
        if (create_cus == 0)
        {
            printf("Invalid identity number or password");
            return (0);
        }
    }
    else if (validate_identity_number(ary) == 0)
    {
    printf("Invalid identity number or password");
    return (0);
    }
    //********************************PART 3****************************************
    char check_ary[11];
    int check_psw;
    printf("ENTER YOUR ID : ");
    scanf("%s",check_ary);
    printf("ENTER YOUR PASSWORD : ");
    scanf("%d",&check_psw);
    if (check_login(check_ary,check_psw) != 1)
    printf("Invalid identity number or password\n");
    else if (check_login(check_ary,check_psw) == 1)
    printf("LOGIN SUCCEFUL\n");
    float withdraw;
    int withdrawable_Amount;
    printf("Enter your withdraw amount: ");
    scanf("%f",&withdraw);
    if (withdrawable_amount(withdraw) == 0)
    {
        withdrawable_Amount = (int)withdraw - ((int)withdraw % 10);
        printf("Withdrawable amount is: %d",withdrawable_Amount);
        return (0);
    }
    printf("WITHDRAW IS SUCCESSFUL :) HAVE A GREAT DAY ");
    return (0);
}