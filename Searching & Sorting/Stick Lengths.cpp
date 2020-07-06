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
        // Find the median
        // 1 2 2 4 5 5

        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end());

        int x = n / 2;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += abs(v[i] - v[x]);
        }

        if (n % 2 == 0)
        {
            x--;
            int ans2 = 0;
            for (int i = 0; i < n; i++)
            {
                ans2 += abs(v[i] - v[x]);
            }

            ans = min(ans, ans2);
        }

        cout << ans;

    }

}