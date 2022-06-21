#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int findFirstDigit(int num)		//Used in hist_of_firstdigit function to find first digit.
{
	int digitNum = 0;
	int temp = num;

	while (temp != 0)	//Find digit number of 'num'
	{
		digitNum++;
		temp = temp/10;
	}
	
	while (digitNum - 1 != 0)	//Find first digit of 'num'
	{
		num = num / 10;
		digitNum--;
	}
	return (num);
}

void generate_sequence (int xs/*First element*/, int currentlen, int seqlen, int *seq)
{
	if (currentlen == seqlen - 1)   //If sequence is finished 
	{
		seq[currentlen] = xs;
		return ;
	}

	else
	{
		if (xs % 2 == 0)    //Even number : x/2
		{
			seq[currentlen] = xs;
			generate_sequence (xs/2, currentlen + 1, seqlen, seq);
		}

		else if (xs % 2 == 1)   //Odd number : 3*x + 1
		{
			seq[currentlen] = xs;
			generate_sequence (3*xs+1, currentlen + 1, seqlen, seq);
		}

	}
}

int has_loop(int *arr, int n, int looplen, int *ls, int *le)
{
		int *firstPart = malloc(sizeof(int)*(looplen));    //Checking if there is a loop in the array with two array comparison
		int *secondPart = malloc (sizeof(int)*(looplen));
		int i, j,k, temp = 0, counter = 0;
		int keepReading = 1;
		int firstIndex, secondIndex;

		while (keepReading)
		{
			k = 0;
			for (i = temp; i < looplen + temp; i++)    //Copy first part of comparison array
			{
				firstPart[k] = arr[i];
				k++;
			}

			k = 0;
			for (j = i; j < i + looplen ;j++)   //Copy second part of comparison array
			{
				secondPart[k] = arr[j];
				k++;
			}

			for (i = 0; i < looplen; i++)
			{
				if (firstPart[i] == secondPart[i])
					counter++;
			}

				if (counter == looplen)     //If counter == looplen, it means there is a loop.
				{
					*ls = temp;               //ls pointer (loop start) holds the first index of loop         
					*le = temp + looplen - 1;     //le pointer (loop end) holds the last index of loop
					// printf("ADRESS OF FIRST INDEX : %d, ADRESS OF SECOND INDEX : %d\n",ls,le);
					return (1);
				}

				else if (looplen * 2 + temp == n)   // If this equation is satisfied, it means every possibilities are checked and could not find loop 
				{
					keepReading = 0;
				}
			temp++;
			counter = 0;   //After every iteration, we must reset counter because accumulation can cause (counter == loople)
		}

		//Free arrays if you could not find any loop.
		free(firstPart);    
		free(secondPart);
	return (0);
}

void check_loop_iterative(void (*f)(int, int, int, int *), int xs, int seqlen, int *loop, int *looplen)
{
	/*create new sequence*/

	int *ary = malloc(sizeof(int)*seqlen);
	f(xs,0,seqlen,ary);

	/*Print this sequence*/
	if (*looplen == seqlen / 2)
	{
		printf("Sequence: {");
		for (int i = 0; i < seqlen; i++)
		{
			printf("%d, ",ary[i]);
		}
		printf("\b\b}\n");
	}


	/*Check with loop if there is a loop. If not, use recursive to lower looplen*/

	if (*looplen >= 3)   //Loop len can not be shorter than 3 elementh
	{
		printf("Checking if there is a loop of lenght %d...\n",(*looplen));
		
		int ls,le;

		if (has_loop(ary,seqlen,*looplen,&ls,&le) == 1)    //If there is a loop
		{
			printf("\n\n\nLoop detected with a lenght of %d.\n",*looplen);
			printf("The indexes of the loop's first occurance: %d(first digit), %d(last digit)\n",ls,le);

			int k = 0;
			for (int i = ls; i <= le; i++)	//Assigning loop's values into loop array
			{
				loop[k] = ary[i];
				k++; 
			}
		}

		else   //If there are no loop, try with ''' 1 LESS LOOPLEN ''' by recursive
		{
			/*Free array if there is no loop found on this looplen and try with lower looplen.*/
			free(ary);

			*looplen = *looplen - 1;
			check_loop_iterative(f,xs,seqlen,loop,looplen);
		}
	}
	else
	{
		*looplen = 0;
		printf("No loop found.\n");   //If loop lenght is less than 3, it means no loop found.
	}
}

void hist_of_firstdigits(void (*f)(int, int, int, int *), int xs, int seqlen, int *h, int digit)
{
	
	if (digit == seqlen)
		return ;
	
	else
	{
		
		int *ptr = malloc(sizeof(int)*seqlen);		//Allocate memory for array
		f(xs,0,seqlen,ptr);							//Generate array

		int firstDigit = findFirstDigit(ptr[digit]); 
		h[firstDigit-1] += 1;
		hist_of_firstdigits(f,xs,seqlen,h,++digit);

		free(ptr);									//Free generated arrays after every recursive
	}
}

int main()
{
	int *collatzArray;
	int seqLen;
	int firstElement;

	printf("-->> Please enter the sequence lenght : ");
	scanf("%d",&seqLen);

	printf("->> Please enter the first element : ");
	scanf("%d",&firstElement);

	int *mainLoop = calloc(seqLen,sizeof(int));		//Loop array 
	int loopLen = seqLen / 2;    //return adress of loop and it's lenght

	check_loop_iterative(generate_sequence, firstElement, seqLen, mainLoop, &loopLen);

	if (mainLoop[0] != 0)
	{
		printf("Loop: {");                          //PRINTING LOOP IN MAIN
			for (int i = 0; i < loopLen; i++)
				printf("%d, ",mainLoop[i]);
			printf("\b\b}\n");
	}

	int *histogram = calloc(9,sizeof(int));	//Histogram of first digits
	int digit = 0;		//Last parameter is for base condition of recursive

	hist_of_firstdigits(generate_sequence, firstElement, seqLen, histogram,digit);

	printf("Histogram of the sequence: {");
	for (int i = 0; i < 9; i++)
	{
		printf("%d, ",histogram[i]);
	}
	printf("\b\b}");

	//Free dynamic allocated memory
	free(histogram);
	free(mainLoop);
	free(collatzArray);  
	return (0);
}