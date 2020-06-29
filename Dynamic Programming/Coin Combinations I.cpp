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

    vector<int> dp(x + 1);
    dp[0] = 1;

    for (int amount = 1; amount <= x; amount++)
    {
        for (int coin : coins)
        {
            if (amount - coin >= 0)
            {
                dp[amount] += dp[amount - coin];
                dp[amount] %= MOD;
            }
        }
    }

    cout << dp[x];
}