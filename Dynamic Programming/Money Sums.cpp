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

    int n;
    cin >> n;

    vector<int> coins(n);
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
        total += coins[i];
    }

    // Total is the max_amount that can be made using these coins
    vector<bool> dp(total + 1, 0);

    dp[0] = 1;
    for (int coin : coins)
    {
        for (int amount = total; amount >= 0 ; amount--)
        {
            if (amount - coin >= 0)
            {
                dp[amount] = dp[amount] || dp[amount - coin];
            }
        }
    }

    int ans = 0;
    for (int amount = 1; amount <= total; amount++ )
    {
        ans += dp[amount]; // Will add if true
    }

    cout << ans << endl;
    for (int amount = 1; amount <= total; amount++)
    {
        if (dp[amount]) cout << amount << " ";
    }


}