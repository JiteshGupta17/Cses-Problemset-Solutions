#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define F first
#define S second
#define ull unsigned long long
#define ld long double
#define mp make_pair
#define endl "\n"

const int N = 8;
bool vert[N];
bool diag1[2 * N + 1], diag2[2 * N + 1];
char board[N][N];

int dfs(int i, int cnt)
{
	if (cnt == 8)
	{
		return 1;
	}

	int ans = 0;

	for (int j = 0; j < N; j++)
	{
		if (board[i][j] == '.' && !vert[j]  && !diag1[i + j] && !diag2[i - j + 7])
		{
			board[i][j] = 'Q';
			vert[j] = 1;
			diag1[i + j] = 1;
			diag2[i - j + 7] = 1;

			ans += dfs(i + 1, cnt + 1);

			board[i][j] = '.';
			vert[j] = 0;
			diag1[i + j] = 0;
			diag2[i - j + 7] = 0;
		}
	}

	return ans;
}

int32_t main()
{
	FASTIO;

	// testcases
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> board[i][j];
			}
		}
		// i = row, j = col
		// Trying to place a queuen in each row

		int ans = 0;
		int i = 0;
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == '.' && !vert[j]  && !diag1[i + j] && !diag2[i - j + 7])
			{
				board[i][j] = 'Q';
				vert[j] = 1;
				diag1[i + j] = 1;
				diag2[i - j + 7] = 1;

				ans += dfs(i + 1, 1);

				board[i][j] = '.';
				vert[j] = 0;
				diag1[i + j] = 0;
				diag2[i - j + 7] = 0;
			}
		}

		cout << ans;

	}


}