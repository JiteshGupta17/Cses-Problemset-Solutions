#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int32_t main()
{
    // Dijkstra
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> graph[n + 1];

    for (int i = 0; i < m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;

        graph[x].push_back({y, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // dist,city
    pq.push({0, 1});

    vector<int> dist(n + 1, 1e18);
    vector<bool> visited(n + 1, 0);
    dist[1] = 0;

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if (visited[cur.second]) continue;

        visited[cur.second] = 1;

        for (auto nbr : graph[cur.second])
        {
            if (dist[nbr.first] > cur.first + nbr.second)
            {
                dist[nbr.first] = cur.first + nbr.second;
                pq.push({dist[nbr.first], nbr.first});
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << dist[i] << " ";


}