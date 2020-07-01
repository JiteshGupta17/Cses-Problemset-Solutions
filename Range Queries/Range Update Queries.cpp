#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

struct fenwickTree {

    vector<int> bit;
    int n;
    void init(int nn)
    {
        n = nn + 10;
        bit.resize(n + 5);
    }

    void update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx)
    {
        int ans = 0;
        while (idx > 0)
        {
            ans += bit[idx];
            idx -= idx & (-idx);
        }

        return ans;
    }

} mytree;

int32_t main()
{
    FASTIO;

    int n; cin >> n;
    int q; cin >> q;

    mytree.init(n);

    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        mytree.update(i, x);
        mytree.update(i + 1, -x);
    }

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 2)
        {
            int x;
            cin >> x;

            int cur = mytree.query(x);
            cout << cur << endl;
        }
        else {
            int l, r, val;
            cin >> l >> r >> val;

            mytree.update(l, val);
            mytree.update(r + 1, -val);
        }
    }

}