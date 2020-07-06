#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int32_t main()
{
    FASTIO;

    // testcases
    {
        int n; cin >> n;

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;

            v[i] = {x, y};
        }

        sort(v.begin(), v.end(), cmp);

        int ans = 1;
        int prev = 0;

        for (int i = 1; i < n; i++)
        {
            if (v[i].first >= v[prev].second)
            {
                ans++;
                prev = i;
            }
        }

        cout << ans;
    }


}