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


int32_t main()
{
    FASTIO;

    // testcases
    {

        int n; cin >> n;
        if (n == 1) {
            cout << n;
            return 0;

        }
        if (n < 4)
        {
            cout << "NO SOLUTION\n";
            return 0;
        }

        vector<int> odd, even;

        for (int i = 1; i <= n; i++)
        {
            if (i & 1) odd.pb(i);
            else even.push_back(i);
        }

        reverse(even.begin(), even.end());
        for (int i = 0; i < even.size() - 2; i++)
        {
            cout << even[i] << " ";
        }
        cout << "2 4 ";
        for (int ele : odd) cout << ele << " ";

    }


}