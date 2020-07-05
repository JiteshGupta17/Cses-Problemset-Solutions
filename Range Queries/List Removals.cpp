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

    void update(int ts, int te, int i, int index, int val)
    {
        if (i < ts || i > te) return ;

        if (ts == te)
        {
            tree[index] += val;
            return;
        }

        int mid = (ts + te) / 2;
        update(ts, mid, i, 2 * index, val);
        update(mid + 1, te, i, 2 * index + 1, val);

        tree[index] = tree[2 * index] + tree[2 * index + 1];
    }

    int query(int ts, int te, int val, int index)
    {
        if (ts == te)
        {
            return ts;
        }

        int mid = (ts + te) / 2;

        if (tree[2 * index] >= val)
        {
            return query(ts, mid, val, 2 * index);
        }

        return query(mid + 1, te, val - tree[2 * index], 2 * index + 1);
    }

} mytree;

int32_t main()
{

    FASTIO;

    int n; cin >> n;
    mytree.init(n);

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        v[i] = x;

        mytree.update(0, n - 1, i, 1, 1);
    }

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        int cur = mytree.query(0, n - 1, x, 1);

        // cout << cur << " ";
        cout << v[cur] << " ";

        mytree.update(0, n - 1, cur, 1, -1);
    }

}