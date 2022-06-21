#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int choice(char *str, int *x, int *y, char *word)
{
   const char s[2] = " ";
   char *token;
   char a[3][30];
   char b[3]=":q";  //Exit command
   

   token = strtok(str, s);  


   int i=0;
   while( token != NULL ) 
   {
      //printf( " %s\n", token );
     strcpy(a[i],token) ;
     i++;
    
      token = strtok(NULL, s);  // strtok know where it left from last execution in a static pointer. If we pass NULL as first parameter, it meanas we are going to search in previous string 
   }

   if(strcmp(a[0],b)==0)    // If fırst element is :q, return exit code (1)
    return (1);
   else{
       if (strlen(a[0]) != 1)
            *x = 10*(a[0][0] - 48) + (a[0][1] - 48);
        
        else if (strlen(a[0]) == 1)
            *x = (a[0][0] -48);

        if (strlen(a[1]) != 1)
            *y = 10*(a[1][0] - 48) + (a[1][1] - 48);
        else if (strlen(a[1]) == 1)
        {
            *y = a[1][0] - 48;
        }

        i = 0;
        while (a[2][i] != '\0')
        {
            word[i] = a[2][i];
            i++;
        }
        word[i] = '\0';
    }
   return(0);
}

int Size(char array[])
{
    int i =0;
    while (array[i] != '\0')
        i++;
    return (i);
}

int randomNumber(int mod)
{
    return (rand()%mod + 1);
}

void getWords(char tempArray[][15])
{
    srand(time(NULL));
    FILE *ptr = fopen("wordlist.txt","r+");

    char buffer[15];
    int lineNumbers[7];

    int i,j,temp,flag;
    for(i = 0; i < 7; i++)// I am trying to find if there are same number. If so, ı will change it
    {
        temp = randomNumber(50);
        for (j = 0; j < 7; j++) 
        {
            if (temp == lineNumbers[j]) // If temp ıs equal to any number of array
            {                           //change temp until it's different
                temp = randomNumber(50);
                j = 0;  //Check from beginning again because new value may be equal again.
            }
        }
        lineNumbers[i] = temp;
    }
    
    i = 0;  
    while(i < 7)  //sort the line numbers of array, so that ı can get words from meal to hall by checking 1by1 
    {  
        if (lineNumbers[i] > lineNumbers[i+1])  //If next  number is greater than current, swap and start from 0
            {
                temp = lineNumbers[i+1];
                lineNumbers[i+1] = lineNumbers[i];
                lineNumbers[i] = temp;
                i = 0;
            }
        else
            i++;
    }

    int k = 0;
    j = 0;
    i = 0;
    while(j < 7)    //Get random words into temp array as ordered by their line number
    {
        fgets(buffer,15,ptr);
        if (i == lineNumbers[j])
        {
            for (k = 0; buffer[k] != '\0'; k++)
            {
                if (buffer[k] != '\n')  // The \n characters are killing my puzzle .This little mistake cost me 1 night , ı am so angry with myself :(
                tempArray[j][k] = buffer[k];
                else
                tempArray[j][k] = '\0';
            }
            j++;
        }
        i++;
    }
    fclose(ptr);
}

