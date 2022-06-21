#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//	Sir, I used files more than you expected because the homework was too complicated for me to understand. I got very confused how to use unions similar to structs so that ı used files.
//	I wrote a string breaking function which allowed me to check every information. I hope it is good enough for you :/

//	List customer fonksiyonunda loan kısmını bastırmıyor. Loan fonksiyonunda sıkıntı yok ama

typedef union Person
{
	int ID;
	char name[50]; 
	char address[50];
	int phone;
}Person;

typedef union Loan 
{
	float values[4]; 	// 0: amount , 1: period , 2: interestRate , 3: How many rights you have to get loan
}Loan;

typedef struct BankAccount
{
	union Person Customer;
	union Loan Loans[3];
}BankAccount;

float calculateLoan(float amount, int period, float interestRate);

void listCustomers(BankAccount *ptr, int customerAmount, int loanIndex);

void addCustomer (BankAccount *ptr, int *index);

char **splitString(char *str);

void newLoan(int index, BankAccount *ptr, int loanIndex);

void getReport(int customerId, int customerAmount);

int main()  
{
	int choice;
	int index = 0;	//	How many customers there are.

	FILE *ptr = fopen("customer.txt","r");

	char c;
	do
	{
		c= getc(ptr);
		if(c == '\n')	index++;
	}
	while (c != EOF);

	BankAccount customers[50];	/*Customer database*/

	do{
	printf("=====================================\n");
	printf("\033[0;36mWELCOME TO THE BANK MANAGEMENT SYSTEM\033[0m\n");
	printf("=====================================\n");
	printf("1.List all customers\n2.Add new customer\n3.New loan application\n4.Report menu\n5.Exit menu\n--->> ");
	scanf("%d",&choice);

	if (choice > 5 || choice < 1)	//Wrong input dealing
	{
		printf("\033[0;31m\nYou entered an invalid option. Please try again\n\033[0m");
		while (getc(stdin) != '\n');
	}
	else{

		switch(choice)
		{
			case 1:
			FILE *loanPtr = fopen("loan.txt","r");

			int loanIndex = 0;	//Finding how many loans there are
			do
			{
				c= getc(loanPtr);
				if(c == '\n')	loanIndex++;
			}
			while (c != EOF);

			fclose(loanPtr);
			listCustomers(customers,index, loanIndex);
			
				break;

			case 2:
		
				if (index == 49)	//Customers array is full
				printf("\033[0;31mThe bank is full now, You can not add a customer now !! \033[0m\n");
				else
				{
					addCustomer(customers,&index);
					index++;
				}

			break;

			case 3:

				newLoan(index, customers,loanIndex);

				break;

			case 4:

			printf("Which customer's details you want to know (ENTER ID)->> ");
			int custId;
			scanf("%d",&custId);
			getReport(custId,index);

				break;
		}

	}
	}while(choice != 5);

	printf("\033[0;32m \n{HAVE A NICE DAY} \n\033[0m");
	return (0);
}

void getReport(int customerId,int customerAmount)
{
	FILE *file = fopen("customer.txt","r");
	char **str;
	char buffer[200];
	int flag = 0;
	float sum = 0.0;

	for (int i = 0; i < customerAmount; i++)	//If customer exist
	{
		fgets(buffer,200,file);
		str = splitString(buffer);
		if (atoi(str[0]) == customerId)
		{
			flag = 1;
			break;
		}
	}
	fclose(file);

	printf("Customer name : %s\n",str[1]);
	printf("Customer phone : %s\n",str[2]);
	printf("Customer adress : %s\n",str[3]);

	FILE *ptr = fopen("loan.txt","r");

	char **pooointeeerrr;

	printf("Customer's loans = [");		//Find all the loans that customer has
	for (int i = 0; i < customerAmount; i++)
	{
		fgets(buffer,200,ptr);
		pooointeeerrr = splitString(buffer);
		if (pooointeeerrr == NULL)
			break;
		if (atoi(pooointeeerrr[0]) == customerId)
		{
			sum += calculateLoan(atof(pooointeeerrr[1]),atoi(pooointeeerrr[2])/100,atof(pooointeeerrr[3]));
			printf("%f + ",calculateLoan(atof(pooointeeerrr[1]),atoi(pooointeeerrr[2])/100,atof(pooointeeerrr[3])));
		}
	}
	printf("\b\b]\n");

	for (int i = 0; i < 12; i++)	//Print monthly installments
	{
		printf("%d. Month installment = %f\n",i+1,sum/12);
	}

}

char **splitString(char *str)
{
	char *controlArray = ",";
	char **result = calloc(4,sizeof(char*));	//	Create enough space for splitted string 
	for (int i = 0; i < 4; i++)
		result[i] = calloc(50,sizeof(char));

	char *token = strtok(str,controlArray);	//Use strtok to break the incomming string apart
	int i = 0;

	while (token != NULL)		//Contiuny breaking the string up untill it is finished
	{
		if (i > 3)	//	To stop iteration
			break;
		strcpy(result[i],token);
		i++;
		token = strtok(NULL,controlArray);
	}
	return (result);	//Return broken string
}

