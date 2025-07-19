#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;



int main()
{
    int n;
    string s;
    cin >> s;
    cin >> n;
    int m = s.size();
    vector<vector<int>> dp(m+1, vector<int>(n, 0));      //建一个（m+1）*n的二维数组，初始化为0
    dp[0][0] = 1;                                        //初始位为1
    int tmp;
    for (int i = 1; i <= m; i++) {                       
        for (int j = 0; j < n; j++) {                   //余数可以为0到n-1
            if (s[i - 1] == 'X' && i == 1) {            //当前位不确定,且为首位，k不能取0
                for (int k = 1; k <= 9; k++) {
                    tmp = (j * 10 + k) % n;
                    dp[i][tmp] += dp[i - 1][j];
                }
            }
            else if (s[i - 1] == 'X' && i != 1) {       //当前位不确定,且不为首位，k可取0到9
                for (int k = 0; k <= 9; k++) {
                    tmp = (j * 10 + k) % n;
                    dp[i][tmp] += dp[i - 1][j];
                }
            }
            else {                                      //当前位确定
                tmp = (j * 10 + (s[i - 1] - '0')) % n;
                dp[i][tmp] += dp[i - 1][j];
            }
        }
    }
    cout << dp[m][0] << endl;
    return 0;
}
