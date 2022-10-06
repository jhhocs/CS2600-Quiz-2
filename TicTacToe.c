//TiC Tac Toe - game between 2 players or player vs computer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
char symbol[2] = {'O', 'X'};

void resetBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void readInput(int *num1, int *num2) {
    while(1) {
        scanf("%d%d", &*num1, &*num2);
        if(*num1 != 1 && *num1 != 2 && *num1 != 3 || *num2 != 1 && *num2 != 2 && *num2 != 3) {
            printf("Please provide a valid input\n");
            fflush(stdin);
            continue;
        }
        break;
    }
}

char checkWin() {
    for(int i = 0; i < 3; i++) {
        if(board[i][i] == ' ') {
            continue;
        }
        if(i == 0) {
            if(board[i][i] == board[i][i + 1] && board[i][i] == board[i][i + 2] || 
            board[i][i] == board[i + 1][i] && board[i][i] == board[i + 2][i]) {
                return board[i][i];
            }
        }
        if(i == 1) {
            if(board[i][i - 1] == board[i][i] && board[i][i] == board[i][i + 1] || 
            board[i - 1][i] == board[i][i] && board[i][i] == board[i + 1][i] ||
            board[i - 1][i - 1] == board[i][i] && board[i][i] == board[i + 1][i + 1]||
            board[i - 1][i + 1] == board[i][i] && board[i][i] == board[i + 1][i - 1]) {
                return board[i][i];
            }
        }
        if(i == 2) {
            if(board[i][i] == board[i][i + 1] && board[i][i] == board[i][i + 2] || 
            board[i][i] == board[i - 1][i] && board[i][i] == board[i - 2][i]) {
                return board[i][i];
            }
        }
    }
    return ' ';
}

void printBoard() {
    for(int i = 0; i < 3; i++) {
        printf("%c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        if(i < 2) {
            printf("---------\n");
        }
    }
}

int pvpGame() {
    time_t t;
    srand((unsigned)time(&t));
    int playerTurn = (rand() % 2) + 1;
    char winner = ' ';
    int numMoves = 0;

    while(winner == ' ' && numMoves != 9) {
        int num1, num2;

        //Print game board
        printf("Current Board:\n");
        printBoard();
        //Print player/cpu turn
        printf("Player %d: make your move\n", playerTurn);
        //Read information from console
        while(1) {
            readInput(&num1, &num2);
            if(board[num1 - 1][num2 - 1] == ' ') {
                board[num1 - 1][num2 - 1] = symbol[playerTurn - 1];
                break;
            }
            printf("Square is already taken!\n");
        }
        //Check for winner
        winner = checkWin();
        numMoves++;
        
        if(playerTurn == 1) {
            playerTurn = 2;
        }
        else {
            playerTurn = 1;
        }
    }//Repeat last four steps until winner is found

    printBoard();
    //Print winner or tie
    if(winner == 'O') {
        printf("Player 1 wins!\n");
    }
    else if(winner == 'X') {
        printf("Player 2 wins!\n");
    }
    else {
        printf("Tie!\n");
    }
    
    return 0;
}

int pvcGame() {
    time_t t;
    srand((unsigned)time(&t));
    int playerTurn = (rand() % 2) + 1;
    char winner = ' ';
    int numMoves = 0;

    while(winner == ' ' && numMoves != 9) {
        //Print game board
        printf("Current Board:\n");
        printBoard();

        if(playerTurn == 1) {
            int num1, num2;

            //Print player/cpu turn
            printf("Make your move\n");
            //Read information from console
            while(1) {
                readInput(&num1, &num2);
                if(board[num1 - 1][num2 - 1] == ' ') {
                    board[num1 - 1][num2 - 1] = symbol[playerTurn - 1];
                    break;
                }
                printf("Square is already taken!\n");
            }
        }
        else {
            printf("Computer move\n");
            int randomSquare = (rand() % (9 - numMoves));
            int counter = 0;

            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(board[i][j] == ' ') {
                        if(randomSquare == counter) {
                            board[i][j] = symbol[playerTurn - 1];
                            i = 3;
                            break;
                        }
                        counter++;
                    }
                }
            }
        }
        
        //Check for winner
        winner = checkWin();
        numMoves++;
        
        if(playerTurn == 1) {
            playerTurn = 2;
        }
        else {
            playerTurn = 1;
        }
    }//Repeat last four steps until winner is found

    printBoard();
    //Print winner or tie
    if(winner == 'O') {
        printf("You Win!\n");
    }
    else if(winner == 'X') {
        printf("You Lose!\n");
    }
    else {
        printf("Tie!\n");
    }
    
    return 0;
}

int main() {
    int playAgain = 1;

    //Prompt user for game they wish to play
    printf("Welcome to Tic Tac Toe!\n\n");
    printf("1 - person vs. person\n");
    printf("2 - person vs. computer\n\n");
    printf("Enter your choice (1 or 2): ");

    //Read information from console
    int gameType;
    while(1) {
        scanf("%d", &gameType);
        if(gameType != 1 && gameType != 2) {
            printf("Please provide a valid input\n");
            fflush(stdin);
            continue;
        }
        break;
    }
    printf("\n\n");

    while(playAgain == 1) {
        //Start game, 2 player or player vs computer
        resetBoard();
        if(gameType == 1) {
            pvpGame();
        }
        else {
            pvcGame();
        }

        //Ask user if they want to play again
        printf("Play again?\n\n");
        printf("1 - Yes\n");
        printf("2 - No\n");
        while(1) {
            scanf("%d", &playAgain);
            if(playAgain != 1 && playAgain != 2) {
                printf("Please provide a valid input\n");
                fflush(stdin);
                continue;
            }
            break;
        }
    }//If yes, restart game, if no terminate program

    return 0;
}