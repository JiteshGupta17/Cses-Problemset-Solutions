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

    vector<int> v(n);
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        total += v[i];
    }

    sort(v.begin(), v.end());

    // total -= v[n - 1];
    // int ans = 0;

    // if (total < v[n - 1])
    // {
    //     ans = 2 * v[n - 1]; 
    // }
    // else ans = total + v[n - 1];

    int ans = max(total,2*v[n-1]);

    cout << ans;


}