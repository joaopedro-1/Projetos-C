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

        playerMove();
        winner = checkWinner();
        if(winner != '  ' || checkFreeSpaces() == 0)
        {
            break;
        }
        computerMove();
        winner = checkWinner();
        if(winner != '  ' || checkFreeSpaces() == 0)
        {
            break;
        }
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
    int x;
    int y;

    do
        {
        printf("Entre Row #(1-3): ");
        scanf("%d",&x);
        x--;
        
        printf("Enter column #(1-3): ");
        scanf("%d",&y);
        y--;
        
        if(board[x][y] != ' ')
        {
            printf("Invaid move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
    
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

char checkWinner()
{
    //check rows
    for(int i =0; i < 3;i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] )
        {
            return board[i][0];
        }
    }
    //check columns
    for(int i =0; i < 3;i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] )
        {
            return board[i][0];
        }
    }
    //check diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] )
    {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0] )
    {
        return board[0][2];
    }

    return ' ';
}
