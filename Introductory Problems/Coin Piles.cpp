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

        int a, b;
        cin >> a >> b;

        bool f1 = (2 * a - b >= 0) && ((2 * a - b) % 3 == 0);
        bool f2 = (2 * b - a >= 0) && ((2 * b - a) % 3 == 0);

        if (f1 && f2)
        {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }


}