void setBoard(char words[][15], char board[][15], int coordinates[][3])
{
    int x,y,lenght,j,i,k; // x and y are coordinates
    int directions[8];    //if a direction is possible, make that index value 1. for example north is index 0, north east is index 1

    int keepReading = 1;

    for (j = 0; j < 7; j++)
    {
            int y,x;
            y = randomNumber(14);
            x = randomNumber(14);
            lenght = Size(words[j]);

            //temp will store x and y. I created them because I must also have first values of x and y 
            int temp_x;
            int temp_y;

            for (int i = 0; i < 8; i++) // Every new run needs a fres directions array.
                directions[i] = 0;


            if (y - lenght >= 0)           // First direction : north
            {
                temp_x = x;
                temp_y = y;
                for (i = 0; i < lenght; i++)
                {
                    if (board[temp_y][temp_x] != '-')
                        i = 256;    //If there is a word in this direction, I am not gonna let this direction to be considered
                    temp_y--;
                }
                if (i != 257)    //if i = 257, direnction[0] will be 0. it is not 256 because for loop increment i and than check the value of i so that it will be 256+1 = 257
                    directions[0] = 1;
            }

            if (y - lenght >= 0 && x + lenght <= 14)    //Second direction :  north east
            {
                temp_x = x;
                temp_y = y;
                for (i = 0; i < lenght; i++ )
                {
                    if (board[temp_y][temp_x] != '-')
                        i = 256;
                    temp_x++;
                    temp_y--;
                }
                if (i != 257)
                    directions[1] = 1;
            }

            if (x + lenght <= 14)    //THird direction :  east
            {
                temp_x = x;
                temp_y = y;
                for (i = 0; i < lenght; i++ )
                {
                    if (board[temp_y][temp_x] != '-')
                        i = 256;
                    temp_x++;
                }
                if (i != 257)
                    directions[2] = 1;
            }

            if (y + lenght <= 14 && x + lenght <= 14)    //Fourth direction :  south east
            {
                temp_x = x;
                temp_y = y;
                for (i = 0; i < lenght; i++ )
                {
                    if (board[temp_y][temp_x] != '-')
                        i = 256;
                    temp_x++;
                    temp_y++;
                }
                if (i != 257)
                    directions[3] = 1;
            }

            if (y + lenght <= 14)    //Fifth direction :  south
            {
                temp_x = x;
                temp_y = y;
                for (i = 0; i < lenght; i++ )
                {
                    if (board[temp_y][temp_x] != '-')
                        i = 256;
                    temp_y++;
                }
                if (i != 257)
                    directions[4] = 1;
            }

            if (y + lenght <= 14 && x - lenght >= 0)    //Sixth direction :  south west
            {
                temp_x = x;
                temp_y = y;
                for (i = 0; i < lenght; i++ )
                {
                    if (board[temp_y][temp_x] != '-')
                        i = 256;
                    temp_x--;
                    temp_y++;
                }
                if (i != 257)
                    directions[5] = 1;
            }

            if (x - lenght >= 0)    //Seventh direction : west
            {
                temp_x = x;
                temp_y = y;
                for (i = 0; i < lenght; i++ )
                {
                    if (board[temp_y][temp_x] != '-')
                        i = 256;
                    temp_x--;
                }
                if (i != 257)
                    directions[6] = 1;
            }

            if (y - lenght >= 0 && x - lenght >= 0)    //Eight direction :  north west
            {
                temp_x = x;
                temp_y = y;
                for (i = 0; i < lenght; i++ )
                {
                    if (board[temp_y][temp_x] != '-')
                        i = 256;
                    temp_x--;
                    temp_y--;
                }
                if (i != 257)
                    directions[7] = 1;
            }

        int dir;

        int keepReading = 1;    //I don't like using break
        while (keepReading) //Decide direction randomly
        {
            dir = randomNumber(8)-1;  // dir value is selected ranadomly
            if (directions[dir] == 1)
                keepReading = 0;
        }
        coordinates[j][0] = x;  //I am passing the coordinates of words to an array
        coordinates[j][1] = y;
        coordinates[j][2] = dir;

        i = 0;
        //Word will be written to the expressed direction
        if (dir == 0)
        {
           while(words[j][i] != '\0')
            {
                board[y][x] = words[j][i];
                y--;
                i++;
            }
        }

        else if (dir == 1)
        {
           while(words[j][i] != '\0')
            {
                board[y][x] = words[j][i];
                y--;
                x++;
                i++;
            }
        }

        else if (dir == 2)
        {
          while(words[j][i] != '\0')
            {
                board[y][x] = words[j][i];
                x++;
                i++;
            }
        }

        else if (dir == 3)
        {
           while(words[j][i] != '\0')
            {
                board[y][x] = words[j][i];
                y++;
                x++;
                i++;
            }
        }

        else if (dir == 4)
        {
           while(words[j][i] != '\0')
            {
                board[y][x] = words[j][i];
                y++;
                i++;
            }
        }

        else if (dir == 5)
        {
           while(words[j][i] != '\0')
            {
                board[y][x] = words[j][i];
                y++;
                x--;
                i++;
            }
        }

        else if (dir == 6)
        {
           while(words[j][i] != '\0')
            {
                board[y][x] = words[j][i];
                x--;
                i++;
            }
        }

        else if (dir == 7)
        {
           while(words[j][i] != '\0')
            {
                board[y][x] = words[j][i];
                y--;
                x--;
                i++;
            }
        }
    }
}

