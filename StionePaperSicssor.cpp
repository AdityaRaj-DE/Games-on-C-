#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void play(int num) {
    if (num == 1) { cout << "ROCK"; }
    else if (num == 2) { cout << "PAPER"; }
    else { cout << "SCISSOR"; }
    return;
}
void game(int num1, int num2) {
    if (num1 == num2) {
        cout << "You play ";
        play(num2);
        cout << " and computer play ";
        play(num1);
        cout << " hence its Draw" << endl;
        return;
    } else if (num1 == 1 && num2 == 2) {
        cout << "You play ";
        play(num2);
        cout << " and computer play ";
        play(num1);
        cout << " hence You won" << endl;
        return;
    } else if (num1 == 1 && num2 == 3) {
        cout << "You play ";
        play(num2);
        cout << " and computer play ";
        play(num1);
        cout << " hence computer wins" << endl;
        return;
    } else if (num1 == 2 && num2 == 1) {
        cout << "You play ";
        play(num2);
        cout << " and computer play ";
        play(num1);
        cout << " hence computer wins" << endl;
        return;
    } else if (num1 == 2 && num2 == 3) {
        cout << "You play ";
        play(num2);
        cout << " and computer play ";
        play(num1);
        cout << " hence You won" << endl;
        return;
    } else if (num1 == 3 && num2 == 1) {
        cout << "You play ";
        play(num2);
        cout << " and computer play ";
        play(num1);
        cout << " hence You won" << endl;
        return;
    } else if (num1 == 3 && num2 == 2) {
        cout << "You play ";
        play(num2);
        cout << " and computer play ";
        play(num1);
        cout << " hence computer wins" << endl;
        return;
    }
}
void level2(int winrate, int num2) {
    if (winrate == 1) {
        int roboval = (rand() % 3) + 1;
        game(roboval, num2);
        return;
    } else {
        if (num2 == 1) { game(2, 1); }
        else if (num2 == 2) { game(3, 2); }
        else { game(1, 3); }
    }
}
void level3(int winrate, int num2) {
    if (winrate == 1) {
        int roboval = (rand() % 3) + 1;
        game(roboval, num2);
        return;
    } else {
        if (num2 == 1) { game(2, 1); }
        else if (num2 == 2) { game(3, 2); }
        else { game(1, 3); }
    }
}
void level4(int winrate, int num2) {
    if (winrate == 1) {
        int roboval = (rand() % 3) + 1;
        game(roboval, num2);
        return;
    } else {
        if (num2 == 1) { game(2, 1); }
        else if (num2 == 2) { game(3, 2); }
        else { game(1, 3); }
    }
}
int main() {
    srand((unsigned int)time(NULL));
    int level;
    do {
        cout << "Pick Diffculty level\n1.Easy\n2.Normal\n3.Hard\n4.Impossible\nAny Other key for Exit" << endl;
        cin >> level;
        cout << "Chosse\n1.For ROCK\n2.For PAPER\n3.For SCISSOR" << endl;
        if (level == 1) {
            int roboval = (rand() % 3) + 1;
            int playerval;
            cin >> playerval;
            game(roboval, playerval);
        } else if (level == 2) {
            int chance = (rand() % 2) + 1;
            int playerval;
            cin >> playerval;
            level2(chance, playerval);
        } else if (level == 3) {
            int chance = (rand() % 4) + 1;
            int playerval;
            cin >> playerval;
            level3(chance, playerval);
        } else if (level == 4) {
            int chance = (rand() % 100) + 1;
            int playerval;
            cin >> playerval;
            level4(chance, playerval);
        }
        cout << "you want to play more\n1.For yes\n2.For no" << endl;
        int flag;
        cin >> flag;
        if (flag == 1) { level = 1; }
        else { level = 5; }
    } while (level < 4 && level > 0);
}