void newLoan(int index, BankAccount *ptr, int loanIndex)
{
	FILE *custFile = fopen("customer.txt","r");
	int i;

	printf("ENTER ID : ");
	int customerID;
	scanf("%d",&customerID);
	char buffer[200];		//To hold values coming from customer.txt by fscanf
	char **holderString;	//To hold pointer returned from splitString
	int customerIsTrue = 0;	//To find if customer ID is true

	int flag = 0;	//To hold the info whether customer ID is valid or not

	FILE *loanFile = fopen("loan.txt","a+");

	for (i = 0; i < loanIndex; i++)		//Find how many loan that customer has
	{
		fgets(buffer,200,loanFile);
		holderString = splitString(buffer);
		if (atoi(holderString[0]) == customerID)
		{
			flag ++;
		}
	}
	fclose(loanFile);

	for (i = 0; i < index; i++)		//Find if customer exist
	{
		fgets(buffer,200,custFile);
		holderString = splitString(buffer);
		if (atoi(holderString[0]) == customerID)
		{
			customerIsTrue = 1;
			break;
		}
	}
	fclose(custFile);

	if (flag < 3 && customerIsTrue == 1)		//İf customer has loan less then three and customer exist, print
	{
		FILE *file = fopen("loan.txt","a+");
		printf("\033[0;32m YOUR ID IS RIGHT, WELCOME <%s>\033[0m\n",holderString[1]);
		fprintf(file,"%d,",atoi(holderString[0]));	//	Add ıd of customer first
		printf("Enter amount of loan : ");
		scanf("%f",&ptr[i].Loans->values[0]);
		fprintf(file,"%f,",ptr[i].Loans->values[0]);
			
		printf("Enter period of period : ");
		scanf("%f",&ptr[i].Loans->values[1]);
		fprintf(file,"%f,",ptr[i].Loans->values[1]);

		printf("Enter interestRate of loan : ");
		scanf("%f",&ptr[i].Loans->values[2]);
		fprintf(file,"%f,\n",ptr[i].Loans->values[2]);
		ptr[i].Loans->values[3] += 1;
		fclose(file);
	}

	else if (flag >= 3 && customerIsTrue == 1)	// If customer is exist but has more than 3 loan
	{
		printf("\033[0;31mYou can not get a loan. Pay of First Dudee !!!!!\033[0m\n");
	}

	else	//If customer does not exist
	{
		printf("\033[0;31mYOUR ID IS INVALID. PLEASE SING IN OR BE SURE YOU WRITE IT RIGHT\033[0m\n");
	}
}

void listCustomers(BankAccount *ptr, int customerAmount, int loanIndex)
{
	FILE *file = fopen("customer.txt","r");	//	Get user informations from text file into union and print.
	char buffer[200];
	char **str;
	int customerId;
	char **holderString;
	float temp = 0.0;
	float sum = 0.0;
	int flag = 0;

	for (int i = 0; i < customerAmount; i++)
	{
		fgets(buffer,200,file);
		str = splitString(buffer);

		ptr[i].Customer.ID = atoi(str[0]);	//Copy ID of customer into union data type
		customerId = atoi(str[0]);
		printf("Customer ID : %d\n",ptr[i].Customer.ID);


		strcpy(ptr[i].Customer.name,str[1]);	//Copy name of customer into union data type
		printf("Customer Name : %s\n",ptr[i].Customer.name);
		
		ptr[i].Customer.phone = atoi(str[2]);	//Copy phone of customer into union data type
		printf("Customer Phone : %d\n",ptr[i].Customer.phone);

		strcpy(ptr[i].Customer.address,str[3]);	//Copy adress of customer into union data type
		printf("Customer Address : %s\n",ptr[i].Customer.address);

		printf("Loans = [");
		FILE *LoanPtr = fopen("loan.txt","r");
		for (int k = 0; k < loanIndex; k++)		//Find how many loan that customer has
		{
			fgets(buffer,200,LoanPtr);
			holderString = splitString(buffer);
			// printf("customerId: %d___holderString : %d",customerId,atoi(holderString[0]));
			if (customerId == atoi(holderString[0]))
			{
				float x1 = 	atof(holderString[1]);
				int x2 = atoi(holderString[2]);
				float x3 = atof(holderString[3])/10;
				sum = calculateLoan(x1,x2,x3);
				printf("--> %.2f +",sum);
			}
		}
		printf("\b\b]");
		fclose(LoanPtr);
		printf("\n\n"); 		
	 	// printf("\b\b ] => %f",sum);
	}
	fclose(file);
}

float calculateLoan(float amount, int period, float interestRate)
{
	float sum = 0.0;
	if (period <= 1)	//Base Condition
	{
		return amount*(1+interestRate);
	}
	else
	{
		sum = (1+interestRate)*calculateLoan(amount,--period, interestRate);
	}
	return sum;
}

void addCustomer (BankAccount *ptr, int *index)
{
	FILE *file = fopen("customer.txt","a+");

	printf("Customer ID: ");
	scanf("%d",&ptr[*index].Customer.ID);
	fprintf(file,"%d,",ptr[*index].Customer.ID);	//Write into file

	printf("Customer Name : ");
	scanf(" %[^\n]%*c",ptr[*index].Customer.name);
	fprintf(file,"%s,",ptr[*index].Customer.name);
	
	printf("Customer Phone : ");
	scanf("%d",&ptr[*index].Customer.phone);
	fprintf(file,"%d,",ptr[*index].Customer.phone);
	
	printf("Customer Address : ");
	scanf(" %[^\n]%*c",ptr[*index].Customer.address);
	fprintf(file,"%s,\n",ptr[*index].Customer.address);

	printf("\033[0;32mCUSTOMER ADDED SUCCESSFULLY\n\033[0m");

	fclose(file);
}