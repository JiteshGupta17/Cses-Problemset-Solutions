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


int32_t main()
{
    FASTIO;

    // testcases
    {
        string s;
        cin >> s;

        vector<int> freq(26);

        for (char ch : s)
        {
            freq[ch - 'A']++;
        }

        string ans = "";
        bool odd = 0;
        int odd_id;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] & 1)
            {
                if (odd == 1)
                {
                    cout << "NO SOLUTION\n";
                    return 0;
                }
                odd = 1;
                odd_id = i;
            }
            else {
                ans += string(freq[i] / 2, char(i + 'A'));
            }
        }
        string temp = ans;
        if (odd)
        {
            ans += string(freq[odd_id], char(odd_id + 'A'));
        }

        reverse(temp.begin(), temp.end());
        ans += temp;
        cout << ans;

    }


}