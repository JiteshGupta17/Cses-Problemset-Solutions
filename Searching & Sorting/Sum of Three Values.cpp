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

    int n, sum;
    cin >> n >> sum;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;

        v[i] = {x, i};
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1, r = n - 1;
        int req = sum - v[i].first;

        while (l < r)
        {
            if (v[l].first + v[r].first == req)
            {
                cout << v[i].second + 1 << " " << v[l].second + 1 << " " << v[r].second + 1;
                return 0;
            }
            else if (v[l].first + v[r].first > req)
            {
                r--;
            }
            else l++;
        }
    }

    cout << "IMPOSSIBLE";

}