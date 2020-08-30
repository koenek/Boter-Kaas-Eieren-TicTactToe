#include <stdio.h>
#include <stdlib.h>

void drawBoard(char board[]);
void markBoard(char input, char board[], int player);
_Bool checkForWin();

int main()
{
    _Bool gamePlaying = 1;
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    char playerOneInput = '0';
    char playerTwoInput = '0';
    int activePlayer = 1;

    // start game
    printf("\n\n        Boter, Kaas & Eieren\n\n\n    Speler 1 (X) - Speler 2 (O)\n\n\n");
    drawBoard(board);

    while (gamePlaying == 1)
    {

        if (activePlayer == 1)
        {
            // Player 1 turn
            printf("\nPlayer 1, Enter a number:\n");
            scanf("%c", &playerOneInput);

            markBoard(playerOneInput, board, 1);
            drawBoard(board);
            activePlayer = 2;
        }
        else
        {
            // Player 2 turn
            printf("\nPlayer 2, Enter a number:\n");
            scanf("%c", &playerTwoInput);

            markBoard(playerTwoInput, board, 2);
            drawBoard(board);
            activePlayer = 1;
        }




    }


    return 0;
}

void drawBoard(char boardToDraw[])
{
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
