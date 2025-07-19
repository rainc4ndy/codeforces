#include <bits/stdc++.h>
using namespace std;

struct DSU {
    array<int,26> p;
    DSU() { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    void unite(int a, int b){
        a = find(a); b = find(b);
        if(a!=b) p[b]=a;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        // 1) must have same length to ever match
        if(s1.size() != s2.size()){
            cout << "NO\n";
            continue;
        }
        // 2) if S3 has different length, it will be a different encrypted string
        if(s1.size() != s3.size()){
            cout << "YES\n";
            continue;
        }
        // DSU on the equality constraints from S1 vs S2
        DSU dsu;
        for(int i = 0; i < (int)s1.size(); i++){
            dsu.unite(s1[i]-'a', s2[i]-'a');
        }
        // 3) is there a position i where s1[i] and s3[i] lie in different components?
        bool ok = false;
        for(int i = 0; i < (int)s1.size(); i++){
            if(dsu.find(s1[i]-'a') != dsu.find(s3[i]-'a')){
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
