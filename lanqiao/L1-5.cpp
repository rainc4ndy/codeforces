#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	long long ans = 0;
    stack<P> st;
    int n,h;
    P p;

    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        cin >> h;
        p.x = h;
        p.y = 1; 
 
        while(!st.empty() && st.top().x <= h)
        {
            ans += st.top().y;
            if(h == st.top().x)
                p.y += st.top().y;
            st.pop();
        }
        if(!st.empty())
            ans++;
        st.push(p);   
    }
 
    cout << ans;
	return 0;
}



