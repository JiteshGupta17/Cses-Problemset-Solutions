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
		int n;
		cin >> n;

		vector<int> v(n);
		for (int & i : v) cin >> i;

		multiset<int> st;
		st.insert(v[n - 1]);

		for (int i = n - 2; i >= 0; i--)
		{
			auto it = st.lower_bound(v[i]);
			if ((*it >= v[i] && it != st.begin()) || (it == st.end() && !st.empty()))
			{
				it--;
				// cout<<"i "<<i<<" "<<*it<<endl;
				st.erase(it);
				st.insert(v[i]);
			}
			else st.insert(v[i]);
		}

		cout << st.size();

		// Method 2

		// for (int i = 0; i < n; i++) {
		// 	cin >> a[i];
		// }
		// vector<int>v;
		// for (int i = 0; i < n; i++) {
		// 	auto idx = upper_bound(v.begin(), v.end(), a[i]);
		// 	if (idx == v.end()) {
		// 		v.pb(a[i]);
		// 	}
		// 	else {
		// 		*idx = a[i];
		// 	}
		// }
		// cout << v.size() << endl;

	}

}