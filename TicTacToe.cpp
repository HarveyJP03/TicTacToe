// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char player1Marker = 'X';
char player2Marker = 'O';
char current_marker;
int current_player;

void drawBoard()
{
    system("CLS");
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "------------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "------------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool isNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

bool placeMarker(int slot)
{

    if (slot < 1 || slot > 9) { return false; }

    int row = slot / 3;
    int col;

    //get row/col from slot number
    if (slot % 3 == 0)
    {
        row = row - 1;
        col = 2;
    }
    else
    col = (slot % 3) - 1;
    
    //put marker into board
    if (board[row][col] != player1Marker && board[row][col] != player2Marker)
    {
        board[row][col] = current_marker;
        return true;
    }
    else
    {
        return false;
    }

}
int checkForWin()
{
    for (int i = 0; i < 3; i++)
    {
        // rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;

        //columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player; 
    }
    //diagonal 1
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
    //diagonal 2
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

    return 0;
    
}

void swapPlayer()
{
    if (current_player == 1)
    {
        current_player = 2;
        current_marker = player2Marker;
    }
    else
    {
        current_player = 1;
        current_marker = player1Marker;
    }
}

void playGame()
{
    drawBoard();
    current_player = 1;
    current_marker = player1Marker;
    int playerInput;
    int slot;
    int winner = 0;

    //game loop
    for (int i = 0; i < 9; i++)
    {
        cout << "Player " << current_player << " please enter the number of the position you want to play (1 - 9): ";   
        cin >> slot;

        //check if the input is an integer
        while (cin.fail()) {
            cout << "Invalid input please try again: " << std::endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> slot;
        }

        if (!placeMarker(slot)) 
        { 
        cout << "You cant go there, try again!" << endl;;
        i--; 
        continue; 
        }

        drawBoard();

        winner = checkForWin();
        if (winner != 0) { cout << "Player" << current_player << " wins the game!"; break; }

        swapPlayer();
    }
    if (winner == 0) { cout << "Game was a draw!"; }
}




int main()
{
    playGame();

}


