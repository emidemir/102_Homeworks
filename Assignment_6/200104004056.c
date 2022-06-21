#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMap(char (*gameArea)[30])
{
	int i,j;
   for (i = 0; i < 15; i++)
   {
	   for (j = 0; j < 30; j++)
	   {            
			if (i % 2 != 0)  // Odd number rows**************
			{
				// 1 and 13, 3 and 11, 9-7-5 are same
				if (i == 1 || i == 13)
				{
					if (j == 0 || j == 29)
						gameArea[i][j] = ':';
					else
						gameArea[i][j] = ' ';
				}

				else if (i == 3 || i == 11)
				{
					if (j == 0 || j == 2 || j == 27 || j == 29)
						gameArea[i][j] = ':';
					 else
						gameArea[i][j] = ' ';
				}

				else if (i == 5 || i == 7 || i == 9)
				{
					if (j == 0 || j == 2 || j == 4 || j == 25 || j == 27 || j == 29)
						gameArea[i][j] = ':';
					else
						gameArea[i][j] = ' ';
				}
				
			}

			else // Even number rows ********************
			{
				// 4 ve 10 -- 2 ve 12 -- 6 ve 8 (These are same)
				if (i == 2 || i == 12)
				{
					if (j == 0 || j == 29)
						gameArea[i][j] = ':';
					else if (j == 1 || j == 28)
						gameArea[i][j] = ' ';
					else 
						gameArea[i][j] = '.';
				} 

				else if (i == 4 || i == 10)
				{
					if (j == 0 || j == 2 || j == 27 || j == 29)
						gameArea[i][j] = ':';
					else if (j == 1 || j == 3 || j == 26 || j == 28)
						gameArea[i][j] = ' ';
					else
						gameArea[i][j] = '.';
				}

				else if (i == 6 || i == 8)
				{
					if (j == 0 || j == 2 || j == 4 || j == 25 || j == 27 || j == 29)
						gameArea[i][j] = ':';
					else
						gameArea[i][j] = ' ';
				}
			}

			if (i == 0 || i == 14)   // First and last row
			   gameArea[i][j] = '.';
	   }
   }

   //gameArea[1][1] = '1';
   //gameArea[3][3] = '2';
   gameArea[1][14] = 'X';
   gameArea[7][28] = 'X';
   gameArea[13][14] = 'X';
   gameArea[3][10] = 'X';
   gameArea[3][18] = 'X';
   gameArea[5][26] = 'X';
   gameArea[10][26] = 'X';
   gameArea[11][10] = 'X';
   gameArea[11][18] = 'X';
   gameArea[2][1] = '_';
   gameArea[4][3] = '_';
} 

int dice()
{
	return (rand() %6 + 1);
}

int startGame()
{
	/*equalFlag = if dice's are equal, keep looping*/
	int equalFlag = 0;
	do
	{
		/*Dıce results*/
		int choiceFirst,choiceSecond;
		printf("\n\n\n\n\n\n\n");

		/*Printf stuff*/
		printf("To start the game, Players must dice.\n");
		printf("\033[0;33mPREES ENTER TO DICE FOR PLAYER 1 : ");
		if (getchar() == '\n')
			choiceFirst = dice();
		printf("DICE : %d\033[m\n",choiceFirst);
		 printf("\033[0;36mPREES ENTER TO DICE FOR PLAYER 2 : ");
		if (getchar() == '\n')
			choiceSecond = dice();
		printf("DICE : %d\033[0m\n",choiceSecond);

		/*Checking dice'S*/
		if (choiceFirst > choiceSecond)
		{
			printf("***PLAYER 1 WILL START THE GAME***\n");
			return (1);
		}
		else if (choiceSecond > choiceFirst)
		{
			printf("***PLAYER 2 WILL START THE GAME***\n");
			return (2);
		}
		else if (choiceFirst == choiceSecond)
		{
			printf("VALUES ARE SAME, DICE AGAIN.\n");
			equalFlag = 1;
			while(getchar() != '\n');   /*To clear the buffer*/
		}
	}while(equalFlag == 1); 
}

void displayMap(char (*gameMap)[30], int player1_x, int player1_y, int player2_x, int player2_y)
{
	/*Get values of 1 and 2 from gameFunction and use that info. Array already exist, ı just print it in this function*/
	/*To print '1' i = player1_x , j = player2_y*/
	/*To print '2' i = player2_x , j = player2_y*/
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (i == player1_x && j == player1_y)
				printf("\033[0;33m%c\033[0m",'1');
			else if (i == player2_x && j == player2_y)
				printf("\033[0;36m%c\033[0m",'2');
			else if (gameMap[i][j] == 'X')
				printf("\033[0;31m%c\033[0m",gameMap[i][j]);
			else if (gameMap[i][j] == '_')
				printf("\033[0;32m%c\033[0m",gameMap[i][j]);
			else
				printf("%c",gameMap[i][j]);
		}
		printf("\n");
	}
}

