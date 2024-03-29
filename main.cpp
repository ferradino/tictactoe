#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int board[9];
const int winCombinations[8][3] = {
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,4,8},
    {2,4,6}
};


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
    
    int canWinScore = 2 * playerNum;
    
    for (int i = 0; i < 8; i++) {
        if (score(winCombinations[i][0], winCombinations[i][1], winCombinations[i][2]) == canWinScore) {
            for (int j = 0; j < 3; j++) {
                if (board[winCombinations[i][j]] == 0) {
                    cell = winCombinations[i][j];
                    return true; 
                }
            }
        }
    }

    return false;
    
}

//============================================================================
// void printStartingScreen()
//   Displays Welcome Message and Rules
//   Player must press enter to begin

void printStartingScreen() {

    cout << "\033[2J\033[H";
    cout << "Welcome to Tic-Tac-Toe!" << endl; 
    cout << "-----------------------" << endl << endl;
    cout << "Rules:" << endl;
    cout << "1) The game will randomly choose which player moves first, and alternate after each move." << endl;
    cout << "2) Each spot on the board corresponds to a number. To make a move, choose the number for that spot:" << endl; 
    cout << "\t 1 | 2 | 3 \n\t --------- \n\t 4 | 5 | 6 \n\t --------- \n\t 7 | 8 | 9" << endl;
    cout << "3) First player to get 3 in a row wins. If all spots are filled before someone wins, the game ends in a draw." << endl << endl;
    cout << "Press ENTER to begin: ";
    cin.get();

}


//============================================================================
// void printBoard()
//   Display the game board
//

void printBoard() {

    char xoBoard[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    // Create new X and O array given values in board array 
    for (int i = 0; i < 9; i++) {
        if (board[i] == 1) {
            xoBoard[i] = 'X';
        } else if (board[i] == -1) {
            xoBoard[i] = 'O';
        } else {
            xoBoard[i] = ' ';
        }
    }

    // Draw Gameboard
    cout << "\033[2J\033[H";
    cout << endl, 
    cout << ' ' << xoBoard[0] << " | " << xoBoard[1] << " | " << xoBoard[2] << endl;
    cout << "-----------" << endl;
    cout << ' ' << xoBoard[3] << " | " << xoBoard[4] << " | " << xoBoard[5] << endl;
    cout << "-----------" << endl;
    cout << ' ' << xoBoard[6] << " | " << xoBoard[7] << " | " << xoBoard[8] << endl;
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

    int computerMoves[9] = {4, 0, 2, 6, 8, 1, 3, 5, 7}; // Spots 5, 1, 3, 7, 9, 2, 4, 6, 8 (Need to subract 1 since array starts at 0)
    int computerMove;

    // if computer can win, have computer chose winning move 
    if (canWin(computerNum, computerMove)) {
        return computerMove;
    // if player can win, have computer block the player's winning move    
    } else if (canWin(-computerNum, computerMove)) {
        return computerMove;
    // if both conditions are false, have computer move through list of moves and select appropiate move    
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
    bool validMove = false; 

    cout << "Select a spot on the board (0 to quit): ";
    cin >> humanMove;

    while (!validMove) {
        // Validate if user's move is in range of table
        if (humanMove < 0 || humanMove > 9) {
            printBoard();
            cout << "Invalid move! Choose a spot 1-9 (0 to quit): ";
            cin >> humanMove;
        // Validate if user's move is not already taken
        } else if (board[humanMove - 1] != 0) {
            printBoard();
            cout << "Spot has already been chosen! Choose another spot 1-9 (0 to quit): ";
            cin >> humanMove;
        // Returns true if conditition are met    
        } else {
            validMove = true;
        }

    }
     
    // Allow user to quit the game 
    if (humanMove == 0)
        exit(1);

    humanMove -= 1;                                         // adjust humanMove to match spots on board in board array 

    return humanMove;

}


int main() {

    // variables
    int playerNum, human, computer;

    // step 1: determine X and O
    srand(time(nullptr));
    human = (rand() % 2) * 2 - 1;                           // randomize if human is 'X' or 'O'
    computer = human * -1;                                  // gives computer a value based of what the human is

    playerNum = 1;                                          // Default value is 1 to make 'X' go first everytime 

    // Display welcome message and provide rules to the game
    printStartingScreen();

    // Prints board if player is first to make move
    if (human == playerNum)
        printBoard();                                           

    // step 2: loop 9 iterations (or until someone wins)
    for (int i = 0; i < 9; i++) {

        // step 2.1: if computer move, get computer move and update board
        if (playerNum == computer) {                    
            board[getComputerMove(playerNum)] = computer; 
            printBoard();

        // step 2.2 : if human move, display board, get human move and update board
        } else if (playerNum == human) {
            board[getHumanMove(playerNum)] = human; 
            printBoard();
        }

        // step 2.3: if not done in the loop check, check for winner, and if true print winner 
        if (playerWins(playerNum) && playerNum == human){
            cout << "You win!" << endl;
            return 1;
        } else if (playerWins(playerNum) && playerNum == computer) {
            cout << "Computer Wins!" << endl;
            return 1;
        }
        
        // step 2.4: it's the other player's move now
        playerNum *= -1;

    }

    // step 3: determine winner, if any
    cout << "Game has ended in a draw!" << endl;

    return 0;

}
