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
        int n; cin >> n;

        int sum = n * (n + 1) / 2;

        if (sum & 1)
        {
            cout << "NO" << endl;
        }
        else {
            // 1 2 3 4 5 6 7
            sum /= 2;
            int a = 0;
            int b = 0;

            vector<int> v1, v2;
            cout << "YES\n";
            for (int i = n; i >= 1; i--)
            {
                if (a <= b)
                {
                    v1.push_back(i);
                    a += i;
                }
                else if (a > b)
                {
                    v2.push_back(i);
                    b += i;
                }
            }

            cout << v1.size() << endl;
            for (int ele : v1) cout << ele << " ";
            cout << endl;
            cout << v2.size() << endl;
            for (int ele : v2) cout << ele << " ";

        }
    }


}