void gameFunction(char (*gameMap)[30], int firstPlayer)
{
	int i,j,flag;
	//int flipflop= firstPlayer;
	int player1,player2;    //Holding dice values
	int player1_x = 1,player1_y = 1,player2_x = 3,player2_y = 3; // 1-1 for player1, 3-3 for player2
	int keepReading = 0;	//As long as one player do not cross the finish line, game will contiuny

	/*If fınısh lınes are not changes, keep the game running*/
	while (keepReading == 0)
	{
		printf("\033[0;33mDICE FOR PLAYER 1 : ");
		getchar();
		player1 = dice();
		printf("Dice : %d\033[m\n",player1);
		printf("\033[0;36mDICE FOR PLAYER 2 : ");
		getchar();
		player2 = dice();
		printf("Dice : %d\033[m\n",player2);

		// Y value has 14 value parameter of array, X value has 28 value parameter of array
		// Y values moving right left , X value is moving up and down 

		if (firstPlayer == 1)	//if player 1 is starting
		{
			// Player 1 *****
			if (player1_x == 1)		//First row of player 1 is changing only
			{
				player1_y += player1;

				if (player1_y == 14)	//penalty point player1's first row
				{
					player1_y -= 2;
					printf("\033[0;33mPENALTY FOR PLAYER 1..\033[m\n");
				}

				if (player1_y >= 29)	//Corner of player1's first row
				{
					player1_x += player1_y - 28;
					player1_y = 28;
				}
			}

			else if (player1_y == 28)	//First colomn of player 1 is changing only
			{
				player1_x += player1;

				if (player1_x == 7)		//penalty point of player1's first colomn
				{
					printf("\033[0;33mPENALTY FOR PLAYER 1..\033[m\n");
					player1_x -= 2;
				}
				if (player1_x >= 14)	//corner of player1's first colomn
				{
					player1_y -= player1_x - 13;
					player1_x = 13;
				}
			}
			
			else if (player1_x == 13)	//Last row of player 1 is changing
			{
				player1_y -= player1;

				if (player1_y == 14)	//penalty point of player1's last colomn
				{
					printf("\033[0;33mPENALTY FOR PLAYER 1..\033[m\n");
					player1_y += 2;
				}
				if (player1_y <= 0)		//corner of player1's last colomn
				{
					player1_x -= -player1_y;
					player1_y = 1;
				}
			}

			else if (player1_y == 1)
			{
				player1_x -= player1;

				if (player1_x <= 2)	//Finishing the game if player passes finish point
				{
					keepReading = 1;
					player1_x = 1;
					player1_y = 1;
				}
			}

			//Player 2 *********

			if (player2_x == 3)	//First row of player 2
			{
				player2_y += player2;

				if (player2_y == 10 || player2_y == 18)	//penalty points of player2's first row
				{
					printf("\033[0;36mPENALTY FOR PLAYER 2..\033[m\n");
					player2_y -=2;
				}
				if (player2_y >= 27)	//corner of player2's first row
				{
					player2_x += player2_y - 26;
					if (player2_x == 5)	/*Third penalty point of player 2 is at the beginnig of first colomn*/
						player2_x -=2;	/*Since I increment the palyer2_X here, program can not entered next else if*/
					/*when player 2 encounter pnelty point and it print '2' over penalty point*/
					/*This if fixes that bug*/
					player2_y = 26;
				}
			}

			else if (player2_y == 26)	//First colomn of player 2
			{
				player2_x += player2;

				if (player2_x == 5 || player2_x == 10)	//penalty points of player2's first colomn
				{
					printf("\033[0;36mPENALTY FOR PLAYER 2..\033[m\n");
					player2_x -= 2;
				}
				if (player2_x >= 12)	//corner of player2's first colomn
				{
					player2_y -= player2_x - 11;
					player2_x = 11;
				}
			}

			else if (player2_x == 11)	//Last row of player 2
			{
				player2_y -= player2;

				if (player2_y == 10 || player2_y == 18) //penalty points of player2's last row
				{
					printf("\033[0;36mPENALTY FOR PLAYER 2..\033[m\n");
					player2_y +=2;
				}
				if (player2_y <= 2)		//corner of player2's last row
				{
					player2_x += player2_y - 2;
					player2_y = 3;
				}
			}

			else if (player2_y == 3)	//Last colomn of player 2
			{
				player2_x -= player2;

				if (player2_x <= 4)	//finishing game if player passes finish line
				{
					keepReading = 1;
					player2_x = 3;
					player2_y = 3;
				}
			}
		printf("\n");
		displayMap(gameMap,player1_x,player1_y,player2_x,player2_y);
		}

		else if (firstPlayer == 2)	//İf player two is starting
		{
			//Player 2 *********

			if (player2_x == 3)	//First row of player 2
			{
				player2_y += player2;

				if (player2_y == 10 || player2_y == 18)	//penalty points of player2's first row
				{
					printf("\033[0;36mPENALTY FOR PLAYER 2..\033[m\n");
					player2_y -=2;
				}
				if (player2_y >= 27)	//corner of player2's first row
				{
					player2_x += player2_y - 26;
					player2_y = 26;
				}
			}

			else if (player2_y == 26)	//First colomn of player 2
			{
				player2_x += player2;

				if (player2_x == 5 || player2_x == 10)	//penalty points of player2's first colomn
				{
					printf("\033[0;36mPENALTY FOR PLAYER 2..\033[m\n");
					player2_x -= 2;
				}
				if (player2_x >= 12)	//corner of player2's first colomn
				{
					player2_y -= player2_x - 11;
					player2_x = 11;
				}
			}

			else if (player2_x == 11)	//Last row of player 2
			{
				player2_y -= player2;

				if (player2_y == 10 || player2_y == 18) //penalty points of player2's last row
				{
					printf("\033[0;36mPENALTY FOR PLAYER 2..\033[m\n");
					player2_y +=2;
				}
				if (player2_y <= 2)		//corner of player2's last row
				{
					player2_x -= 3 - player2_y;
					player2_y = 3;
				}
			}

			else if (player2_y == 3)	//Last colomn of player 2
			{
				player2_x -= player2;

				if (player2_x <= 4)	//finishing game if player passes finish line
				{
					keepReading = 1;
					player2_x = 3;
					player2_y = 3;
				}
			}

			// Player 1 *****
			if (player1_x == 1)		//First row of player 1 is changing only
			{
				player1_y += player1;

				if (player1_y == 14)	//penalty point player1's first row
				{
					printf("\033[0;33mPENALTY FOR PLAYER 1..\033[m\n");
					player1_y -= 2;
				}
				if (player1_y >= 29)	//Corner of player1's first row
				{
					player1_x += player1_y - 28;
					player1_y = 28;
				}
			}

			else if (player1_y == 28)	//First colomn of player 1 is changing only
			{
				player1_x += player1;

				if (player1_x == 7)		//penalty point of player1's first colomn
				{
					printf("\033[0;33mPENALTY FOR PLAYER 1..\033[m\n");
					player1_x -= 2;
				}
				if (player1_x >= 14)	//corner of player1's first colomn
				{
					player1_y -= player1_x - 13;
					player1_x = 13;
				}
			}
			
			else if (player1_x == 13)	//Last colomn of player 1 is changing
			{
				player1_y -= player1;

				if (player1_y == 14)	//penalty point of player1's last colomn
				{
					printf("\033[0;33mPENALTY FOR PLAYER 1..\033[m\n");
					player1_y += 2;
				}
				if (player1_y <= 0)		//corner of player1's last colomn
				{
					player1_x -= -player1_y;
					player1_y = 1;
				}
			}

			else if (player1_y == 1)
			{
				player1_x -= player1;

				if (player1_x <= 2)	//Finishing the game if player passes finish point
				{
					keepReading = 1;
					player1_x = 1;
					player1_y = 1;
				}
			}
		printf("\n");
		displayMap(gameMap,player1_x,player1_y,player2_x,player2_y);
		}
	}

	if (player1_x == 1 && player1_y == 1)
		printf("\033[0;33mPLAYER 1 WON THE GAME\033[m");
	else if (player2_x == 3 && player2_y == 3)
		printf("\033[0;36mPLAYER 2 WON THE GAME\033[m");
}

int main()
{
	char gameMap[15][30];
	srand(time(NULL));

	int firstPlayer;  /*Fırst player is decided*/
	firstPlayer = startGame();

	printMap(gameMap);  /*Printing the map*/

	gameFunction(gameMap,firstPlayer);
	return (0);
}