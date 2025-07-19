#include <algorithm>
#include <bits/stdc++.h> 

#define mod (100001)
#define ll long long
  
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int p[4];
   	int m1, m2;

   	int mx = -1;
   	for (int i = 0; i < 4; i++)  {
   		cin >> p[i];
   		mx = max(p[i], mx);
   	}
   	cin >> m1 >> m2;

   	int b;
   	int e = 0;
   	int g = 0;
   	for (int i = 0; (i < 4) && e < 2; i++) {
   		b = abs(p[i] - mx);
   		if (p[i] < m1 || b > m2) {
   			g = i + 1;
   			e++;
   		} 
   	}

   	if (e != 0 ) {
   		if (e < 2) 	
 	  		printf("Warning: please check #%d!", g);
 	  	else
 	  		printf("Warning: please check all the tires!");
   	}
   	else cout << "Normal";

	return 0;
}