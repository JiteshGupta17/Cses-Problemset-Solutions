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

    // testcases
    {

        int n; cin >> n;
        int prev;
        cin >> prev;

        int ans = 0 ;
        for (int i = 1; i < n; i++)
        {
            int x ; cin >> x;
            if (x < prev)
            {
                ans += prev - x;
                x = prev;
            }

            prev = x;
        }

        cout << ans;
    }


}