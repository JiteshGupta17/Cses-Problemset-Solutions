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

        vector<pair<pair<int, int>, int>> v(2 * n);
        int idx =  0;

        for (int i = 0; i < 2 * n; i += 2)
        {
            int x, y;
            cin >> x >> y;

            v[i] = {{x, 0}, idx};
            v[i + 1] = {{y, 1}, idx};

            idx++;
        }

        vector<int> ans(n);
        sort(v.begin(), v.end());

        // Will store the rooms which become vacant and have been alloted once
        set<int> st;
        int rooms_alloted = 0 ;

        for (int i = 0; i < 2 * n; i++)
        {
            auto ele = v[i];

            // cout<<ele.second<<" "<<ele.first.first<<endl;

            if (ele.first.second == 0) {
                if (st.empty())
                {
                    rooms_alloted += 1;
                    ans[ele.second] = rooms_alloted;
                }
                else {
                    auto it = st.begin();
                    ans[ele.second] = *it;
                    st.erase(*it);
                }
            }
            else {

                int room = ans[ele.second];
                st.insert(room);
            }
        }

        cout << rooms_alloted << endl;
        for (int ele : ans) cout << ele << " ";

    }

}