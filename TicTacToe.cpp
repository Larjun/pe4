#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
    private:
        int board[3][3];
        int side;

    public:
        TicTacToe() {
            for(int x = 0; x < 3; x++) {
                for(int y = 0; y < 3; y++) {
                    board[x][y] = -1;
                }
            }

            side = 0;
        }

        void testBoard() {
            board[0][0] = 0;
            board[0][1] = 1;
            board[0][2] = 0;

            board[1][0] = 1;
            board[1][1] = 0;
            board[1][2] = 1;

            board[2][0] = 0;
            board[2][1] = 1;
            board[2][2] = 0;
        }
        
        /*
        void printBoard() {
            for(int x = 0; x < 3; x++) {
                for(int y = 0; y < 3; y++) {
                    switch(board[x][y]) {
                        case 0:
                            cout << "X";
                            break;
                        case 1:
                            cout << "O";
                            break;
                        default:
                            cout << " ";
                            break;
                    }
                    if(y < 2) {cout << " | ";}
                }
                cout << endl;
                if(x < 2) {cout << "--+---+--" << endl;}

            }
        } */

        bool placeMarker(int side, int x, int y) {
            if(board[x][y] != -1) {
                if(board[x][y] == side) {
                    cout << "You already placed the marker there, please enter another coordinates";
                } else {
                    cout << "The enemy already placed the marker there, please enter another coordinates";
                }

                return false;
            } else {
                board[x][y] = side;
                return true;
            }
        } 

        void GetPlayerChoice() {
            bool go = true;
            bool placeable = false;
            string x;
            string y;

            while(!placeable) {
                if(side == 0) {cout << "X's turn";} 
                else {cout << "O's turn";}

                while(go) {
                    x = "";
                    cout << endl << "Enter a row to move to 0-2: ";
                    cin >> x;
                    if (x == "0" || x == "1" || x == "2") {
                        go = false;
                    }
                }
                go = true;
                while(go) {
                    y = "";
                    cout << endl << "Enter a column to move to 0-2: ";
                    cin >> y;
                    if (y == "0" || y == "1" || y == "2") {
                        go = false;
                    }
                }

                placeable = placeMarker(side, stoi(x), stoi(y));
            }


            side = (side+1)%2;
        }

        

        int checkGameEnd() {
            int winner = 0;
            for(int x = 0; x < 3; x++) {
                if(board[x][0] == board[x][1] && board[x][1] == board[x][2]) {
                    winner =  board[x][0] + 1;
                }
            }

            for(int y = 0; y < 3; y++) {
                if(board[0][y] == board[1][y] && board[1][y] == board[2][y]) {
                    winner =  board[0][y] + 1;
                }
            }

            if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                winner = board[1][1] + 1;
            }
            
            if(board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
                winner = board[1][1] + 1;
            }

            return winner;
        }
};      

int main() {
    TicTacToe game = TicTacToe();
    while(!game.checkGameEnd()) {
        game.GetPlayerChoice();
        game.printBoard();
    }

    if(game.checkGameEnd() == 1) {cout << "X wins the game" << endl;}
    else {cout << "O wins the game" << endl;}
}