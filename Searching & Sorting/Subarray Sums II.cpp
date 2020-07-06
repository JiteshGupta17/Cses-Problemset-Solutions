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

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    map<int, int> mp;
    mp[0] = 1;

    int cum_sum = 0;
    int ans = 0 ;
    for (int i = 0; i < n; i++)
    {
        cum_sum += v[i];
        if (mp.count(cum_sum - sum))
        {
            ans += mp[cum_sum - sum];
        }

        mp[cum_sum]++;
    }

    cout << ans;

}