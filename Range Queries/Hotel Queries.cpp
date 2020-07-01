#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

struct segmentTree {

    vector<int> tree;
    void init(int n)
    {
        tree.resize(4 * n + 5);
    }

    void update(int ts, int te, int index, int i, int val)
    {
        if (i < ts || i > te) return;

        if (ts == te)
        {
            tree[index] += val;
            return;
        }

        int mid = (ts + te) / 2;
        update(ts, mid, 2 * index, i, val);
        update(mid + 1, te, 2 * index + 1, i, val);

        tree[index] = max(tree[2 * index], tree[2 * index + 1]);
    }

    int query(int ts, int te, int index, int val)
    {
        if (te == ts)
        {
            return te;
        }

        int mid = (ts + te) / 2;

        if (tree[2 * index] >= val)
        {
            return query(ts, mid, 2 * index, val);
        }

        return query(mid + 1, te, 2 * index + 1, val);
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
        mytree.update(1, n, 1, i, x);
    }

    while (q--)
    {
        int x; cin >> x;

        if (mytree.tree[1] < x)
        {
            cout << 0 << " ";
        }
        else {
            int idx = mytree.query(1, n, 1, x);
            cout << idx << " ";
            mytree.update(1, n, 1, idx, -x);
        }
    }

}