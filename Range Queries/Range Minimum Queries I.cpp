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
        tree.resize(4 * n);
    }

    void update(int ts, int te, int index, int i, int new_val)
    {
        // No overlap
        if (i > te || i < ts) return ;

        // Leaf
        if (ts == te)
        {
            tree[index] = new_val;
            return ;
        }

        // Partial overlap
        int mid = (ts + te) / 2;
        update(ts, mid, 2 * index, i, new_val);
        update(mid + 1, te, 2 * index + 1, i, new_val);

        tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    }

    int query(int ts, int te, int index, int l, int r)
    {
        // No overlap
        if (r < ts || l > te)
        {
            return 2e9;
        }

        // Complete Overlap
        if (l <= ts && r >= te)
        {
            return tree[index];
        }

        // Partial overlap
        int mid = (ts + te) / 2;
        int left = query(ts, mid, 2 * index, l, r);
        int right = query(mid + 1, te, 2 * index + 1, l, r);

        return min(left, right);
    }


} mytree;

int32_t main()
{
    FASTIO;

    int n; cin >> n;
    int q; cin >> q;

    mytree.init(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        mytree.update(0, n - 1, 1, i, x);
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        // l and r  - 1 based so minus to make them 0- based
        int cur = mytree.query(0, n - 1, 1, l - 1, r - 1);
        cout << cur << endl;
    }

}