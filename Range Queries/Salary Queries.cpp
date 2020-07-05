#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

struct segmentTree {

	vector<int> tree;
	void init(int n)
	{
		tree.resize(4 * n);
	}

	void update(int ts, int te, int i, int index, int val)
	{
		if (i < ts || i > te) return;

		if (ts == te)
		{
			tree[index] += val;
			return;
		}

		int mid = (ts + te) / 2;
		update(ts, mid, i, 2 * index, val);
		update(mid + 1, te, i, 2 * index + 1, val);

		tree[index] = tree[2 * index] + tree[2 * index + 1];
	}

	int query(int ts, int te, int l, int r, int index)
	{
		if (l > te || r < ts) return 0;

		if (l <= ts && r >= te) return tree[index];

		int mid = (ts + te) / 2;
		int left = query(ts, mid, l, r, 2 * index);
		int right = query( mid + 1, te, l, r, 2 * index + 1);

		return left + right;
	}


} mytree;

int32_t main()
{
	FASTIO;

	int n, q;
	cin >> n >> q;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	vector<int> temp = v;

	vector<char> queries(q);
	vector<pair<int, int>> quer(q);

	for (int i = 0; i < q; i++)
	{
		cin >> queries[i];
		if (queries[i] == '!')
		{
			int k, x;
			cin >> k >> x;

			quer[i] = {k - 1, x};
			temp.push_back(x);
		}
		else {
			int a, b;
			cin >> a >> b;

			quer[i] = {a, b};
			temp.push_back(a);
			temp.push_back(b);
		}
	}

	sort(temp.begin(), temp.end());
	temp.resize(unique(temp.begin(), temp.end()) - temp.begin());

	// cout << temp.size() << endl;

	int nn = temp.size();
	mytree.init(nn);

	for (int i = 0; i < n; i++)
	{
		int cur = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
		// cout << v[i] << " " << cur << endl;
		v[i] = cur;
		mytree.update(0, nn - 1 , cur, 1, 1);
	}

	for (int i = 0; i < q; i++)
	{
		if (queries[i] == '!')
		{
			int k = quer[i].first;
			int x = quer[i].second;

			x = lower_bound(temp.begin(), temp.end(), x) - temp.begin();

			mytree.update(0, nn - 1, v[k], 1, -1);
			v[k] = x;

			mytree.update(0, nn - 1, x, 1, 1);

		}
		else {

			int a = quer[i].first;
			a = lower_bound(temp.begin(), temp.end(), a) - temp.begin();

			int b = quer[i].second;
			b = lower_bound(temp.begin(), temp.end(), b) - temp.begin();

			int ans = mytree.query(0, nn - 1, a, b, 1);
			cout << ans << endl;

		}
	}
}