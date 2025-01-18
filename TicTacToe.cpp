#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
class TicTacToe {
public:
    char Gmap[21][21] = {
        {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
        {'-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-'},
        {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
        {'-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-'},
        {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '}};
    char zero[3][5] = {
        {' ', '/', '-', 92, ' '},
        {'|', ' ', 'O', ' ', '|'},
        {' ', 92, '-', '/', ' '}};
    char cross[3][5] = {
        {'-', 92, ' ', '/', '-'},
        {' ', ' ', 'X', ' ', ' '},
        {'-', '/', ' ', 92, '-'}};
    char playable[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    void makecross(int a, int b) {
        a -= 1;
        b -= 2;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) { Gmap[i + a][j + b] = cross[i][j]; }
        }
    }
    void makezero(int a, int b) {
        a -= 1;
        b -= 2;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) { Gmap[i + a][j + b] = zero[i][j]; }
        }
    }
    void updater() {
        system("cls");
        Gmap[1][2] = playable[0];
        Gmap[1][8] = playable[1];
        Gmap[1][14] = playable[2];
        Gmap[5][2] = playable[3];
        Gmap[5][8] = playable[4];
        Gmap[5][14] = playable[5];
        Gmap[9][2] = playable[6];
        Gmap[9][8] = playable[7];
        Gmap[9][14] = playable[8];
        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 21; j++) {
                if (Gmap[i][j] == 'X') { makecross(i, j); }
                else if (Gmap[i][j] == 'O') { makezero(i, j); }
            }
        }
        for (int i = 0; i < 18; i++) {
            for (int j = 0; j < 18; j++) { cout << Gmap[i][j]; }
            cout << endl;
        }
    }
    char winner(char player) {
        if ((playable[0] == player && playable[1] == player && playable[2] == player) ||
            (playable[3] == player && playable[4] == player && playable[5] == player) ||
            (playable[6] == player && playable[7] == player && playable[8] == player) ||
            (playable[0] == player && playable[4] == player && playable[8] == player) ||
            (playable[2] == player && playable[4] == player && playable[6] == player))
        { return player; }
        else { return 'D'; }
    }
    void computerplay() {
        int roboval = (rand() % 9);
        int flag = 0;
        while (flag == 0) {
            if (playable[roboval] == 'X' || playable[roboval] == 'O') {
                roboval = (roboval + 1) % 9;
            } else {
                playable[roboval] = 'X';
                flag = 1;
            }
        }
    }
    void playerplay() {
        int flag = 0;
        while (flag == 0) {
            int playerval;
            cin >> playerval;
            playerval = playerval - 1;
            if (playable[playerval] == 'X' || playable[playerval] == 'O' || playerval > 9 || playerval < 0) {
                cout << "you enter wrong value" << endl;
            } else {
                playable[playerval] = 'O';
                flag = 1;
            }
        }
    }
    void runner() {
        char player = 'D';
        int turn = (rand() % 2);
        for (int i = 0; i < 10; i++) {
            updater();
            char win = winner(player);
            if (win == 'O') {
                cout << "You win" << endl;
                break;
            } else if (win == 'X') {
                cout << "computer win" << endl;
                break;
            } else if (i == 9) {
                cout << "Its a draw" << endl;
                break;
            }
            if (turn % 2 == 0) {
                playerplay();
                player = 'O';
            } else {
                computerplay();
                player = 'X';
            }
            turn++;
        }
        return;
    }
    void reset() {
        playable[0] = '1';
        playable[1] = '2';
        playable[2] = '3';
        playable[3] = '4';
        playable[4] = '5';
        playable[5] = '6';
        playable[6] = '7';
        playable[7] = '8';
        playable[8] = '9';
        Gmap[1][2] = playable[0];
        Gmap[1][8] = playable[1];
        Gmap[1][14] = playable[2];
        Gmap[5][2] = playable[3];
        Gmap[5][8] = playable[4];
        Gmap[5][14] = playable[5];
        Gmap[9][2] = playable[6];
        Gmap[9][8] = playable[7];
        Gmap[9][14] = playable[8];
    }
};

int main() {
    srand((unsigned int)time(NULL));
    cout << "press 1 to start and any key to exit" << endl;
    int start;
    cin >> start;
    do {
        TicTacToe Game;
        Game.reset();
        Game.runner();
        cout << "press 1 to restart the game" << endl;
        cin >> start;
    } while (start == 1);
    return 0;
}