#include <bits/stdc++.h> 
#include <cstdlib>
#include <cstring>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
 	char* s = (char*)malloc(sizeof(char) * 11);
 	strcpy(s, "Hello\0World");

 	printf(s);

 	char* p1 = &s[0];
	char* p2 = &s[4];

	ptrdiff_t diff = p2 - p1;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}