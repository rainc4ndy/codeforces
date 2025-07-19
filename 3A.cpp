#include <bits/stdc++.h> 
#include <string>
#include <vector>
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

typedef pair<int, int> P;

void solve() {
    char tmp;
    P p1, p2;
    
    // Input the start position
    cin >> tmp >> p1.y;
    p1.x = tmp - 'a' + 1;
    
    // Input the end position
    cin >> tmp >> p2.y;
    p2.x = tmp - 'a' + 1;
    
    vector<string> steps;
    
    // While the king has not reached the target
    while (p1.x != p2.x || p1.y != p2.y) {
        string move = "";
        if (p1.x < p2.x) {
            move += 'R';
            p1.x++;
        } else if (p1.x > p2.x) {
            move += 'L';
            p1.x--;
        }
        
        if (p1.y < p2.y) {
            move += 'U';
            p1.y++;
        } else if (p1.y > p2.y) {
            move += 'D';
            p1.y--;
        }
        
        steps.push_back(move);
    }
    
    // Output the number of steps
    cout << steps.size() << endl;
    
    // Output each step
    for (const string& step : steps) {
        cout << step << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    
    return 0;
}