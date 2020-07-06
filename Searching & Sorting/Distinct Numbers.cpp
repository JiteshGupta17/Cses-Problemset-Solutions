#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
// #define int long long
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
        set<int> st;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            st.insert(x);
        }

        cout << st.size();

    }


}