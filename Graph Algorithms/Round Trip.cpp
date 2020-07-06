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

void dfs(int cur, int parent)
{
    for (int nbr : graph[cur])
    {
        if (!visited[nbr])
        {
            visited[nbr] = cur;
            dfs(nbr, cur);
        }
        else
        {   if (nbr != parent)
            {
                vector<int> path;
                path.push_back(nbr);

                int x = cur;
                while (x != nbr)
                {
                    path.push_back(x);
                    x = visited[x];
                }

                path.push_back(nbr);
                cout << path.size() << endl;
                for (int ele : path) cout << ele << " ";
                exit(0);
            }
        }
    }
}

int32_t main()
{
    // Cycle Detection in a Undirected Graph and Printing the Cycle

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
            visited[i] = i;
            dfs(i, i);
        }
    }

    cout << "IMPOSSIBLE";
    return 0;





}