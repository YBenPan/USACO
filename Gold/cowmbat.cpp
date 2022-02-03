#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int a[100005]; 
int g[30][30], dist[30][30], pre[100005][30], dp[100005][30]; 
int main()
{
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dp, 0x3f, sizeof(dp)); 
    int n, m, k;
    cin >> n >> m >> k;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i)
        a[i + 1] = str[i] - 'a' + 1;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> g[i][j]; 
            dist[i][j] = g[i][j]; 
        }
    for (int kk = 1; kk <= m; ++kk)
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j)
                dist[i][j] = min(dist[i][j], dist[i][kk] + dist[kk][j]);
    for (int i = 1; i <= m; ++i)
    {
        pre[0][i] = 0;
        for (int j = 1; j <= n; ++j)
            pre[j][i] = pre[j - 1][i] + dist[a[j]][i]; 
    }
    for (int i = 1; i <= m; ++i) dp[0][i] = 0; 
    for (int i = k; i <= n; ++i)
    {
        int minn = 1E9; 
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist[a[i]][j]); 
            minn = min(minn, dp[i - k][j]);
        }
        for (int j = 1; j <= m; ++j)
            dp[i][j] = min(dp[i][j], minn + pre[i][j] - pre[i - k][j]); 
    }
    int ans = 1E9; 
    for (int i = 1; i <= m; ++i) ans = min(ans, dp[n][i]); 
    cout << ans << endl;
    return 0;
}