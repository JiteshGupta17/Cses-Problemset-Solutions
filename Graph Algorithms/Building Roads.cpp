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

    // No of connected Components - 1

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

    vector<bool> visited(n + 1);
    vector<int> comp;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;
        visited[i] = 1;

        comp.push_back(i);
        queue<int> q;
        q.push(i);

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            for (int nbr : graph[cur])
            {
                if (!visited[nbr])
                {
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
    }

    int ans = comp.size();
    if (ans == 0)
    {
        cout << ans;
        return 0;
    }

    cout << ans - 1 << endl;

    for (int i = 1; i < ans; i++)
    {
        cout << comp[i] << " " << comp[i - 1] << endl;
    }

}