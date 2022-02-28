#include <ctime>
#include <iostream>
#include <queue>
#include <unistd.h> // Для Sleep()

using namespace std;

class myGame {
private:
    static const int arrSIZE = 3;
    int _game[arrSIZE]{};

public:
    myGame() = default;

    ~myGame() {};

    void showDrums();

    void initDrums(myGame A);

    void isWin(const myGame &A);
};

void myGame::showDrums() {
    for (int i = 0; i < arrSIZE; ++i) {
        cout << _game[i] << " ";
    }
    cout << " \n";
}

void myGame::initDrums(myGame A) {
    for (int i = 0; i < arrSIZE; ++i) {
        _game[i] = rand() % 10;
        sleep(1);
        cout << "Drum was rotated" << endl;
    }
}

void myGame::isWin(const myGame &A) {
    bool flag = false;
    bool jackpot = false;
    int w = 0;
    int n = 1;

    for (int i = arrSIZE - 1; i >= 0; --i) {
        w += _game[i] * n;
        n *= 10;
    }
    n = _game[0];
    int tmp = n;
    jackpot = true;
    for (int i = 1; i < arrSIZE; ++i) {
        if (n == _game[i] || n - _game[i] == 1 || _game[i] - n == 1)
            flag = true;
        n = _game[i];
        if (n != tmp || n != _game[i])
            jackpot = false;
    }
    if (w == 0)
        w = 1000;
    w = rand() % w;
    if (jackpot && flag) {
        w = w * 1000;
        cout << "***!!!You Win! JACKPOT!!! ***"
             << " " << w << "$ congratulations" << endl;
    } else if (flag) {
        cout << "You Win! "
             << " " << w << "$" << endl;
    } else {
        cout << "You Lose! " << endl;
    }
}

int main() {
    char ch;
    bool x = false;
    while (true) {
        if (!x) {
            cout << "Press \"Enter\" to rotate the drum, or \"q\" to exit!\n";
            x = true;
        }
        ch = cin.get();
        if (ch == '\n') {
            srand(time(nullptr));
            myGame A;
            A.initDrums(A);
            A.showDrums();
            A.isWin(A);
            x = false;
        } else if (ch == 'q')
            return 0;
    }
}
