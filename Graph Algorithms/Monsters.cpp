#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

vector<pair<int, int>> direc = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
string dd = "RDLU";

int visited[1001][1001];

int32_t main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edge;
    pair<int, int> aa;

    char board[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && (board[i][j] == '.' || board[i][j] == 'A'))
            {
                if (board[i][j] == 'A')
                {
                    cout << "YES\n0";
                    return 0;
                }
                edge.push_back({i, j});
            }

            if (board[i][j] == 'A')
            {
                aa = {i, j};
            }
        }
    }


    for (auto p : edge)
    {

        memset(visited, -1, sizeof visited);

        queue<pair<int, int>> q;

        q.push(p);
        visited[p.first][p.second] = 0;
        bool f = false;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            if (board[cur.first][cur.second] != '.')
            {
                f = (board[cur.first][cur.second] == 'A');
                break;
            }

            for (int d = 0; d < 4; d++)
            {
                int x = cur.first + direc[d].first;
                int y = cur.second + direc[d].second;

                if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] != '#' && visited[x][y] == -1)
                {
                    visited[x][y] = d;
                    q.push({x, y});
                }
            }
        }



        if (f)
        {
            cout << "YES\n";
            string ans = "";
            pair<int, int> cur = aa;

            while (cur != p)
            {
                int x = visited[cur.first][cur.second];

                if (dd[x] == 'R') ans += 'L';
                else if (dd[x] == 'L') ans += 'R';
                else if (dd[x] == 'U') ans += 'D';
                else ans += 'U';

                cur.first -= direc[x].first;
                cur.second -= direc[x].second;
            }

            cout << ans.length() << endl;
            cout << ans;

            return 0;
        }
    }

    cout << "NO";


}