int findWord(int x, int y, int coordinates[][3], char words[][15], char userAnswer[], int *dir)
{
    int i;
    for (i = 0; i < 7; i++)
    {
        if (coordinates[i][0] == x && coordinates[i][1] == y)
        {
            if (strcmp(words[i],userAnswer) == 0)
            {
                *dir = coordinates[i][2];
                return 1;
            }
        }
    }
    return (0);
}

void coverWord(int x, int y, int size, int direction, char board[][15])
{
    int i = 0;
    if (direction == 0)
        {
           while(i < size)
            {
                board[y][x] = 'X';
                y--;
                i++;
            }
        }

        else if (direction == 1)
        {
           while(i < size)
            {
                board[y][x] = 'X';
                y--;
                x++;
                i++;
            }
        }

        else if (direction == 2)
        {
          while(i < size)
            {
                board[y][x] = 'X';
                x++;
                i++;
            }
        }

        else if (direction == 3)
        {
           while(i < size)
            {
                board[y][x] = 'X';
                y++;
                x++;
                i++;
            }
        }

        else if (direction == 4)
        {
           while(i < size)
            {
                board[y][x] = 'X';
                y++;
                i++;
            }
        }

        else if (direction == 5)
        {
           while(i < size)
            {
                board[y][x] = 'X';
                y++;
                x--;
                i++;
            }
        }

        else if (direction == 6)
        {
           while(i < size)
            {
                board[y][x] = 'X';
                x--;
                i++;
            }
        }

        else if (direction == 7)
        {
           while(i < size)
            {
                board[y][x] = 'X';
                y--;
                x--;
                i++;
            }
        }
}

int main()
{
    srand(time(NULL));
    char wordArray[7][15];    //Hold 7 word from file
    getWords(wordArray);

    char boardArray[15][15];    // Fill the table with '-' sign
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
            boardArray[i][j] = '-';
    }

    int coordinates[7][3];  // Second dimention's first two elements are for coordinates, third for direction. 
    setBoard(wordArray,boardArray,coordinates); //Create the board

    int temp;
    printf("\n");
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (boardArray[i][j] == '-')
            {
                temp = rand()%26;
                boardArray[i][j] = 'A' + temp;
            }
        }
    }


    int keepReading = 1;
    int sumPoint = 0;       //player's point
    int wrongChoice = 3;    
    char buffer[15];       //User text
    int x,y;
    char userEnteredWord[7];
    int size;   //used as Word lenght at 451
    int dir;
    
    while (keepReading)
    {
        for (int i = 0; i < 15 ; i++)
        {
                for (int j = 0; j < 15 ; j++)
                printf("%c ",boardArray[i][j]);
            printf("\n");
        }

        printf("Enter coordinates (X AND Y) and word \n");
        gets(buffer);
        if (choice(buffer,&x,&y,userEnteredWord) == 1)
        {
            printf("YOUR TOTAL SCORE IS : %d\nExiting the game.",sumPoint);
            keepReading = 0;
        }
        
        else
        {
            size = strlen(userEnteredWord);
            if (findWord(x,y,coordinates,wordArray,userEnteredWord,&dir) == 0)    //If answer ıs wrong
            {
                wrongChoice--;
                if (wrongChoice == 0)   //Lost the game
                {
                    printf("You lost the game, :( YOUR SCORE IS : %d",sumPoint);
                    keepReading = 0;
                }
                else    // Still have chance
                printf("Your answer is wrong, you have %d chances.\n",wrongChoice);
            }
            else if (findWord(x,y,coordinates,wordArray,userEnteredWord,&dir) == 1)   //If answer ıs true
            {
                sumPoint += 2;
                printf("Founded! You got 2 points. Your total point is: %d\n",sumPoint);
                coverWord(x, y, size,dir,boardArray);
                if (sumPoint == 14)
                {
                    printf("YOU WON THE GAME :)....CONGRATULATIONS.");
                    keepReading = 0;
                }
            }
        }
    }

    return (0);
}