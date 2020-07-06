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

        vector<pair<int, int>> v(2 * n);

        for (int i = 0; i < 2 * n; i += 2)
        {
            int x, y;
            cin >> x >> y;
            v[i] = {x, 1};
            v[i + 1] = {y, 0};
        }

        sort(v.begin(), v.end());

        // for(auto ele : v) cout<<ele.first<<" "<<ele.second<<endl;

        int max_ans = 0;
        int cur = 0;

        for (int i = 0; i < 2 * n; i++)
        {
            if (v[i].second == 1) cur++;
            else cur--;

            max_ans = max(max_ans, cur);
        }

        cout << max_ans;
    }


}