#include <iostream>

using namespace std;


int board[9];                           // size of game board (3x3 or 9 squares)

int score(int cell1, int cell2, int cell3) {

    return 0;
}

bool playerWins(int playerNum) {        // Check to see if player wins 

    // Check if player has won the game
    // Up/down, Right/Left, or Diagnol
    // Return true/fasle

    return true;
}


bool canWin(int playerNum, int &square) {

    // Check if computer can win
    // Send true/false back to getComputerMove()

    return true;
}

void printBoard(void) {                 // Draw game board at start and after each turn
    
   // Print board as matrix
   // Wait or ask Dr. Bob how to print array as matrix 
    
}


int getComputerMove(int computerNum) {  // Determine computer's next move
    
    // loop through if else staments until true to get computer's move
    // check for canWin() first 

    return 0;
}

int getHumanMove(int humanNum) {        // Get players move 
                                       
    cout << "Choose spot on board: " << endl;
    cin >> humanNum;

    // Possible Do loop here?
    // Keep asking and checking spot on board until user chooses spot that is not taken
    
    
    return 0; 
}

int main() {

    int humanNum;
    int computerNum;
    
    /* While Loop (Until Win) 
     * 1. Get computer num / check computer win 
     * 2. Pring board
     * 3. Get player num  / check player win 
     * 4. If win then display winner
     * 5. End loop  
    */ 


    return 0;
    
}
