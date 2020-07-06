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
        int n; cin >> n;
        int sum; cin >> sum;

        map<int, int> mp;

        for (int i = 1; i <= n; i++)
        {
            int x; cin >> x;

            int rem = sum - x;

            if (mp.count(rem))
            {
                cout << mp[rem] << " " << i;
                return 0;
            }
            else mp[x] = i;
        }

        cout << "IMPOSSIBLE";
    }

}