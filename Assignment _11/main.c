#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
.						I DID NOT DO THE INSERT_KEY FUNCTION
.						I DID NOT DO THE FILE FUNCTOINS EITHER 
*/

typedef struct database {
	struct tables * tList; 			/* to be implemented as a linked list */
	int n; 						/* num of entries */
	char * name; 				/* table name */
} database;

typedef struct tables {
	struct tables *next;
	char *name;
	struct table *t;
} tables;

typedef struct table {
	char **field;
	char **type;
	bool *isNull;
	bool *isKey;
} table;

char **splitString(char *str)
{
	char *controlArray = " ";
	char **result = calloc(20,sizeof(char*));	//	Create enough space for splitted string 
	for (int i = 0; i < 20; i++)
		result[i] = calloc(50,sizeof(char));

	char *token = strtok(str,controlArray);	//Use strtok to break the incomming string apart
	int i = 0;

	while (token != NULL)		//Contiuny breaking the string up untill it is finished
	{
		if (i > 19)	//	To stop iteration
			break;
		strcpy(result[i],token);
		i++;
		token = strtok(NULL,controlArray);
	}
	return (result);	//Return broken string
}

database* create_database(char *name)
{
	database *ptr = malloc(sizeof(database)*1);	//	Allocate space for database
	ptr->name = calloc(30,sizeof(char));		//	Allocate space for database name
	ptr->tList = calloc(1,sizeof(tables));
	ptr->tList->t = NULL;
	strcpy(ptr->name,name);		//	Database's name
	ptr->n = 0;		//	Entriy amount is inittially 0
	return (ptr);
}

void show_table(database *d)
{		
	if (d->tList == NULL)			//	If there is no table to show
	{
		printf("No table to show.....");
	}
	
	else									//	If there are multiple elements
	{
		tables *iter = d->tList;	//	Iterator which allows me to hang around linked list
		printf("Tables Names.....\n");

		while (iter != NULL)	//	Show elements untill you reached the last element
		{
			printf("%s\n",iter->name);
			iter = iter->next;
		}
	}
	return ;
}

void desc_table(database *d, table *t)
{
	printf("|---------------------------------------------------|\n");
	printf("|   FIELD     |   TYPE     |   NULL     |   KEY     |\n");
	printf("|---------------------------------------------------|\n");
	for (int i = 0; t->field[i] != NULL; i++)	//	Until field is null, keep printing because field being finished indicates that tables are over
	{
		printf("| %s         %s            %d                %d  \n",t->field[i],t->type[i],t->isNull,t->isKey);
	}
}

void insert_table(database *d, table *t, char *tableName)
{
	if (d->tList->t == NULL)		//	No elements initially
	{
		d->tList->name = tableName;
		d->tList->t = t;
		d->tList->next = NULL;
		d->n = d->n + 1;
	}

	else if (d->tList->t != NULL && d->tList->next == NULL)		//	Only 1 element
	{
		tables *newTable = calloc(1,sizeof(tables));
		d->tList->next = newTable;
		newTable->name = tableName;
		newTable->t = t;
		newTable->next = NULL;
		d->n = d->n + 1;
	}

	else			//	Multiple element
	{
		tables *iter = d->tList;

		while (iter->next != NULL)		//Search for the last element of list
		{
			//printf("Names are : %s\n",iter->name);
			iter = iter->next;
		}
		tables *newTable = calloc(1,sizeof(tables));	//	Create a proper place for new table

		iter->next = newTable;		//	Allocate new places adress
		newTable->name = tableName;		//	Assign their values
		newTable->t = t;
		newTable->next = NULL;
		d->n = d->n + 1;
	}

	printf("\033[0;35mTABLE IS INSERTED.....\033[0m;\n");
}

void remove_table(database *d, char *name)
{
	tables *iter = d->tList;

	if (strcmp(iter->name,name) == 0)	//	If first element is deleted
	{
		printf("First element is deleted...\n");
		tables *temp;
		d->tList = d->tList->next;
		free(iter);
		d->n = d->n - 1;
		return ;
	}

	while (strcmp(iter->next->name,name) != 0 && iter->next != NULL)
	{
		iter = iter->next;
	}
	tables *temp = iter->next;
	iter ->next = iter -> next -> next;
	d->n = d->n - 1;
	printf("Element is deleted...\n");
	free(temp);
}

