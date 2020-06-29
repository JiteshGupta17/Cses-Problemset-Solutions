#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const int N = 1e6 + 10;
int dp[N];

int solve(int n)
{
	if (n == 0) return 0;

	int & ans = dp[n];
	if (ans != -1) return ans;

	ans = 1e9;
	int temp = n;

	while (temp)
	{
		int dig = temp % 10;
		temp /= 10;

		if (dig != 0)
		{
			ans = min(ans, 1 + solve(n - dig));
		}
	}

	return ans;
}

int32_t main()
{
	FASTIO;

	int n; cin >> n;

	memset(dp, -1, sizeof dp);

	cout << solve(n);


}