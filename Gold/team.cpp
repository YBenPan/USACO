#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000009
#define vi vector<int>
#define pi pair<int, int>
LL a[1005], b[1005];
LL dp[1005][1005][15] = {0}; 
int main()
{
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    sort(a + 1, a + n + 1); 
    sort(b + 1, b + m + 1); 
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j) dp[i][j][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int kk = 1; kk <= min(k, min(i, j)); ++kk)
            {
                dp[i][j][kk] = (dp[i][j][kk] + dp[i - 1][j][kk]) % MOD;
                dp[i][j][kk] = (dp[i][j][kk] + dp[i][j - 1][kk]) % MOD;
                dp[i][j][kk] = (dp[i][j][kk] - dp[i - 1][j - 1][kk] + MOD) % MOD;
                if (a[i] > b[j]) dp[i][j][kk] = (dp[i][j][kk] + dp[i - 1][j - 1][kk - 1]) % MOD; 
            }
        }
    }
    cout << dp[n][m][k] % MOD << endl;
    return 0;
}

