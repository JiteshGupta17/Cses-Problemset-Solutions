#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

// Recursive 2D dp wont pass
// int solve(int idx,int sum,vector<vector<int>>&dp)
// {
//     if(sum==0) return 1;
//     if(idx==n) return 0;

//     int & ans = dp[idx][sum];
//     if(ans != -1) return ans;

//     ans = 0;
//     for(int i = idx;i<n;i++)
//     {
//         if(sum - coins[i]>=0)
//         {
//             ans += solve(i,sum-coins[i],dp);
//             ans %= MOD;
//         }
//     }

//     return ans;
// }

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

    for (int coin : coins)
    {
        for (int amount = 1; amount <= x; amount++)
        {
            if (amount - coin >= 0)
            {
                dp[amount] += dp[amount - coin];
                dp[amount] %= MOD;
            }
        }

        // for(int ele : dp) cout<<ele<<" ";
        // cout<<endl;
    }

    cout << dp[x];


}