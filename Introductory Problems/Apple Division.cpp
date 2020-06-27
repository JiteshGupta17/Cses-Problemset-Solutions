#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define F first
#define S second
#define ull unsigned long long
#define ld long double
#define mp make_pair
#define endl "\n"

int ans = 1e18;
int n;

void solve(int arr[], int idx, int a, int b)
{
    if (idx == n)
    {
        int cur = abs(a - b);
        ans = min(ans, cur);
        return;
    }

    solve(arr, idx + 1, a + arr[idx], b);
    solve(arr, idx + 1, a, b + arr[idx]);
}

int32_t main()
{
    FASTIO;

    // testcases
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];

        solve(arr, 0, 0, 0);
        cout << ans;


    }


}