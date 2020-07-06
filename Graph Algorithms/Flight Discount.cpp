#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

void djkstra(int src, vector<int>&dist, vector<pair<int, int>> graph[])
{
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if (dist[cur.second] < cur.first) continue;

        for (auto nbr : graph[cur.second])
        {
            if (dist[nbr.first] > cur.first + nbr.second)
            {
                dist[nbr.first]  =  cur.first + nbr.second;
                pq.push({dist[nbr.first], nbr.first});
            }
        }
    }
}

int32_t main()
{


    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> graph1[n + 1];
    vector<pair<int, int>> graph2[n + 1];


    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;

        graph1[x].push_back({y, wt});
        graph2[y].push_back({x, wt});
    }

    vector<int> dist_s(n + 1, 1e17);
    vector<int> dist_d(n + 1, 1e17);

    djkstra(1, dist_s, graph1);
    djkstra(n, dist_d, graph2);

    int ans = 1e18;

    for (int i = 1; i <= n; i++)
    {
        for (auto nbr : graph1[i])
        {
            int cur = dist_s[i] + nbr.second / 2 + dist_d[nbr.first];
            ans = min(ans, cur);
        }
    }

    cout << ans;

}