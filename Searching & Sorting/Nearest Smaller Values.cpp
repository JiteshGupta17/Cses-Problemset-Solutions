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

    int n; cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    stack<int> s;
    int ans[n];
    
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && v[s.top()] >= v[i])
        {
            s.pop();
        }

        ans[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }

    for (int ele : ans) cout << ele << " ";

}