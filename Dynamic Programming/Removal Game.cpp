#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const int N = 5002;
bool gap;
int dp[N][N];
int v[N];

int solve(int l, int r)
{
    if (l > r) return 0;

    if (dp[l][r] != -1) return dp[l][r];

    // turn of player 1 - tries to maximise his score
    if (((r - l) & 1) != gap)
    {
        return dp[l][r] = max(v[l] + solve( l + 1, r), v[r] + solve( l, r - 1));
    }

    // turn of player 2 - tries to minimise score of player 1
    return dp[l][r] = min(solve(l + 1, r), solve(l, r - 1));
}

int32_t main()
{
    FASTIO;

    int n; cin >> n;
    for (int i  = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (n & 1) gap = true;
    else gap = false;

    memset(dp, -1, sizeof dp);

    cout << solve(0, n - 1);

}