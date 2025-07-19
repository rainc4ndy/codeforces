#include <bits/stdc++.h> 
  
 #define mod (100001)
 #define ll long long

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n;
    cin >> n;

    int data[mod][3] {};

   	for (int i = 0; i < n; i++) {
   		cin >> data[i][0]
   		>> data[i][1]
   		>> data[i][2];
   	}

   	for (int i = 0; i < n; i++) {
   		if (
   			data[i][0] + data[i][1] == data[i][2] ||
   			data[i][1] + data[i][2] == data[i][0] || 
   			data[i][0] + data[i][2] == data[i][1]
   			) {
   			cout << "YES";
   		} else {
   			cout << "NO";
   		}
   		if (i != n - 1)
   			cout << endl;
   	}

	return 0;
}