void readFromFile(FILE *filePtr)
{
	
}

void writeIntoFile(database *Dtbase)
{
	FILE *filePointer = fopen(Dtbase->name,"a+");
	tables *iter = Dtbase->tList;


	for (int i = 0; i < Dtbase->n; i++)
	{
		//	WRITING STYLE  IS : "table_name field[0] field[1]... type[0] type[1]... isNull isKey table_name field[0] field[1]... type[0] type[1]... isNull isKey  

		fprintf(filePointer,"%s ",iter->name);
		for (int k = 0; iter->t->field[k] != NULL; k++)
			fprintf(filePointer,"%s ",iter->t->field[k]);
		for (int k = 0; iter->t->field[k] != NULL; k++)
			fprintf(filePointer,"%s ",iter->t->type[k]);

		fprintf(filePointer,"%s ",iter->t->isNull);
		fprintf(filePointer,"%s ",iter->t->isKey);
		iter = iter->next;
		fprintf(filePointer,"\n");
	}
	fclose(filePointer);
}

void clearBuffer()
{
	while (getchar() != '\n');
}


int main()
{
	char	inputBuffer[500];
	char	**splittedInput;

	database *ptr;	//	Allocate space for database

	//		Here are the buried commands


	int counter = 0;
	do
	{
		printf("\033[0;32mMySQL>  \033[0m");
		scanf("%[^\n]s",inputBuffer);	

		splittedInput = splitString(inputBuffer);

		if (strncmp(inputBuffer,"EXIT",4) == 0)
			return(0);	//	Kill the program

		else if (strncmp(splittedInput[0],"CREATE",6) == 0 && strncmp(splittedInput[1],"DATABASE",8) == 0)
		{
			if (splittedInput[2][0] == '\0')	//	If database name is not entered
			{
				printf("Failed to create database.....\n");
			}
			else
			{	printf("Database created successfully.....\n");
				ptr = create_database(splittedInput[2]);	//	Database is created
			}
		}

		else if (strncmp(splittedInput[0],"SHOW",4) == 0)
		{
			show_table(ptr);
		}

		else if (strncmp(splittedInput[0],"DESCRIBE",8) == 0)
		{
			tables	*iter = ptr->tList;
			
			while (strcmp(iter->name,splittedInput[1]) != 0 && iter->next != NULL)	//	Find the wanted table name
			{
				iter = iter->next;
			}

			desc_table(ptr,iter->t);	//	Print all the elements of table 
		}

		else if (strncmp(splittedInput[0],"CREATE",6) == 0 && strncmp(splittedInput[1],"TABLE",5) == 0)
		{
			table *newTable = malloc(sizeof(table)*1);

			int k = 0;

			newTable->field = malloc(sizeof(char *)*20);	//	Creating place for field and type variables
			newTable->type = malloc(sizeof(char *)*20);		//	If we dont allocate, we wont be able to store user entered strings as variables of table
						
			for (int i = 3; splittedInput[i][0] != '\0'; i++)	//	Insert user entered variables of table into struct before connecting table
			{
				newTable->field[k] = calloc(30,sizeof(char));
				newTable->type[k] = calloc(30,sizeof(char));
				strcpy(newTable->field[k],splittedInput[i]);
				strcpy(newTable->type[k],splittedInput[++i]);
				newTable->isKey = 0;
				newTable->isNull = 0;
				k++;
			}
			
			insert_table(ptr,newTable,splittedInput[2]);
		}


		else if (strncmp(splittedInput[0],"DROP",4) == 0 && strncmp(splittedInput[1],"TABLE",5) == 0)
		{
			remove_table(ptr,splittedInput[2]);
		}

		clearBuffer();	//	Clear İnput buffer
	} while (1);
	

	return (0);
}