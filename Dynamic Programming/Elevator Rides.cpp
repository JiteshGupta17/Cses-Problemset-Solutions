#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const int N = (1 << 20) + 10;
int dp_rides[N];
int dp_last[N];

// dp_rides[i] = minimum rides to send people with set bit in i
// dp_last[i] = wt of people sent in last ride with set bit in i

int n, x;
vector<int> wts;

void solve(int mask)
{
	// cout << mask << endl;
	if (!mask) {

		dp_rides[mask] = 1;
		dp_last[mask] = 0;
		return;
	}

	if (dp_rides[mask] != -1) return ;

	int ans_rides = n + 1;
	int ans_last;

	for (int i = 0; i < n; i++)
	{
		if ((mask >> i) & 1)
		{
			// iske bina

			int temp = ~(1 << i);
			solve(mask & temp);

			int rides = dp_rides[temp & mask];
			int last = dp_last[temp & mask];

			// can be accomadated with last ride or to be send separately as new
			if (last + wts[i] <= x)
			{
				last += wts[i];
			}
			else {
				last = wts[i];
				rides += 1;
			}

			if (ans_rides >= rides)
			{
				if (ans_rides == rides)
				{
					ans_last = min(last, ans_last);
				}
				else ans_last = last;

				ans_rides = rides;
			}
		}
	}

	dp_rides[mask] = ans_rides;
	dp_last[mask] = ans_last;

}

int32_t main()
{

	FASTIO;

	cin >> n >> x;

	wts.assign(n, -1);
	for (int i = 0; i < n; i++) cin >> wts[i];

	memset(dp_rides, -1, sizeof dp_rides);

	solve((1 << n) - 1);
	cout << dp_rides[(1 << n) - 1];

}