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

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        v[i] = {x, y};
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int prev = 0;

    for (int i = 0; i < n; i++)
    {
        int duration = v[i].first;
        prev += duration;

        ans += v[i].second - prev;
        // cout<<prev<<" "<<ans<<endl;
    }

    cout << ans;

}