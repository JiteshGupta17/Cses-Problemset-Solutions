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

int power(int a, int b)
{
    if (b == 0) return 1;

    int rec = power(a, b / 2);
    rec = rec * rec;
    rec %= MOD;

    if (b & 1) {
        rec *= a;
    }

    return rec % MOD;
}

int32_t main()
{
    FASTIO;

    // testcases
    {
        int n;
        cin >> n;

        // Calculate 2 power n
        int ans = power(2, n);
        cout << ans;
    }


}