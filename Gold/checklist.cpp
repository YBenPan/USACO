#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
pi h[1005], g[1005]; 
LL dp[1005][1005][2]; 
LL dist(pi a, pi b)
{
    return (LL)(b.first - a.first) * (b.first - a.first) + (LL)(b.second - a.second) * (b.second - a.second);
}
int main()
{
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> h[i].first >> h[i].second;
    for (int i = 0; i < m; ++i) cin >> g[i].first >> g[i].second;
    for (int i = 0; i <= n; ++i) 
    {
        for (int j = 0; j <= m; ++j)
        {
            dp[i][j][0] = 1E16;
            dp[i][j][1] = 1E16;
        }
    }
    dp[1][0][0] = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i > 0 && j > 0)
            {
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + dist(h[i - 1], g[j - 1])); 
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + dist(h[i - 1], g[j - 1]));
            }
            if (i > 1)
            {
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + dist(h[i - 2], h[i - 1]));
                
            }
            if (j > 1) 
            {
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + dist(g[j - 2], g[j - 1]));
                
            }
            //cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
        }
    }
    cout << dp[n][m][0] << endl;
    return 0;
}