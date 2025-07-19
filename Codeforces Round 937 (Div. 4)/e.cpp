#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to find all divisors of a given number n
vector<int> findDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}

// Function to count the occurrences of substrings of length 'len' in the string 'str'
int countSubstrs(const string& str, int len) {
    string window = str.substr(0, len);
    int count = 0;
    for (int i = 0; i <= str.size() - len; i += len) {
        if (str.substr(i, len) == window) {
            count++;
        } else {
            // If any substring of length 'len' doesn't match the first one,
            // we can return 0 as it's not a repeating pattern for the whole string
            return 0;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t; // Reading number of test cases
    
    int tmp;
    while (t--) {
        string str;
        cin >> tmp;
        cin >> str; // Reading each string
        
        vector<int> divisors = findDivisors(str.size());
        
        cout << "For string: " << str << endl;
        for (int i : divisors) {
            // Skip the whole string as a substring
            if (i == str.size()) continue;
            
            int count = countSubstrs(str, i);
            if (count > 0) {
                cout << "Substring length: " << i << ", Count: " << count << endl;
            }
        }
    }
    
    return 0;
}
