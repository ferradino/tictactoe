#include <iostream>
#include <stdlib.h>

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
    
    int winningScore;

    if (playerNum == 1) {
        winningScore = 3;
    } else {
        winningScore = -3;
    }

    if (score(0, 1, 2) ==  winningScore) {
       return true; 
    } else if (score(3, 4, 5) == winningScore) {
        return true;
    } else if (score(6, 7, 8) == winningScore) {
        return true;
    } else if (score(0, 3, 6) == winningScore) {
        return true;
    } else if (score(1, 4, 7) == winningScore) {
        return true;
    } else if (score(2, 5, 8) == winningScore) {
        return true;
    } else if (score(0, 4, 8) == winningScore) {
        return true; 
    } else if (score(2, 4, 6) == winningScore) {
        return true;
    } else {
        return false;
    }

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
    return true;
}


//============================================================================
// void printBoard()
//   Display the game board
//

void printBoard() {

    char xoBoard[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    for (int i = 0; i < 9; i++) {
        if (board[i] == -1) {
            xoBoard[i] = 'X';
        } else if (board[i] == 1) {
            xoBoard[i] = 'O';
        } else {
            xoBoard[i] = ' ';
        }
    }

    cout << "\033[2J\033[H";
    cout << endl, 
    cout << xoBoard[0] << " | " << xoBoard[1] << " | " << xoBoard[2] << endl;
    cout << "---------" << endl;
    cout << xoBoard[3] << " | " << xoBoard[4] << " | " << xoBoard[5] << endl;
    cout << "---------" << endl;
    cout << xoBoard[6] << " | " << xoBoard[7] << " | " << xoBoard[8] << endl;
    cout << endl;
 
   
           /*  "   |   |\n ";
    // top-left cell
    if (board[0] == 1)
        cout << 'X';
    else if (board[0] == -1)
        cout << 'O';
    else
        cout << '1';
    cout << " | ";
    // top-center
    if (board[1] == 1)
        cout << 'X';
    else if (board[1] == -1)
        cout << 'O';
    else
        cout << '2';
    cout << " | ";
    // top-right
    if (board[2] == 1)
        cout << 'X';
    else if (board[2] == -1)
        cout << 'O';
    else
        cout << '3';
    cout << "\n   |   |\n---+---+---\n   |   |\n ";
    // mid-left cell
    if (board[3] == 1)
        cout << 'X';
    else if (board[3] == -1)
        cout << 'O';
    else
        cout << '4';
    cout << " | ";
    // center
    if (board[4] == 1)
        cout << 'X';
    else if (board[4] == -1)
        cout << 'O';
    else
        cout << '5';
    cout << " | ";
    // mid-right
    if (board[5] == 1)
        cout << 'X';
    else if (board[5] == -1)
        cout << 'O';
    else
        cout << '6';
    cout << "\n   |   |\n---+---+---\n   |   |\n ";
    // bottom-left cell
    if (board[6] == 1)
        cout << 'X';
    else if (board[6] == -1)
        cout << 'O';
    else
        cout << '7';
    cout << " | ";
    // bottom-center
    if (board[7] == 1)
        cout << 'X';
    else if (board[7] == -1)
        cout << 'O';
    else
        cout << '8';
    cout << " | ";
    // bottom-right
    if (board[8] == 1)
        cout << 'X';
    else if (board[8] == -1)
        cout << 'O';
    else
        cout << '9';
    cout << "\n   |   |" << endl;
*/    
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

    for (int i = 0; i < 9; i++) {
        if (board[computerMoves[i]] == 0) {
           computerMove = computerMoves[i]; 
           break;
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
        cout << "Invalid move! Choose square 1-9: ";
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
    int playerNum;

    // step 1: determine X and O
    playerNum = 1;

    // step 2: loop 9 iterations (or until someone wins)
    for (int i = 0; i < 9; i++) {
        // step 2.1: if computer move, get computer move and update board
        if (playerNum == 1) {
            board[getComputerMove(playerNum)] = 1; 
            printBoard();

            // step 2.2 : if human move, display board, get human move and update board
        } else if (playerNum == -1) {
            board[getHumanMove(playerNum) - 1] = -1; 
            printBoard();
        }

        // step 2.3: if not done in the loop check, check for winner and break if necessary
        if (playerWins(playerNum) == true){
            break;
        }
        
        // step 2.4: it's the other player's move now
        playerNum *= -1;

    }

    // step 3: determine winner, if any
    if (playerWins(playerNum) && playerNum == 1) {
        cout << "Computer Wins!" << endl;
    } else if ( playerWins(playerNum) && playerNum == -1) {
        cout << "You Win!" << endl;
    } else {
        cout << "Game has ended in a draw" << endl;
    }

    return 0;

}
