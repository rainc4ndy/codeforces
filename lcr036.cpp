class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        using namespace std;
        stringstream ss;
        bool ok = false;

        for (auto& c: tokens) {
            ok = false;
            if (std::isdigit(c[0]))
                ok = true;
            if (!ok) {
                if (c[0] == '-' && c.size() > 1)
                    ok = true;
            }
            if (ok) {
                ss.clear();
                ss = stringstream(c);
                int num;
                ss >> num;
                stk.push(num);
            }
            else { 
                int y = stk.top();
                stk.pop();
                int x = stk.top();
                stk.pop();
                int z = 0;
                switch (c[0]) {
                    case '+': {
                        z = x+y;
                        break;
                    } 
                    case '-': {
                        z = x-y;
                        break;
                    }
                    case '*': {
                        z = x*y;
                        break;
                    }
                    case '/': {
                        z = x/y;
                        break;
                    }
                }
                stk.push(z);
            }
        }
        return stk.top();
    }
};