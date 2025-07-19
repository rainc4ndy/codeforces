#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the pattern
void printPattern(int n) {
    vector<string> pattern;

    // Initial pattern for n = 1
    pattern.push_back("##");
    pattern.push_back("##");

    // Loop to generate the pattern for each level of n
    for (int level = 2; level <= n; level++) {
        int size = pattern.size();
        
        // Adding dots to the right and left of existing lines
        for (int i = 0; i < size; i++) {
            pattern[i] = pattern[i] + "..";
            pattern[i] = ".." + pattern[i];
        }
        
        // Adding new lines at the top and bottom
        for (int i = 0; i < size; i++) {
            pattern.push_back(pattern[i]);
            pattern[i] = ".." + pattern[i].substr(2, pattern[i].length() - 4) + "..";
        }
    }

    // Printing the final pattern
    for (const auto &line : pattern) {
        cout << line << endl;
    }
}

int main() {
    int n;
    cin >> n; // Taking input for n
    printPattern(n); // Printing the pattern for n
    return 0;
}
