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
        int n, x;
        cin >> n >> x;

        vector<int> v(n);

        for (auto & i : v) cin >> i;

        sort(v.begin(), v.end());

        int l = 0, r = n - 1;
        int ans = 0;
        while (l <= r)
        {
            if (v[l] + v[r] <= x)
            {
                ans++;
                l++;
                r--;
            }
            else {
                ans++;
                r--;
            }
        }

        cout << ans;

    }


}