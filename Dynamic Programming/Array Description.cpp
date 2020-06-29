#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const int N = 1e5 + 5;
int arr[N];
int n, m;
int dp[N][100];

int solve(int i, int prev)
{
    if (i == n) return 1;

    int &ans = dp[i][prev];
    if (ans != -1) return ans;

    if (arr[i] != 0)
    {
        if (abs(arr[i] - prev) > 1) return 0;
        return ans = solve(i + 1, arr[i]);
    }

    ans = 0;
    for (int add = -1; add <= 1; add++)
    {
        if (prev + add >= 1 && prev + add <= m)
        {
            ans += solve(i + 1, prev + add);
            ans %= MOD;
        }
    }

    return ans;
}

int32_t main()
{
    FASTIO;

    cin >> n >> m;

    for (int i  = 0; i < n; i++) cin >> arr[i];

    memset(dp, -1, sizeof dp);

    int ans = 0;

    if (arr[0] != 0)
    {
        ans = solve(1, arr[0]);
    }
    else {
        for (int i = 1; i <= m; i++)
        {
            ans += solve(1, i);
            ans %= MOD;
        }
    }

    cout << ans;


}