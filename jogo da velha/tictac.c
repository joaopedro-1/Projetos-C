#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBorad();
void printBorad();
void playerMove();
void computerMove();
void printWinner(char winner);

int checkFreeSpaces();
char checkWinner();

int main()
{
    char winner = ' ';

    resetBorad();
    printBorad();
    while(winner == ' ' && checkFreeSpaces() !=0)
    {
        printBorad();
    }
    
    return 0;
}

void resetBorad()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }    
    }

}
void printBorad()
{
    printf(" %c | %c | %c ", board[0][0],board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0],board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0],board[2][1], board[2][2]);
    printf("\n");
}
void playerMove()
{

}
void computerMove()
{

}
void printWinner(char winner)
{

}

int checkFreeSpaces()
{
    int freeSpaces = 9;

    for(int i = 0; i <3; i++)
    {
        for(int j = 0; j < 3; i++)
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}