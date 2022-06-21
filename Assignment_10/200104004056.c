#include <stdio.h>
#include <stdlib.h>

//************************************************************************READ ME*************************************************************************************************************
//**Sir I used characters instead of integers for disks because working with symbols feels to be more logical. Since I used char data type, after 10 number disk, weird symbols will shop up**
//********************************************************************************************************************************************************************************************

#define STACK_BLOCK_SIZE 10

typedef struct{

	int currentSize;
	int maxSize;
	char *array;

}stack;

int requiredMove(int diskAmount, stack **source, stack **axulry, stack **dest)
{
	if (diskAmount <= 0)
	{
		printf("\033[0;31m Invalid Disk Amount!!!!\033[0m\n");
		return (-1);
	}
	else
	{
		int a = 2;
		for (int i = 0; i < diskAmount - 1; i++)
		{
			a *= 2;
		}
		return (a);
	}
}

stack* init_return()
{
	stack *ptr = calloc(1,sizeof(stack));

	ptr->array = calloc(STACK_BLOCK_SIZE,sizeof(char));
	ptr->currentSize = 0;
	ptr->maxSize = STACK_BLOCK_SIZE;

	return (ptr);
}

void push(stack *stc, char add)		//	Push function will be void.
{
	if (stc ->currentSize >= stc->maxSize)		//	If stack si full
	{
		char *newStack = (char *)calloc(stc->maxSize+STACK_BLOCK_SIZE,sizeof(char));

		stc->maxSize += STACK_BLOCK_SIZE;		//	Increment max value of stack
		
		int i;

		for (i = 0; i < stc->currentSize; i++)	//	Copy old stack into new one
		{
			newStack[i] = stc->array[i];
		}

		newStack[i] = add;
		stc-> array = newStack;
		stc->currentSize++;
	}
	
	else
	{
		stc->array[(stc->currentSize)++] = add;
	}
}

char pop(stack *stc)
{
	if (stc->currentSize == 0)	//	If stack's current size is 0, it means there are no element in stack 
	{
		return (0);
	}
	else
	{
		stc->currentSize -= 1;	//		Since we poped , we must decrement the size by 1 
		return (stc->array[stc->currentSize]);
	}
}

int init(stack *stc)
{
	if (stc == NULL)	//	If stack pointer has null, there is a problem
	{
		printf("Error while creating stack !!!!!\n");
		return (-1);
	}
	else
	{
		printf("Stack is created successfully...\n");
		return (0);
	}
}

void printStack(stack *stc)
{
	if (stc->currentSize == 0)	//	If stack is empty, nothing to show
	{
	}
	else
	{
		int i = 0;

		while (i < stc->currentSize)
		{
			printf("%c ",stc->array[i]);
			i++;
		}
	}
}

void moveDisks(stack **src, stack **dst)
{
	// Get the adresses of src and dst inside a double pointer (because they are already a pointer) and move relevant disks

	char sourceTopDisk = pop(*src);
    char destTopDisk = pop(*dst);
	char temp;
 
    // When source stack is empty
    if (sourceTopDisk == 0)
    {
        push(*src, destTopDisk);
    }
 
    // When destination stack is empty
    else if (destTopDisk == 0)
    {
        push(*dst, sourceTopDisk);
    }
 
    // When ascii value of top element of source is larger than dest
    else if (sourceTopDisk > destTopDisk)
    {
        push(*src, sourceTopDisk);
        push(*src, destTopDisk);
    }
 
    // When ascii value of top element of source is smaller than dest
    else
    {
        push(*dst, destTopDisk);
        push(*dst, sourceTopDisk);
    }
}

void hanoi(int (*f)(int, stack **, stack **, stack **), void (*p)(stack** , stack**),stack *rod_1, stack *rod_2, stack *rod_3, int diskAmount)
{
	/*
	ROD 1 = SOURCE;
	ROD 2 = AXULRY;
	ROD 3 = DEST;
	*/

	int requiredMove = f(diskAmount,&rod_1,&rod_2,&rod_3);
	char temp;	//	Used for pop and push commands


	for (int i = 1; i < requiredMove; i++)
	{
		printf("\nNumber of Move : %d",i);
		if (i % 3 == 1)		//	Between source and destination pole. 
		{
			p(&rod_1, &rod_3);
				printf("\n\nRod1: ");
				printStack(rod_1);
				printf("\nRod2: ");
				printStack(rod_2);
				printf("\nRod3: ");
				printStack(rod_3);
		}

		else if (i % 3 == 2)	//	Source and axulry
		{
			p(&rod_1, &rod_2);
				printf("\n\nRod1: ");
				printStack(rod_1);
				printf("\nRod2: ");
				printStack(rod_2);
				printf("\nRod3: ");
				printStack(rod_3);
		}

		else if (i % 3 == 0)	//	Axulry and dest
		{
			p(&rod_2,&rod_3);
				printf("\n\nRod1: ");
				printStack(rod_1);
				printf("\nRod2: ");
				printStack(rod_2);
				printf("\nRod3: ");
				printStack(rod_3);
		}
	}
	printf("\n\n");
}

int main(){

	stack *myStack = init_return();	//	Initilize stack
	init(myStack);

	stack *rod_1 = init_return();	//	Start rod
	stack *rod_2 = init_return();	//	Axuliry rod
	stack *rod_3 = init_return();	//	Destination rod


	printf("\033[0;35mEnter Tower Size: \033[0m");
	int towerSize;
	scanf("%d",&towerSize);

	for (int i = towerSize; i > 0; i--)		//	Put discs into rod1
	{
		push(rod_1,i + 48);
	}

	int (*f)(int, stack**, stack **, stack **) = &requiredMove;		//	Fucntion pointer for required move function.
	void (*p)(stack **, stack **) = &moveDisks;
	hanoi(f, p, rod_1, rod_2, rod_3, towerSize);		//		Pass fucntion pointer into hanoi funct
	

	printf("After Eveytrhing...........................\n");

	printf("\nRod1: ");
	printStack(rod_1);
	printf("\nRod2: ");
	printStack(rod_2);
	printf("\nRod3: ");
	printStack(rod_3);
		



	free(myStack->array);		//	Free occupied places
	free(myStack->array);


    return 0;
}