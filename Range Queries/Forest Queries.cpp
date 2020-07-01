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

    int n; cin >> n;
    int q; cin >> q;

    char forest[n + 1][n + 1];
    for (int i  = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> forest[i][j];
        }
    }

    vector<vector<int>> prefix(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j =  1; j <= n; j++)
        {
            prefix[i][j] = prefix[i][j - 1] + (forest[i][j] == '*');
        }
    }

    for (int j = 1; j <= n; j++)
    {
        for (int i = 2; i <= n; i++)
        {
            prefix[i][j] += prefix[i - 1][j];
        }
    }

    while (q--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int cur = prefix[l2][r2] - prefix[l2][r1 - 1] - prefix[l1 - 1][r2] + prefix[l1 - 1][r1 - 1];
        cout << cur << endl;
    }

}