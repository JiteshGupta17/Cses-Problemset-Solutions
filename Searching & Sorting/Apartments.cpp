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
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> desir(n);
        for (int i = 0; i < n; i++) cin >> desir[i];

        sort(desir.begin(), desir.end());

        vector<int> rooms(m);
        for (int i = 0; i < m; i++) cin >> rooms[i];

        sort(rooms.begin(), rooms.end());

        int j = 0;
        int cnt = 0;
        for (int i = 0; i < n && j < m;)
        {
            if (rooms[j] >= desir[i] - k && rooms[j] <= desir[i] + k)
            {
                j++;
                cnt++;
                i++;
            }
            else if (rooms[j] < desir[i]) j++;
            else i++;
        }

        cout << cnt;


    }


}