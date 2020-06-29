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
    int total = n * (n + 1) / 2;

    // odd , cant be divided into 2 parts
    if (total & 1)
    {
        cout << 0;
        return 0;
    }

    total /= 2;
    vector<int> dp(total + 1, 0);
    dp[0] = 1;

    for (int ele = 1; ele <= n; ele++)
    {
        for (int i = total; i >= 1; i--)
        {
            if (i - ele >= 0 )
            {
                dp[i] += dp[i - ele];
                dp[i] %= MOD;
            }
        }
    }

    // No. of ways to make the divided amount = dp[total]/2
    // dp[total]/2 = (dp[total]*modularInverse(2))%MOD
    cout << (dp[total] * 500000004) % MOD;

}