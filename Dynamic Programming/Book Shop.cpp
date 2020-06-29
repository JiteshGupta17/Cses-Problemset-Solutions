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

    int n;
    cin >> n;

    int total = 0;
    cin >> total;

    vector<int> price(n);
    for (int & i : price) cin >> i;

    vector<int> pages(n);
    for (int & i : pages) cin >> i;

    vector<int> dp(total + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int amount = total; amount >= 0; amount--)
        {
            if (amount - price[i] >= 0)
            {
                dp[amount] = max(dp[amount], pages[i] + dp[amount - price[i]]);
            }
        }
    }

    int ans = dp[total];
    // for(int ele : dp) cout<<ele<<" ";
    // cout<<endl;

    cout << ans;


}