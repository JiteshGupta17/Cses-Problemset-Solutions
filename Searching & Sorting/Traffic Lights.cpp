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
        int n; cin >> n;

        set<pair<int, int>> st;
        multiset<int> len;

        st.insert({0, n});
        len.insert(n);

        int q; cin >> q;

        while (q--)
        {
            int x;
            cin >> x;

            auto it = st.lower_bound({x, 0});
            it--;
            int l = it->first;
            int r = it->second;
            st.erase(it);

            auto it2 = len.find(r - l);
            len.erase(it2);

            st.insert({l, x});
            len.insert(x - l);

            st.insert({x, r});
            len.insert(r - x);

            cout << *len.rbegin() << " ";

        }

    }

}