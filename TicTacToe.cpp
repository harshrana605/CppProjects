#include <iostream>
#include <string>
using namespace std;

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char playerX = 'X';
    const char playerO = 'O';

    int r = -1;
    int c = -1;
    char currentPlayer = playerX;
    char winner = ' ';



    for (int i = 0; i < 9; i++) {   // maximum moves can be only 9
        // printing the game board
        cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        cout << "Current Player is: " << currentPlayer << endl;
        while (true) {
            cout << "Enter your row and column: ";
            cin >> r >> c;
            if (r < 0 || c < 0 || r > 2 || c > 2) {
                cout << "Invalid Input, please try again: ";
            } else if (board[r][c] != ' ') {
                cout << "Tile is full, you can't overwrite it.";
            } else {
                break;
            }
            r = -1;
            c = -1;
            cin.clear();      // if user enters a character instead of a number 
            cin.ignore(10000, '\n');
        }

        board[r][c] = currentPlayer;

        // checking the winner: row-wise checking
        for (int r = 0; r < 3; r++) {
            if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2]) {
                winner = board[r][0];
                break;
            }
        }

        // column-wise checking
        for (int c = 0; c < 3; c++) {
            if (board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c]) {
                winner = board[0][c];
                break;
            }
        }

        // diagonal check
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = board[0][0];
        } else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            winner = board[0][2];
        }

        if (winner != ' ') {
            cout << "The winner is: " << winner << endl;
            break;  // Exit the loop if there is a winner
        }
        

        // If no winner yet and board is full
        if (i == 8) { 
            cout << "The match is a tie." << endl;
        }

        // Switch player
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
    }

    return 0;
}
