#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

vector<pair<int, int>> direc = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
string dd = "RDLU";

int32_t main()
{

    FASTIO;

    int n, m;
    cin >> n >> m;

    pair<int, int> start;
    pair<int, int> end;

    char board[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'A')
            {
                start.first = i;
                start.second = j;
            }

            if (board[i][j] == 'B')
            {
                end.first = i;
                end.second = j;
            }
        }
    }

    vector<vector<int>> visited(n + 1, vector<int>(m + 1, -1));
    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty())
    {
        auto cur = q.front();
        if (cur == end)
        {
            break;
        }

        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int x = direc[d].first + cur.first;
            int y = direc[d].second + cur.second;

            if (x >= 0 && x < n && y >= 0 && y < m && (board[x][y] == '.' || board[x][y] == 'B'))
            {
                board[x][y] = '#';
                visited[x][y] = d;
                q.push({x, y});
            }
        }
    }

    if (visited[end.first][end.second] == -1)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    pair<int, int> cur = end;
    // cout << visited[cur.first][cur.second];
    string ans = "";
    while (cur != start)
    {
        int x = visited[cur.first][cur.second];
        ans += dd[x];

        cur.first -= direc[x].first;
        cur.second -= direc[x].second;

        // cout << cur.first << " " << cur.second << endl;
    }

    reverse(ans.begin(), ans.end());
    cout << ans.length() << endl;
    cout << ans;


}