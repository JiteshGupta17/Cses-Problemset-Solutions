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
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int cells = i * i * (i * i - 1) / 2;
            cout << cells - 4 * (i - 1)*(i - 2) << endl;
        }

	}

}