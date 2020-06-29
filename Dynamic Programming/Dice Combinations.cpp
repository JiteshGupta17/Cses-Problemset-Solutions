#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

// Recursive
int solve(int n)
{
    if (n == 0) return 1;
    int ans = 0;
    for (int d = 1; d <= 6; d++) {
        if (n - d >= 0) ans += solve(n - d);
    }

    return ans;
}

int32_t main()
{
    FASTIO;

    int n; cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int d = 1; d <= 6; d++)
        {
            if (i - d >= 0) {
                dp[i] += dp[i - d];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[n];
}