#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

const int N = 5005;
string s, t;
int dp[N][N];

int solve(int i, int j)
{
    if (i == s.length()) return t.length() - j;
    if (j == t.length()) return s.length() - i;

    int & ans = dp[i][j];
    if (ans != -1) return ans;

    if (s[i] == t[j]) return ans = solve(i + 1, j + 1);

    ans = 0;
    ans = 1 + solve(i + 1, j + 1); //Replace
    ans = min(ans, 1 + solve(i + 1, j)); //add in s
    ans = min(ans, 1 + solve(i, j + 1)); //remove in t

    return ans;
}

int32_t main()
{
    FASTIO;

    cin >> s >> t;

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0);



}