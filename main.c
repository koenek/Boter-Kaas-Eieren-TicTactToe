#include <stdio.h>
#include <stdlib.h>

void drawBoard(char board[]);
void markBoard(char input, char board[], int player);
_Bool checkForWin(char boardToCheck[]);
char getInput(char boardToCheck[]);

int main()
{
    _Bool gamePlaying = 1;
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    char playerOneInput = '0';
    char playerTwoInput = '0';

    // start game
    drawBoard(board);

    while (gamePlaying == 1)
    {

        // Player 1 turn
        printf("\nPlayer 1, Enter a number:\n");
        // scanf(" %c", &playerOneInput);
        playerOneInput = getInput(board);

        markBoard(playerOneInput, board, 1);
        drawBoard(board);
        if (checkForWin(board) == 1) {
            printf("\n==>Player 1 wins!\n\n");
            break;
        }

        // Player 2 turn
        printf("\nPlayer 2, Enter a number:\n");
        // scanf(" %c", &playerTwoInput);
        playerTwoInput = getInput(board);

        markBoard(playerTwoInput, board, 2);
        drawBoard(board);
        if (checkForWin(board) == 1) {
            printf("\n==>Player 2 wins!\n\n");
            break;
        }

    }


    return 0;
}

void drawBoard(char boardToDraw[])
{
    system("clear");
    printf("\n\n        Boter, Kaas & Eieren\n\n\n    Speler 1 (X) - Speler 2 (O)\n\n\n");
    printf("___________________\n|     |     |     |\n|");
    for (int i = 0; i < 9; i++)
    {
        if (i == 3 || i == 6)
        {
            printf("\n|_____|_____|_____|\n|     |     |     |\n|");
        }
        printf("  %c  |", boardToDraw[i]);
    }
    printf("\n|_____|_____|_____|\n\n");
}

void markBoard(char input, char board[], int player)
{
    for (int i = 0; i < 9; i++)
    {
        if (input == board[i])
        {
            if (player == 1)
            {
                board[i] = 'X';
            }
            else
            {
                board[i] = 'O';
            }
        }
    }
}

_Bool checkForWin(char boardToCheck[])
{
    // Check for horizontal line on first row || second row || third row
    if ((boardToCheck[0] == boardToCheck[1] && boardToCheck[0] == boardToCheck[2]) || (boardToCheck[3] == boardToCheck[4] && boardToCheck[3] == boardToCheck[5]) || (boardToCheck[6] == boardToCheck[7] && boardToCheck[6] == boardToCheck[8]))
    {
        // printf("\n>>>>>>>>horizontale lijn!<<<<<<<\n");
        return 1;
    }
    // Check for vertical line on first column || second column || third column
    if ((boardToCheck[0] == boardToCheck[3] && boardToCheck[0] == boardToCheck[6]) || (boardToCheck[1] == boardToCheck[4] && boardToCheck[1] == boardToCheck[7]) || (boardToCheck[2] == boardToCheck[5] && boardToCheck[2] == boardToCheck[8]))
    {
        // printf("\n>>>>>>>>verticale lijn!<<<<<<<\n");
        return 1;
    }
    // Check for diagonal line from left to right || or right to left
    if ((boardToCheck[0] == boardToCheck[4] && boardToCheck[0] == boardToCheck[8]) || (boardToCheck[2] == boardToCheck[4] && boardToCheck[2] == boardToCheck[6])) {
        // printf("\n>>>>>>>>diagonale lijn!<<<<<<<\n");
        return 1;
    }
    return 0;
}

char getInput(char boardToCheck[]) {
    _Bool inputValid = 0;
    char playerInput = '0';
    while (inputValid == 0) {
        scanf(" %c", &playerInput);
        for (int i = 0; i < 9; i++) {
            if (playerInput == boardToCheck[i]) {
                inputValid = 1;
                return playerInput;
            }
        }
        printf("\nInvalid input. Please enter another value:\n");
    }
    return playerInput;
}
