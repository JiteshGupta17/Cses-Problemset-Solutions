#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

vector<pair<int, int>> direc = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};

int32_t main()
{
	// Count of Connected Componenets
	FASTIO;

	int n, m;
	cin >> n >> m;

	vector<string> v(n);
	for (string &s : v) cin >> s;

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == '#') continue;

			queue<pair<int, int>> q;
			q.push({i, j});

			v[i][j] = '#';
			cnt++;

			while (!q.empty())
			{
				auto cur = q.front();
				q.pop();

				for (auto d : direc)
				{
					int x = d.first + cur.first;
					int y = d.second + cur.second;

					if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '.')
					{
						q.push({x, y});
						v[x][y] = '#';
					}
				}

			}


		}
	}

	cout << cnt;


}