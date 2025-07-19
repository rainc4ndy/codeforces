#include <iostream>
#include <string>
using namespace std;
bool judgeCircle(const string& moves) {
    int x = 0, y = 0;
    for (char move : moves) {
        if (move == 'U') y++;
        else if (move == 'D') y--;
        else if (move == 'L') x--;
        else if (move == 'R') x++;
    }
    return x == 0 && y == 0;
}
int main() {
    string moves;
    cin >> moves;
    if (judgeCircle(moves)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}