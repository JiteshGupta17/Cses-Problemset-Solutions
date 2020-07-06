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
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> remainders(n);
    remainders[0] = 1;

    int prev_rem = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int rem = (n + v[i] % n) % n;
        int cur_rem = (prev_rem + rem) % n;

        ans += remainders[cur_rem];
        remainders[cur_rem]++;

        prev_rem = cur_rem;
    }

    cout << ans;

}