#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const int N = 1e5 + 5;
vector<int> graph[N];
vector<int> visited(N);

void dfs(int cur)
{
    int color = visited[cur];

    for (int nbr : graph[cur])
    {
        if (!visited[nbr])
        {
            visited[nbr] = 3 - color;
            dfs(nbr);
        }
        else {
            if (visited[nbr] == color)
            {
                // Presence of odd length cycle
                cout << "IMPOSSIBLE";
                exit(0);
            }
        }
    }
}

int32_t main()
{
    // Bipartite
    FASTIO;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << visited[i] << " ";
    }


}