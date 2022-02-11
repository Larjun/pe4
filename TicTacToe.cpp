#include <iostream>
#include <vector>

using namespace std;

struct Location {
	int x;
	int y;
};

class TicTacToe {
    private:
        bool playerSq[3][3];
        bool enemySq[3][3];
        int board[3][3];

    public:
        TicTacToe() {
            for(int x = 0; x < 3; x++) {
                for(int y = 0; y < 3; y++) {
                    playerSq[x][y] = false;
                    enemySq[x][y] = false;
                    board[x][y] = 0;
                }
            }
        }

        void testBoard() {
            board[0][0] = 1;
            playerSq[0][0] = true;

            board[0][1] = 2;
            enemySq[0][1] = true;

            board[0][2] = 1;
            playerSq[0][2] = true;

            board[1][0] = 2;
            enemySq[1][0] = true;

            board[1][1] = 1;
            playerSq[1][1] = true;

            board[1][2] = 2;
            enemySq[1][2] = true;

            board[2][0] = 1;
            playerSq[2][0] = true;

            board[2][1] = 2;
            enemySq[2][1] = true;

            board[2][2] = 1;
            playerSq[2][2] = true;
        }
        
        void printBoard() {
            for(int x = 0; x < 3; x++) {
                for(int y = 0; y < 3; y++) {
                    switch(board[x][y]) {
                        case 1:
                            cout << "X";
                            break;
                        case 2:
                            cout << "O";
                            break;
                        default:
                            cout << " ";
                            break;
                    }
                    if(y < 2) {cout << " | ";}
                }
                cout << endl;
                if(x < 2) {cout << "==+===+==" << endl;}
            }
        }

        Location GetPlayerChoice() {
            bool go = true;
            string x;
            string y;
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
            Location loc;
            loc.x = stoi(x);
            loc.y = stoi(y);
            return loc;
        }

        void placeMarker(int side);

        int checkGameEnd();
};

int main() {
    TicTacToe game = TicTacToe();
    game.GetPlayerChoice();
}