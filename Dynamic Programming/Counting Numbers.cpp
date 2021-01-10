#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int dp[20][10][2][2];

int solve(string &str, int idx, int prev, int tight, int start)
{
	if (idx == str.size()) return 1;

	int &ans = dp[idx][prev][tight][start];
	if (ans != -1) return ans;

	ans = 0;
	int end = tight ? str[idx] - '0' : 9;

	for (int i = 0; i <= end; i++)
	{
		if (start)
		{
			if (i != prev) ans += solve(str, idx + 1, i, tight && (i == end), 1);
		}
		else {
			ans += solve(str, idx + 1, i, tight && (i == end), !(i == 0));
		}
	}

	return ans;
}

int32_t main()
{
	FASTIO;

	memset(dp, -1, sizeof dp);

	string a, b;
	cin >> a >> b;

	int ans = 0;
	ans = solve(b, 0, 0, 1, 0);

	memset(dp, -1, sizeof dp);

	int num = stol(a);
	if (num > 0) a = to_string(num - 1);
	else ans += 1;

	ans -= solve(a, 0, 0, 1, 0);

	cout << ans;

}