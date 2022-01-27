#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL dp[1005][1005] = {0}; 
int a[1005];
vi g[1005], connect_one; 
set<int> active, new_active; 
int main()
{
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i) cin >> a[i]; 
    int in1, in2;
    for (int i = 0; i < m; ++i)
    {
        cin >> in1 >> in2;
        g[in1].pb(in2);
        if (in2 == 1) connect_one.pb(in1);  
    }
    active.insert(1);
    for (int i = 0; i <= 1000; ++i)
    {
        int loss = c * (2 * i + 1); 
        for (auto j : active)
            for (auto k : g[j])
            {
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + a[k] - loss); 
                new_active.insert(k); 
            }
        active = new_active;
    }
    int ans = 0;
    for (int i = 1; i <= 1000; ++i)
    {
        int loss = c * (2 * i + 1); 
        for (auto j : connect_one)
        {
            int res = dp[i][j] - loss; 
            ans = max(ans, res); 
        }
    }
    cout << ans << endl;
    return 0;
}