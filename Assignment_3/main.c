#include <stdio.h>
#include <math.h>

int sum (int n1, int n2, int flag)
{
    int sum = 0;

    if (flag == 0){ // work on even numbers
        if (n1 % 2 != 0) // If the number ıs not even initially , make it even and do not take initial
            n1 +=1;
        else if (n1 % 2 == 0)
            n1 += 2;

        while (n1 <= n2){
            if (n1 == n2)
                printf("\b");
            else if (n1 % 2 == 0){
                printf(" %d +",n1);
                sum += n1;
            }
            n1++;
        }
        return (sum);
    }

    else if (flag == 1){ //WORK ON ODD NUMBERS
        if (n1 % 2 == 0) // If the number ıs not odd initially , make it odd
            n1 +=1;
        else if (n1 % 2 != 0)
            n1 += 2;
        while (n1 <= n2){
            if (n1 == n2)
                printf("\b");
            else if (n1 % 2 != 0){
                printf(" %d +",n1);
                sum +=n1;
            }
            n1++;
        }
        return (sum);
    }
}

int multi (int n1, int n2, int flag)
{
    int sum = 1;

       if (flag == 0){ // work on even numbers
        if (n1 % 2 != 0) // If the number ıs not even initially , make it even and do not take initial
            n1 +=1;
        else if (n1 % 2 == 0)
            n1 += 2;

        while (n1 <= n2){
            if (n1 == n2)
                printf("\b");
            else if (n1 % 2 == 0){
                printf(" %d *",n1);
                sum *= n1;
            }
            n1++;
        }
        return (sum);
       }

     else if (flag == 1){ //WORK ON ODD NUMBERS
        if (n1 % 2 == 0) // If the number ıs not odd initially , make it odd
            n1 +=1;
        else if (n1 % 2 != 0)
            n1 += 2;
        while (n1 <= n2){
            if (n1 == n2)
                printf("\b");
            else if (n1 % 2 != 0){
                printf(" %d *",n1);
                sum *=n1;
            }
            n1++;
        }
        return (sum);
     }
}

int isprime (int a)
{
    int i;

    for (i = 2; i <=  sqrt(a); i++){
        if (a % i == 0)
        return (i);
    }
    return (0);
}

void print_file ()
{
    FILE *fp = fopen("result.txt","r");

    int temp;

    while (!feof(fp)){
        fscanf(fp,"%d ",&temp);
        printf("%d ",temp);
    }
    fclose(fp);
}

void write_file (int number)
{
    FILE *fp = fopen("result.txt","a+");
        fprintf(fp,"%d ",number);
    fclose(fp);
}

int file_size() // FIND HOW MANY NUMBER IN result.txt FILE
{
    int i = 0,temp;
    FILE *ptr = fopen("result.txt","r");

    while (!feof(ptr)){
        fscanf(ptr,"%d ",&temp);
        i++;
    }
    fclose(ptr);
    return (i);
}

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

	else if (a > 10){
		sum += found_digit(a / 10);
	}

	if(a)
	return (sum);
}

void delete_number(int a, int b, int c) // DELETE SPESIFIC NUM'S FROM FILE
{
    FILE *fp =  fopen("result.txt","r");
    FILE *ptr = fopen("tempp_2.txt","a");
    int temp;
    
    while (!feof(fp)){
        fscanf(fp,"%d",&temp);

        if (temp != a && temp != b && temp != c){

            fprintf(ptr,"%d ",temp);
        }
    }

    fclose(ptr);
    fclose(fp);
    remove("result.txt");
    rename("tempp_2.txt","result.txt");
}


void sort_file()
{
    int min1 = 2147483647, min2 = 2147483647, min3 = 2147483647;

        /* min numbers are assıgnt to max ınt value. By doıng thıs every number comıng
        from fıle ısgonna be lower than thıs number and ıt makes sortıng easier*/

    int temp;
    int size = file_size(); //result's size 

    if (size % 3 > 0)   // how many steps result will be checked
        size = size / 3 + 1;
    else if (size % 3 == 0)
        size = size/3;

    FILE *file_2 = fopen("file_2.txt", "a+");

    for (int i = 0; i < size; i++){  // STEPS ARE DONE HERE

    min1 = 2147483647, min2 = 2147483647, min3 = 2147483647;
    
        FILE *ptr = fopen("result.txt","r");

        while (!feof(ptr)){ //  FINDING MINS IN EVERY STEP
            fscanf(ptr,"%d ",&temp);
            if (temp < min2 && temp < min3){
                if (temp > min1){
                    min3 = min2;
                    min2 = temp;
                }
                else if (temp < min1){
                    min3 = min2;
                    min2 = min1;
                    min1 = temp;
                }
            }
            else if (temp > min2 && temp < min3){
                min3 = temp;
            }
        }

        // WRITE MIN VALUES INTO FILE2
        if (min1 != 2147483647)
             fprintf(file_2,"%d ",min1);
        if (min2 != 2147483647)
             fprintf(file_2,"%d ",min2);
        if (min3 != 2147483647)
            fprintf(file_2,"%d ",min3);
        
        fclose(ptr);
        
        delete_number(min1,min2,min3); // DELETE min num's from result.txt
    }
    fclose(file_2);
    remove("result.txt");
    rename("file_2.txt","result.txt");
    
}

int main()
{
    printf("SELECT OPERATION\n");                                   // STARTS AT 122
    printf("1. Calculate sum/multiplication between two numbers\n");
    printf("2. Calculate prime numbers\n");
    printf("3. Show number sequence in file\n");
    printf("4. Sort number sequence in file\n");
    printf("---------------------\n");

    int op_flag;
    scanf("%d",&op_flag);

    switch (op_flag){ // SWITCASE FOR OPERATIONS
        case 1:
                printf("Please enter '0' for sum, '1' for multiplication\n");
                    int num_flag;
                    scanf("%d",&num_flag);
                    if (num_flag < 0 || num_flag > 1){
                        printf("INVALID NUMBER !!!!!");
                        return (0);
                    }
                printf("Please enter '0' to work on even number, '1' to work on odd numbers\n");
                    int even_odd;
                    scanf("%d",&even_odd);
                    if (even_odd < 0 || even_odd > 1){
                        printf("INVALID NUMBER !!!!!");
                        return (0);
                    }
                printf("Please enter 2 different number:\n");
                printf("Number 1:");
                int num1;
                scanf("%d",&num1);
                printf("Number 2:");
                int num2;
                scanf("%d",&num2);
                if (num1 == num2){
                        printf("NUMBERS ARE EQUAL!!!!!");
                        return (0);
                }
                printf("Result\n");

                if (num_flag == 0){ // sum
                    int sum_result = sum(num1,num2,even_odd);
                    write_file(sum_result);
                    printf(" = %d",sum_result);
                }
                else if (num_flag == 1){ // multiplication
                    int mult_result = multi(num1,num2,even_odd);
                    write_file(mult_result);
                    printf(" = %d",mult_result);
                }  
            break;
    case 2:
                ;
            int i, prime, temp;

            printf("Please enter an integer : ");
            scanf("%d",&prime);

            for(i = 2; i < prime; i++){
                temp = isprime(i);
                if (temp == 0)
                    printf("%d is a prime number\n",i);
                else{
                    printf("%d is not a prime number, it is devidible by %d\n",i,temp);
                }
            }
            break;
    case 3:
            printf("Result : ");
            print_file ();
            break;
    case 4:
            sort_file();
            print_file();
            break;

        default:
            printf("INVALID CHOOSE!!!");
            break;
        }
    return (0);
}