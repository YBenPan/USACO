#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
string g1[505], g2[505]; 
set<string> s;
main()
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> g1[i]; 
    for (int i = 0; i < n; i++)
        cin >> g2[i]; 
    int l = 1, r = m, mid;
    while (l != r)
    {
        mid = (l + r) / 2;
        bool bflag = false; 
        for (int i = 0; i + mid - 1 <= m - 1; i++)
        {
            bool flag2 = true;
            s.clear(); 
            for (int j = 0; j < n; j++)
            {
                string str = g1[j].substr(i, mid); 
                //cout << str << endl;
                s.insert(str); 
            }
            for (int j = 0; j < n; j++)
            {
                string str = g2[j].substr(i, mid); 
                if (s.find(str) != s.end())
                {
                    flag2 = false; 
                    //cout << i << " " << j << endl;
                    break;
                }
            }
            if (flag2) 
            {
                bflag = true;
                break;
            }
        }
        if (bflag) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}