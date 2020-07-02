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

    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        int st, en, price;
        cin >> st >> en >> price;

        v[i] = {{en, st}, price};
    }

    sort(v.begin(), v.end());
    set<pair<int, int>> st;

    int ans = 0;

    for (auto ele : v)
    {
        auto it = st.upper_bound({ele.first.second, 0});

        int cur;
        if (it == st.begin()) {
            //  cout<<"F"<<endl;
            cur = ele.second;
        }
        else {
            it--;
            cur = ele.second + it->second;
            // cout<<it->first<<" "<<it->second<<endl;
        }

        ans = max(ans, cur);
        st.insert({ele.first.first, ans});

    }

    cout << ans;

}