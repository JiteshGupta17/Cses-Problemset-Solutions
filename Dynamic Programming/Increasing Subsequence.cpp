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

    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> list;

    for (int i = 0; i < n; i++)
    {
        auto l = lower_bound(list.begin(), list.end(), v[i]);
        if (l == list.end())
        {
            list.push_back(v[i]);
        }
        else {
            *l = v[i];
        }

    }

    cout << list.size();

}