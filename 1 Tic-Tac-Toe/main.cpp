#include <iostream>
#include <limits>
using namespace std;

char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void displayBoard() {
    cout << "\n";
    cout << "   |   |   \n";
    cout << " " << board[1] << " | " << board[2] << " | " << board[3] << " \n";
    cout << "---+---+---\n";
    cout << " " << board[4] << " | " << board[5] << " | " << board[6] << " \n";
    cout << "---+---+---\n";
    cout << " " << board[7] << " | " << board[8] << " | " << board[9] << " \n";
    cout << "   |   |   \n";
    cout << "\n";
}

bool checkWin(char marker) {
    if (board[1] == marker && board[2] == marker && board[3] == marker) return true;
    if (board[4] == marker && board[5] == marker && board[6] == marker) return true;
    if (board[7] == marker && board[8] == marker && board[9] == marker) return true;
    if (board[1] == marker && board[4] == marker && board[7] == marker) return true;
    if (board[2] == marker && board[5] == marker && board[8] == marker) return true;
    if (board[3] == marker && board[6] == marker && board[9] == marker) return true;
    if (board[1] == marker && board[5] == marker && board[9] == marker) return true;
    if (board[3] == marker && board[5] == marker && board[7] == marker) return true;
    return false;
}

bool checkDraw() {
    for (int i = 1; i <= 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') return false;
    }
    return true;
}

void resetBoard() {
    for (int i = 1; i <= 9; i++) {
        board[i] = '0' + i;
    }
}

bool getMove(int& position) {
    string input;
    cout << "> ";
    cin >> input;

    if (input.length() != 1 || input[0] < '1' || input[0] > '9') {
        cout << "Invalid input! Enter a number 1-9.\n";
        return false;
    }

    position = input[0] - '0';

    if (board[position] == 'X' || board[position] == 'O') {
        cout << "Cell already taken! Choose another.\n";
        return false;
    }

    return true;
}

int main() {
    int position;
    char currentMarker;
    bool gameOver;
    string choice;

    do {
        resetBoard();
        gameOver = false;
        currentMarker = 'X';

        while (!gameOver) {
            clearScreen();
            cout << "=== TIC TAC TOE ===\n";
            cout << "Player X  vs  Player O\n";
            displayBoard();
            cout << "Player " << currentMarker << "'s turn\n";

            while (!getMove(position)) {}

            board[position] = currentMarker;

            if (checkWin(currentMarker)) {
                clearScreen();
                cout << "=== TIC TAC TOE ===\n";
                displayBoard();
                cout << "Player " << currentMarker << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                clearScreen();
                cout << "=== TIC TAC TOE ===\n";
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                currentMarker = (currentMarker == 'X') ? 'O' : 'X';
            }
        }

        cout << "\nPlay again? (y/n): ";
        cin >> choice;
    } while (choice == "y" || choice == "Y" || choice == "yes" || choice == "Yes");

    cout << "Thanks for playing!\n";
    return 0;
}