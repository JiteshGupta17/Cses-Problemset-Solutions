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

    // testcases
    {
        int n;
        cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; i++) cin >> v[i];

        map<int, int> mp;
        int prev = -1;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (mp.count(v[i]) == 0 || mp[v[i]] < prev)
            {
                ans = max(ans, i - prev);
            }
            else {
                prev = mp[v[i]];
                ans = max(ans, i - prev);
            }

            mp[v[i]] = i;
            // cout<<ans<<endl;
        }

        cout << ans;

    }

}