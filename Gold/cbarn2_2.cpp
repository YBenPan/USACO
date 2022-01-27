#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL dp[8][205] = {0}, val[205][205] = {0};
LL a[205]; 
int main()
{
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    LL ans = 1E15;
    for (int i = 1; i <= n; ++i)
    {
        memset(val, 0, sizeof(val));
        memset(dp, 0x7f7f7f7f, sizeof(dp)); 
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                val[i][j] = val[i][j - 1] + a[j] * (j - i);
            }
        }
        for (int j = 1; j <= n; ++j) dp[1][j] = val[1][j];
        for (int j = 2; j <= m; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                for (int p = 1; p < k; ++p)
                {
                    dp[j][k] = min(dp[j][k], dp[j - 1][p] + val[p + 1][k]); 
                }
            }
        }
        ans = min(ans, dp[m][n]); 
        rotate(a + 1, a + 2, a + n + 1); 
    }
    cout << ans << endl;
    return 0;
}

