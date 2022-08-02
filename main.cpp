#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int board[9];

//============================================================================
// int score(int cell1,int cell2,int cell3)
//   Add and return score for the three given cells
//
// Parameters
//   cell1 - first cell index
//   cell2 - second cell index
//   cell3 - third cell index
//
// Returns
//   board[cell1] + board[cell2] + board[cell3]
//

int score(int cell1,int cell2,int cell3) {

    return board[cell1] + board[cell2] + board[cell3];
}


//============================================================================
// bool playerWins(int playerNum)
//   Determine if the given player has won the game
//
// Parameter
//   playerNum - 1 if player is X, -1 if player is O
//
// Returns
//   true if player has won, false otherwise
//

bool playerWins(int playerNum) {
    
    int winningScore = 3 * playerNum;
    int winCombinations[8][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };
    
    for (int i = 0; i < 8; i++) {
        if (score(winCombinations[i][0], winCombinations[i][1], winCombinations[i][2]) == winningScore) {
            return true;
        }
    }

    return false;

}


//============================================================================
// bool canWin(int playerNum,int &cell)
//   Return true if player can win on this move, and find the winning move
//
// Parameters
//   playerNum - 1 if player is X, -1 if player is O
//   cell      - Reference parameter, filled in with winning move if it exists
//
// Returns
//   true if player can win, false otherwise
//

bool canWin(int playerNum,int &cell) {
    
    return false;
}


//============================================================================
// void printBoard()
//   Display the game board
//

void printBoard() {

    char xoBoard[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    // Create new X and O array given values in board array 
    for (int i = 0; i < 9; i++) {
        if (board[i] == -1) {
            xoBoard[i] = 'X';
        } else if (board[i] == 1) {
            xoBoard[i] = 'O';
        } else {
            xoBoard[i] = ' ';
        }
    }

    // Draw Gameboard
    cout << "\033[2J\033[H";
    cout << endl, 
    cout << xoBoard[0] << " | " << xoBoard[1] << " | " << xoBoard[2] << endl;
    cout << "---------" << endl;
    cout << xoBoard[3] << " | " << xoBoard[4] << " | " << xoBoard[5] << endl;
    cout << "---------" << endl;
    cout << xoBoard[6] << " | " << xoBoard[7] << " | " << xoBoard[8] << endl;
    cout << endl;
 
}


//============================================================================
// int getComputerMove(int computerNum)
//   Generate computer's next move
//
// Parameter
//   computerNum - 1 if computer is X, -1 if computer is O
//
// Returns
//   cell number (0-8) that computer chooses
//

int getComputerMove(int computerNum) {

    int computerMoves[9] = {4, 0, 2, 6, 8, 1, 3, 5, 7}; // Spots 5, 1, 3, 7, 9, 2, 4, 6, 8 (Need to subract 1 since array starts at 0
    int computerMove;

    if (canWin(computerNum, computerMove)) {

    } else {

        for (int i = 0; i < 9; i++) {
            if (board[computerMoves[i]] == 0) {
                computerMove = computerMoves[i]; 
                return computerMove;
            }
        }
    }
    return computerMove;
}


//============================================================================
// int getHumanMove(int humanNum)
//   Generate human's next move
//
// Parameter
//   humanNum - 1 if human is X, -1 if human is O
//
// Returns
//   cell number (0-8) that human chooses
//

int getHumanMove(int humanNum) {
    
    int humanMove; 

    cout << "Select a square on the board (0 to quit): ";
    cin >> humanMove;

    while (humanMove < 0 || humanMove > 9) {
        cout << "Invalid move! Choose a square 1-9: ";
        cin >> humanMove;

    }
    
    // Allow user to quit the game 
    if (humanMove == 0)
        exit(1);

    while (board[humanMove - 1] != 0) {
        cout << "Square on board has already been choosen. Choose another square: ";
        cin >> humanMove;
        if (humanMove == 0)
            exit(1);
    }

    return humanMove;

}


int main() {

    // variables
    int playerNum, human, computer;

    // step 1: determine X and O
    srand(time(nullptr));
    playerNum = (rand() % 2) * 2 - 1;                       // randomize if 'X' or 'O' goes first                      
    human = (rand() % 2) * 2 - 1;                           // randomize if human is 'X' or 'O'
    computer = human * -1;                                  // gives computer a value based of what the human is

    // step 2: loop 9 iterations (or until someone wins)
    for (int i = 0; i < 9; i++) {
        printBoard();

        // step 2.1: if computer move, get computer move and update board
        if (playerNum == computer) {                    
            board[getComputerMove(playerNum)] = computer; 

        // step 2.2 : if human move, display board, get human move and update board
        } else if (playerNum == human) {
            board[getHumanMove(playerNum) - 1] = human; 
        }

        // step 2.3: if not done in the loop check, check for winner, and if true print winner 
        if (playerWins(playerNum) && playerNum == human){
            printBoard();                                   // print board to show final move
            cout << "You win!" << endl;
            return 1;
        } else if (playerWins(playerNum) && playerNum == computer) {
            printBoard();                                   // print board to show final move
            cout << "Computer Wins!" << endl;
            return 1;
        }
        
        // step 2.4: it's the other player's move now
        playerNum *= -1;

    }

    // step 3: determine winner, if any
    printBoard();
    cout << "Game has ended in a draw" << endl;

    return 0;

}
