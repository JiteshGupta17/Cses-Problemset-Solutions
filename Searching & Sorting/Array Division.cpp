#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const int N = 2e5 + 5;
int v[N];
int n, k;

bool check(int maxSum)
{
    int sets = 1;
    int cur_sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > maxSum) return false;

        if (cur_sum + v[i] <= maxSum)
        {
            cur_sum += v[i];
        }
        else {
            sets ++;
            cur_sum = v[i];
        }
    }

    return sets <= k;
}

int32_t main()
{
    FASTIO;

    cin >> n;
    cin >> k;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int l = 0 , r = 1e18;
    int ans = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }

    cout << ans;

}