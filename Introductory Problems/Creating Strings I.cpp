#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define F first
#define S second
#define ull unsigned long long
#define ld long double
#define mp make_pair
#define endl "\n"

set<string> st;

void permut(string s, string ans)
{
    if (s.length() == 0)
    {
        st.insert(ans);
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        permut(s.substr(0, i) + s.substr(i + 1), ans + s[i]);
    }
}

int32_t main()
{
    FASTIO;

    // testcases
    {
        string s;
        cin >> s;

        permut(s, "");
        cout << st.size() << endl;
        for (string ele : st)
            cout << ele << endl;

    }

}