#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int f[100005], s[100005]; 
multiset<int> spice; 
main()
{
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> f[i] >> s[i]; 
    int l = 0, sum = 0, ans = LLONG_MAX;
    for (int r = 0; r < n; ++r)
    {
        spice.insert(s[r]); 
        sum += f[r]; 
        while (l < r && sum >= m)
        {
            if (sum - f[l] < m) break;
            auto loc = spice.find(s[l]); 
            spice.erase(loc); 
            sum -= f[l]; 
            l++;
        }
        int cur = *spice.rbegin(); 
        if (sum >= m) ans = min(ans, cur); 
    }
    cout << ans << endl;
    return 0;
}
