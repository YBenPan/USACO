#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL dp[8][205] = {0}; 
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
        //a[i + n] = a[i]; 
    }
    LL ans = 1E15;
    for (int i = 1; i <= n; ++i)
    {
        memset(dp, 0x7f7f7f7f, sizeof(dp)); 
        dp[0][n + 1] = 0; 
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                LL val = 0;
                for (int p = k + 1; p <= n + 1; ++p)
                {
                    val += a[p - 1] * (p - k - 1); 
                    dp[j][k] = min(dp[j][k], dp[j - 1][p] + val); 
                }
                //cout << j << " " << k << " " << dp[j][k] << endl;
            }
        }
        ans = min(ans, dp[m][1]); 
        rotate(a + 1, a + 2, a + n + 1); 
    }
    cout << ans << endl;
    return 0;
}