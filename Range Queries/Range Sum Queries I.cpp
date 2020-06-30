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

    int n, q;
    cin >> n >> q;

    int sum = 0;
    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        sum += x;
        arr[i] = sum;
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << arr[r] - arr[l - 1] << endl;
    }

}