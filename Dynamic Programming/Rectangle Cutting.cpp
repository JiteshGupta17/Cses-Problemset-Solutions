#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const int N = 505;
int dp[N][N];

int solve(int l, int b)
{
	// swapping done as ans of l,b is same as b,l , so as to always calculate of small,big
	// Another way can be to store ans for l,b as ans for b,l also
	if (l > b) swap(l, b);

	if (l == b) return 0;

	int & ans = dp[l][b];
	if (ans != -1) return ans;

	ans = 1e9;

	// These calls can be further optimised by going only till l/2
	for (int cut = 1; cut < l; cut ++)
	{
		int cur = 1 + solve(cut, b) + solve(l - cut, b);
		ans = min(ans, cur);
	}

	for (int cut = 1; cut < b; cut++)
	{
		int cur = 1 + solve(l, cut) + solve(l, b - cut);
		ans = min(ans, cur);
	}

	return ans;

}

int32_t main()
{
	FASTIO;

	int l, b;
	cin >> l >> b;

	memset(dp, -1, sizeof dp);

	cout << solve(l, b);

}