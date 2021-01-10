#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const int N = 1e6 + 10;
int n;
int dp[N][2];

// dp[i] = to fill from i till n
// dp[i][0] = i-1 had 2 tiles each of width 1
// dp[1][1] = i-1 has 1 tile of width 2

int solve(int i, int prev)
{
	if (i == n) {
		return 1;
	}

	int & ans = dp[i][prev];
	if (ans != -1) return ans;

	ans = 0;
	if (prev == 1)
	{
		// extend the prev tile of width two
		// ans = (ans + solve(i + 1, 1)) % MOD;

		// place a new tile of width two
		// ans = (ans + solve(i + 1, 1)) % MOD;

		// place two separate tiles
		// ans = (ans + solve(i + 1, 0)) % MOD;

		ans = (2ll * solve(i + 1, 1)) % MOD;
		ans = (ans + solve(i + 1, 0)) % MOD;
	}
	else {

		// dont extend either - 1) start with a new one of width 2 or 2) start with 2 new ones
		// ans = (ans + solve(i + 1, 1)) % MOD;
		// ans = (ans + solve(i + 1, 0)) % MOD;


		// extend both or extend one or extend the other
		// ans = (ans + solve(i + 1, 0)) % MOD;
		// ans = (ans + solve(i + 1, 0)) % MOD;
		// ans = (ans + solve(i + 1, 0)) % MOD;

		ans = solve(i + 1, 1);
		ans = (ans + (4ll * solve(i + 1, 0)) % MOD) % MOD;

	}

	return ans;
}

int32_t main()
{

	FASTIO;

	testcases
	{
		cin >> n;

		for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = -1;

		// Top down - MOre intuitive
		// cout << (solve(1, 0) + solve(1, 1)) % MOD << endl;

		// Bottom up
		dp[n][0] = dp[n][1] = 1;

		for (int i = n - 1; i >= 1; i--)
		{
			dp[i][1] = (2ll * dp[i + 1][1]) % MOD;
			dp[i][1] = (dp[i][1] + dp[i + 1][0]) % MOD;

			dp[i][0] = dp[i + 1][1];
			dp[i][0] = (dp[i][0] + (4ll * dp[i + 1][0])) % MOD;
		}

		cout << (dp[1][0] + dp[1][1]) % MOD << endl;;
	}


}