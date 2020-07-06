#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const int N = 2e5 + 5;
int arr[N];
int n, t;

bool check(int time)
{
    int products = 0;

    for (int i = 0; i < n; i++)
    {
        products += time / arr[i];
        if (products >= t) return true;
    }

    return false;
}

int32_t main()
{
    FASTIO;

    cin >> n >> t;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l = 1, r = 2e18;
    int ans = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans;

}