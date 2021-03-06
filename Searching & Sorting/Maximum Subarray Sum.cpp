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

        int cur = v[0];
        int maxSofar = v[0];

        for (int i = 1; i < n; i++)
        {
            cur = max(cur + v[i], v[i]);
            maxSofar = max(maxSofar, cur);
        }

        cout << maxSofar;
    }

}