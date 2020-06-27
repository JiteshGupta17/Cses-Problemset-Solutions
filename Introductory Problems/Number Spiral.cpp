#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define F first
#define S second
#define ull unsigned long long
#define ld long double
#define mp make_pair
#define endl "\n"


int32_t main()
{
    FASTIO;

    testcases
    {
        int x, y;
        cin >> x >> y;

        int maxi = max(x, y);

        int h = maxi * maxi;
        int l = h - (2 * maxi - 2);

        if (maxi & 1)
        {
            if (x < y)
            {
                cout << h - x + 1;
            }
            else {
                cout << l + y - 1;
            }
        }
        else{
            if (x < y)
            {
                cout << l + x - 1;
            }
            else{
                cout << h - y + 1;
            }
        }

        cout << endl;
    }


}