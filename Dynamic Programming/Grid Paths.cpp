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

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    if (grid[n - 1][n - 1] == '*')
    {
        cout << 0;
        return 0;
    }

    vector<int> dp(n + 1, 0);
    dp[n - 1] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (grid[i][j] == '*') dp[j] = 0;
            else dp[j] += dp[j + 1];

            dp[j] %= MOD;
        }
    }

    cout << dp[0];

}