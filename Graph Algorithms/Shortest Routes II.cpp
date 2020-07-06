#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int32_t main()
{
    // Floyd Warshall
    FASTIO;

    int n, m;
    cin >> n >> m;

    int q;
    cin >> q;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e18));

    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        dp[x][y] = min(dp[x][y], c);
        dp[y][x] = min(dp[y][x], c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;

        int cur = dp[x][y] == 1e18 ? -1 : dp[x][y];
        cout << cur << endl;
    }

}