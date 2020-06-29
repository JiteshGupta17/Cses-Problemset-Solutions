#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int32_t main()
{
    FASTIO;

    int n; cin >> n;
    int x; cin >> x;

    vector<int> coins(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, -1);
    dp[0] = 0; 

    for (int i = 1; i <= x; i++)
    {
        for (int d : coins)
        {
            if (i - d >= 0 && dp[i - d] != -1) {
                if (dp[i] == -1) dp[i] = 1 + dp[i - d];
                else dp[i] = min(dp[i], 1 + dp[i - d]);
            }
        }
    }

    cout << dp[x];
}