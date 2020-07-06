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

	// testcases
	{
		int n, m;
		cin >> n >> m;

		multiset<int> tickets;
		vector<int> people(m);

		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			tickets.insert(x);
		}

		vector<int> ans(m);

		for (int i = 0; i < m; i++) {
			int x; cin >> x;

			auto it = tickets.lower_bound(x);
			if (*it == x) {
				ans[i] = x;
				tickets.erase(it);
			}
			else if (it != tickets.begin())
			{
				it--;
				ans[i] = *it;
				tickets.erase(it);
			}
			else ans[i] = -1;
		}

		for (int ele : ans) cout << ele << endl;
	}


}