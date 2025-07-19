#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    vector<string> tiangan = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
    vector<string> dizhi = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};

    unordered_map<string, int> ganzhi_to_year;
    int start_year = 1984;

    for (int i = 0; i < 60; ++i) {
        string ganzhi = tiangan[i % 10] + dizhi[i % 12];
        ganzhi_to_year[ganzhi] = start_year + i;
    }

    int T;
    cin >> T;
    while (T--) {
        string ganzhi;
        cin >> ganzhi;
        cout << ganzhi_to_year[ganzhi] << endl;
    }

    return 0;
}
