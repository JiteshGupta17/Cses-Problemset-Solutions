#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int n, m;
const int N = 2e5;
vector<int> graph[N];
int ans = 0;
int child[N];
vector<int> depth(N, -1e9);

// Calculate the max_path from cur_node to nth node and stoe its child which will lead that path
int dfs(int cur)
{
	// cout << cur << endl;
	if (cur == n)
	{
		return 1;
	}

	for (int nbr : graph[cur])
	{
		// visited will be better to use
		int nbr_depth = depth[nbr];
		if (nbr_depth == -1e9) dfs(nbr);

		int cur_depth = 1 + depth[nbr];

		// int cur_depth = 1 + dfs(nbr);

		if (cur_depth > depth[cur])
		{
			depth[cur] = cur_depth;
			child[cur] = nbr;
		}
	}


	return depth[cur];

}

int32_t main()
{


	FASTIO;

	cin >> n >> m;
	depth[n] = 1;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		graph[x].push_back(y);
	}

	int ans = dfs(1) ;

	if (ans < 0)
	{
		cout << "IMPOSSIBLE";
	}
	else {
		cout << ans << endl;
		int cur = 1;
		while (cur != n)
		{
			cout << cur << " ";
			cur = child[cur];
		}

		cout << cur;
	}

}
