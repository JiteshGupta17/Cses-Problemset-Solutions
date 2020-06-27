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
        int n;
        cin >> n;

        // zero will be equal to no of pairs of 2,5 which will be equal to no. of 5s
        int ans = 0 ;
        int five = 5;
        while (n / five > 0)
        {
            ans += n / five;
            five *= 5;
        }

        cout << ans;
    }


}