#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
pi bale[100005]; 
bool cmp(pi a, pi b)
{
    return a.second < b.second; 
}
main()
{
    freopen("trapped.in", "r", stdin);
    freopen("trapped.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, b;
    cin >> n >> b; 
    for (int i = 1; i <= n; ++i) cin >> bale[i].first >> bale[i].second; 
    sort(bale + 1, bale + n + 1, cmp); 
    //for (int i = 1; i <= n; ++i) cout << bale[i].first << " " << bale[i].second << endl;
    int l = 0, r = 1, lc, rc; 
    if (n == 1) 
    {
        int diff = abs(bale[1].second - b); 
        if (diff >= bale[1].first) cout << diff - bale[1].first << endl;
        else cout << 0 << endl;
        return 0;
    }
    if (b > bale[n].second) 
    {
        l = lc = n;
        r = rc = n + 1;

    }
    for (int i = 1; i < n; ++i)
    {
        if (bale[i].second < b && bale[i + 1].second > b) 
        {
            l = lc = i; 
            r = rc = i + 1;
        }
        
    }
    int ans = 1E16; 
    for (; r <= n; ++r)
    {
        
        while (l > 0)
        {
            int diff = bale[r].second - bale[l].second; 
            if (diff <= bale[l].first) // valid
            {
                ans = min(ans, diff - bale[r].first); 
                break; 
            }
            else l--; 
            
        }
    }
    l = lc, r = rc; 
    for (; l >= 1; --l)
    {
        while (r <= n)
        {
            int diff = bale[r].second - bale[l].second; 
            if (diff <= bale[r].first) // valid
            {
                ans = min(ans, diff - bale[l].first); 
                break; 
            }
            else r++; 
           
        }
    }
    if (ans != 1E16) cout << max(ans, (int)0) << endl;
    else cout << -1 << endl;   
    return 0;
}