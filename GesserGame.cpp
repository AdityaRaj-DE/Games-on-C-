#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void mode1() {
    int range = 0;
    while (range < 1) {
        cout << "Pick the range. Range should be greater than one: ";
        cin >> range;
        if (range < 1) { cout << "You enter wrong range" << endl; }
    }
    int number = (rand() % range) + 1;
    int guess = 0, times = 0;
    do {
        cout << "Enter Guess (1-" << range << "): ";
        cin >> guess;
        times++;
        if (guess > number) {
            if (abs(guess - number) < 10) { cout << "You are close "; }
            cout << "Guess lower number!" << endl;
        } else if (guess < number) {
            if (abs(guess - number) < 10) { cout << "You are close "; }
            cout << "Guess higher number!" << endl;
        } else { cout << "You won! in " << times << " moves." << endl; }
    } while (guess != number);
}
void mode2() {
    int range = 0;
    while (range < 1) {
        cout << "Pick the range. Range should be greater than one: ";
        cin >> range;
        if (range < 1) { cout << "You enter wrong range" << endl; }
    }
    cout << "enter the no. of players" << endl;
    int nums;
    cin >> nums;
    vector<int> playersScore(nums, 0);
    int number = (rand() % range) + 1;
    vector<string> playersName(nums);
    for (int i = 0; i < nums; i++) {
        cout << "enter player " << i + 1 << " name: ";
        string naam;
        cin >> naam;
        playersName[i] = naam;
        cout << endl;
    }
    cout << "Now guess the number given by judge and whose number is closer wins the game" << endl;
    for (int i = 0; i < nums; i++) {
        cout << playersName[i] << " guess the number: ";
        int guess;
        cin >> guess;
        playersScore[i] = abs(number - guess);
        cout << endl;
    }
    cout << "the number is: " << number << endl;
    int winner = *min_element(playersScore.begin(), playersScore.end());
    string first;
    for (int i = 0; i < nums; i++) {
        if (winner == playersScore[i]) {
            first = playersName[i];
            cout << "And the winner is: " << first << endl;
        }
    }
}
void mode3() {
    int range = 0;
    while (range < 1) {
        cout << "Pick the range. Range should be greater than one: ";
        cin >> range;
        if (range < 1) { cout << "You enter wrong range" << endl; }
    }
    cout << "Enter the no. of players" << endl;
    int nums;
    cin >> nums;
    vector<int> playersScore(nums, 0);
    int number = (rand() % range) + 1;
    vector<string> playersName(nums);
    for (int i = 0; i < nums; i++) {
        cout << "Enter player " << i + 1 << " name: ";
        string naam;
        cin >> naam;
        playersName[i] = naam;
        cout << endl;
    }
    cout << "Enter the number of rounds: ";
    int round;
    cin >> round;
    cout << "every person have " << round << " turns to guess the number and at last average of rounds is taken for winner" << endl;
    for (int i = 0; i < nums; i++) {
        cout << playersName[i] << " guess the number" << endl;
        for (int j = 0; j < round; j++) {
            cout << "Round " << j + 1 << ": ";
            int guess;
            cin >> guess;
            playersScore[i] += abs(number - guess);
            cout << endl;
        }
    }
    cout << "the number is: " << number << endl;
    int winner = *min_element(playersScore.begin(), playersScore.end());
    string first;
    for (int i = 0; i < nums; i++) {
        if (winner == playersScore[i]) {
            first = playersName[i];
            cout << "And the winner is: " << first << endl;
        }
    }
}
void mode4()
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "You have to guess a five digit number in 5 moves" << endl
         << "You have clue that the digit is in corrct place or in the number" << endl;
    cout << "Rules:" << endl
         << "1.if digit is right place then it is";
    SetConsoleTextAttribute(color, 10);
    cout << " green." << endl;
    SetConsoleTextAttribute(color, 15);
    cout << "2. If digit is in the number then it is ";
    SetConsoleTextAttribute(color, 14);
    cout << "yellow." << endl;
    SetConsoleTextAttribute(color, 15);
    cout << "3. If digit is repeted in number ther it is ";
    SetConsoleTextAttribute(color, 13);
    cout << "purple" << endl;
    SetConsoleTextAttribute(color, 15);
    cout << "Hint: if digit is green then it does't mean it can't be purple" << endl;
    vector<int> number(5);
    for (int i = 0; i < 5; i++) { number[i] = (rand() % 9) + 1; }
    int winner = 0;
    for (int i = 0; i < 5; i++) {
        vector<int> guess(5);
        for (int j = 0; j < 5; j++) {
            cout << "Enter digit number " << j + 1 << ": ";
            int playernum = -1;
            while (playernum > 9 || playernum < 0) {
                cin >> playernum;
                if (playernum > 9 || playernum < 0) { cout << "your number is out of range enter single digit" << endl; }
            }
            guess[j] = playernum;
        }
        cout << endl << "Your number is: ";
        for (int j = 0; j < 5; j++) {
            SetConsoleTextAttribute(color, 15);
            if (guess[j] == number[j]) {
                SetConsoleTextAttribute(color, 10);
                cout << guess[j] << " ";
                winner++;
            } else {
                int flag = 0;
                for (int k = 0; k < 5; k++) {
                    if (guess[j] == number[k]) {
                        flag++;
                    }
                }
                if (flag > 1) {
                    SetConsoleTextAttribute(color, 13);
                    cout << guess[j] << " ";
                } else if (flag == 1) {
                    SetConsoleTextAttribute(color, 14);
                    cout << guess[j] << " ";
                } else {
                    SetConsoleTextAttribute(color, 15);
                    cout << guess[j] << " ";
                }
            }
            SetConsoleTextAttribute(color, 15);
        }
        cout << endl;
        if (winner == 5) {
            cout << "you won" << endl;
            break;
        }
        winner = 0;
    }
    if (winner != 5) {
        cout << "you lose" << endl;
        cout << "the number is: ";
        for (int i = 0; i < 5; i++) { cout << number[i] << " "; }
    }
}
int main() {
    srand((unsigned int)time(NULL));
    int start;
    do {
        int n;
        cout << "1. Single player Classic game" << endl << "2. Multi player " << endl << "3. Rapid fire" << endl
             << "4. number wordly" << endl << "5.Exit" << endl;
        cin >> n;
        switch (n) {
            case 1: mode1(); break;
            case 2: mode2(); break;
            case 3: mode3(); break;
            case 4: mode4(); break;
            default: break;
        }
        cout << "Press 1 to restart the game";
        cin >> start;
    } while (start == 1);
    return 0;
}