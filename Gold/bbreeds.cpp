#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define MOD 2012
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int dp[2][1005][1005] = {0};
main()
{
    freopen("bbreeds.in", "r", stdin);
    freopen("bbreeds.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
    cin >> str;
    int n = str.size();
    dp[1][0][0] = 1;
    int tot = 0, ans = 0;
    for (int k = 0; k < n; k++)
    {
        int p = (k + 1) % 2, c = k % 2;
        tot += (str[k] == '(' ? 1 : -1);
        memset(dp[c], 0, sizeof(dp[c]));
        for (int i = 0; i <= tot; i++)
        {
            int j = tot - i;
            {
                if (str[k] == '(')
                {
                    if (i > 0) dp[c][i][j] = (dp[p][i][j] + dp[p][i - 1][j]) % MOD;
                    if (j > 0) dp[c][i][j] += (dp[p][i][j] + dp[p][i][j - 1]) % MOD;
                }
                else
                    dp[c][i][j] = (dp[p][i + 1][j] + dp[p][i][j + 1]) % MOD;
                if (k == n - 1) ans += dp[c][i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}