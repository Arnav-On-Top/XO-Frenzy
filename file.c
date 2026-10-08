#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char board[3][3]={
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};
void printBoard()
{
    printf("\n");
    printf("%c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf("%c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf("%c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkWinner()
{
    if(board[0][0]==board[0][1]&&
    board[0][1]==board[0][2])
    return 1;
    if(board[1][0]==board[1][1]&&
    board[1][1]==board[1][2])
    return 1;
    if(board[2][0]==board[2][1]&&
    board[2][1]==board[2][2])
    return 1;
    if(board[0][0]==board[1][0]&&
    board[1][0]==board[2][0])
    return 1;
    if(board[0][1]==board[1][1]&&
    board[1][1]==board[2][1])
    return 1;
    if(board[0][2]==board[1][2]&&
    board[1][2]==board[2][2])
    return 1;
    if(board[0][0]==board[1][1]&&
    board[1][1]==board[2][2])
    return 1;
    if(board[0][2]==board[1][1]&&
    board[1][1]==board[2][0])
    return 1;
    return 0;
}
int checkDraw()
{
    if(board[0][0]!='1'&&
    board[0][1]!='2'&&
board[0][2]!='3'&&
board[1][0]!='4'&&
board[1][1]!='5'&&
board[1][2]!='6'&&
board[2][0]!='7'&&
board[2][1]!='8'&&
board[2][2]!='9')
{
    return 1;
}
return 0;
}
void resetBoard()
{
    board[0][0]='1';
    board[0][1]='2';
    board[0][2]='3';
    board[1][0]='4';
    board[1][1]='5';
    board[1][2]='6';
    board[2][0]='7';
    board[2][1]='8';
    board[2][2]='9';
}
int main()
{
    int choice;
    int row;
    int col;
    int computerChoice;
    int computerRow;
    int computerCol;
    int playerScore=0;
    int computerScore=0;
    int drawScore=0;
    int gameOver;
    srand(time(NULL));
    printf("===Tic Tac Toe===\n");
    printf("You are X\n");
    printf("Computer is O\n");
    resetBoard();
    while(1)
    {
        gameOver=0;
        printBoard();
        printf("Choice a position (1-9):");
        scanf("%d",&choice);
        if(choice<1 || choice>9)
        {
            printf("Invalid Choice! Choose between 1 and 9. \n");
            continue;
        }
        row=(choice-1)/3;
        col=(choice-1)%3;
        if(board[row][col]=='X' || board[row][col]=='O')
        {
            printf("That position is alrdy taken \n");
            continue;
        }
        board[row][col]='X';
        printBoard();
        if(checkWinner())
        {
            printBoard();
            printf("You Win! \n");
            playerScore++;
            printf("\n Score: \n");
            printf("You: %d\n", playerScore);
            printf("Computer: %d\n", computerScore);
            printf("Draws: %d\n", drawScore);
            gameOver=1;
        }
        if(checkDraw())
        {
            printBoard();
            printf("Draw! \n");
            drawScore++;
            printf("\n Score: \n");
            printf("You: %d\n", playerScore);
            printf("Computer: %d\n", computerScore);
            printf("Draws: %d\n", drawScore);
            break;
        }
        if(gameOver==1)
        {
            break;
        }
        printf("Computer is choosing... \n");
        while (1)
        {
            computerChoice=rand()%9+1;
            computerRow=(computerChoice-1)/3;
            computerCol=(computerChoice-1)%3;
            if(board[computerRow][computerCol]!='X'&&
            board[computerRow][computerCol]!='O')
            {
                break;
            }
        }
        board[computerRow][computerCol]='O';
        printf("Computer chose: %d\n", computerChoice);
        printBoard();
        if(checkWinner())
        {
            printBoard();
            printf("Computer Wins! \n");
            computerScore++;
            printf("\n Score: \n");
            printf("You: %d\n", playerScore);
            printf("Computer: %d\n", computerScore);
            printf("Draws: %d\n", drawScore);
            gameOver=1;
        }
        if(checkDraw())
        {
            printBoard();
            printf("Draw! \n");
            drawScore++;
            printf("\n Score: \n");
            printf("You: %d\n", playerScore);
            printf("Computer: %d\n", computerScore);
            printf("Draws: %d\n", drawScore);
            gameOver=1;
        }
        if(gameOver==1)
        {
            break;
        }
    }
}