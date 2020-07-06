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

    int n, m;
    cin >> n >> m;

    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> visited(n + 1);

    visited[1] = 1;
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur == n)
        {
            break;
        }

        for (int nbr : graph[cur])
        {
            if (!visited[nbr])
            {
                visited[nbr] = cur;
                q.push(nbr);
            }
        }
    }


    if (!visited[n])
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> path;
    int x = n;
    path.push_back(x);

    while (x != 1)
    {
        x = visited[x];
        path.push_back(x);
    }

    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for (int ele : path) cout << ele << " ";

}