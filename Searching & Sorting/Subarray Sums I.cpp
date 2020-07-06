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

    int arr[n];

    // Only positive, therefor can be done with 2 pointers

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int r = 0;
    int ans = 0;
    int cum_sum = 0;

    for (int l = 0; l < n; l++)
    {
        while (r < n && cum_sum + arr[r] <= sum)
        {
            cum_sum += arr[r];
            r++;
        }

        if (cum_sum == sum) ans++;

        cum_sum -= arr[l];
    }

    cout << ans;

}