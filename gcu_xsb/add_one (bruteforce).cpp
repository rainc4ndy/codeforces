#include <iostream>
#include <string>

const int MOD = 1e9 + 7;

std::string transform(const std::string& num) {
    std::string result;
    for (char c : num) {
        result += std::to_string(c - '0' + 1);
    }
    return result;
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        long long n, m;
        std::cin >> n >> m;

        std::string current = std::to_string(n);

        for (long long i = 0; i < m; ++i) {
            current = transform(current);
        }

        std::cout << current.length() % MOD << std::endl;
    }

    return 0;
}
