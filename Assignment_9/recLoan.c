#include <stdio.h>
#include <stdlib.h>
// amount * (1+interest) * (1+interest) * (1+interest)

float loan(float amount, int period, float interestRate)
{
	float sum = 0.0;
	if (period == 1)	//Base Condition
	{
		return amount*(1+interestRate);
	}
	else
	{
		sum = (1+interestRate)*loan(amount,--period, interestRate);
	}
	return sum;
}

int main()
{
	printf("Enter amount : ");
	float amount;

	scanf("%f",&amount);

	printf("Loan amount = %f\n",loan(amount,12,1));

	printf("<<%f>>",atof("123.45"));

	return (0);
}