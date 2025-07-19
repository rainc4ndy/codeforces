#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    int data;
    for( int i = 0; i < n; i++ )
    {
        cin >> data;
        a.push_back( data );
    }
    data = a[0];
    sort( a.begin(), a.end() );
    int r = a.end() - upper_bound( a.begin(), a.end(), data );

    //cout << "r is: " << r << endl;

    int l = n - r;
    int cnt = 0;
    if( r == 0 )
    {
        cnt += ( l / 2 );
    }

    while( r > 0 && l > 1 )
    {
        if( r & 1 )
        {
            r++;
            l--;
        }
        cnt++;
        r /= 2;
        l /= 2;
    }
    cout << cnt << endl;
    return 0;
}