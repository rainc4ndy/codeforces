#include <bits/stdc++.h>
#include <fstream>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define debug(x) cout << #x << ' ' << x << endl;
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5+10;
const ll mod = 998244353;

void RC4(unsigned char* data, long dataLen, unsigned char* key, long keyLen, unsigned char* result) {
    unsigned char T[256];
    unsigned char S[256];
    unsigned char tmp; // to be used in swaping
    int j = 0, t = 0, i = 0;

    // S & K initialization
    for(int i = 0 ; i < 256 ; i++) {
        S[i] = i;
        T[i] = key[i % keyLen];
    }
    // State Permutation
    for(int i = 0 ; i < 256; i++) {
        j = (j + S[i] + T[i]) % 256;

        // Swap S[i] & S[j]
        tmp = S[j];
        S[j] = S[i];
        S[i] = tmp;
    }
    j = 0; // reinitializing j to reuse it
    for(int x = 0 ; x < dataLen ; x++) {
        i = (i + 1) % 256; // using %256 to avoid exceeding the array limit
        j = (j + S[i]) % 256; // using %256 to avoid exceeding the array limit

        // Swap S[i] & S[j]
        tmp = S[j];
        S[j] = S[i];
        S[i] = tmp;

        t = (S[i] + S[j]) % 256;

        result[x] = data[x] ^ S[t]; // XOR generated S[t] with Byte from the plaintext / cipher and append each Encrypted/Decrypted byte to result array
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <input file>" << endl;
        return 1;
    }

    ifstream in(argv[1], ios::binary);
    if (!in.is_open()) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    string key_str = "OZIXJMVGASLLTSSSECXWYXMOWUOJKJDB";

    unsigned char key[key_str.length()];
    memcpy(key, key_str.c_str(), key_str.length());

    // Read the input file into a vector
    vector<unsigned char> data((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close(); // Close the input file after reading

    vector<unsigned char> result(data.size());

    // Encrypt the data using RC4
    RC4(data.data(), data.size(), key, key_str.length(), result.data());

    // Write the result to an output file
    ofstream out("r2.bin", ios::binary);
    if (!out.is_open()) {
        cout << "Failed to open output file." << endl;
        return 1;
    }

    out.write(reinterpret_cast<char*>(result.data()), result.size());
    out.close();

    cout << "Processing complete. Output written to r2.bin." << endl;
    return 0;
}
