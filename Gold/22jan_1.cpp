#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int b[105];
int dp[105][1005], pre[105][1005];
int add(int a, int b) {return (a + b) % MOD;}
int sub(int a, int b) {return (a - b + MOD) % MOD;}
main()
{
    //freopen("drought.in", "r", stdin);
    //freopen("drought.out", "w",stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];
    int ans = 0;
    for (int L = 0; L <= 1000; L++)
    {
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        for (int j = L; j <= b[1]; j++) 
        {
            dp[1][j] = 1;
            if (j > 0) pre[1][j] = add(pre[1][j - 1], dp[1][j]); else pre[1][j] = dp[1][j] % MOD;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = L; j <= L + (b[i] - b[i - 1]); j++) 
            {
                if (L > 0) dp[i][j] = sub(pre[i - 1][b[i - 1]], pre[i - 1][L - 1]);
                else dp[i][j] = pre[i - 1][b[i - 1]] % MOD;
                if (j > 0) pre[i][j] = add(pre[i][j - 1], dp[i][j]); 
                else pre[i][j] = dp[i][j];
                //cout << i << " " << j << " " << dp[i][j] << endl;
            }
            if (b[i] >= b[i - 1])
            {
                int cnt = 0;
                for (int j = max(L, L + (b[i] - b[i - 1] + 1)); j <= b[i]; j++)
                {
                    cnt++;
                    if (L > 0) dp[i][j] = sub(pre[i - 1][b[i - 1] - cnt], pre[i - 1][L - 1]);
                    else dp[i][j] = pre[i - 1][b[i - 1] - cnt] % MOD;
                    if (j > 0) pre[i][j] = add(pre[i][j - 1], dp[i][j]); else pre[i][j] = dp[i][j] % MOD;
                    //cout << i << " " << j << " " << dp[i][j] << endl;
                }
            }
            else
            {
                int cnt = 0;
                for (int j = L; j <= b[i]; j++)
                {
                    if (L > 0) dp[i][j] = sub(pre[i - 1][b[i] - cnt], pre[i - 1][L - 1]);
                    else dp[i][j] = pre[i - 1][b[i] - cnt] % MOD;
                    if (j > 0) pre[i][j] = add(pre[i][j - 1], dp[i][j]); else pre[i][j] = dp[i][j] % MOD;
                    cnt++;
                    //cout << i << " " << j << " " << dp[i][j] << endl;
                }
            }
            //cout << pre[i][b[i]] << endl;
        }
        //if (dp[n][L]) cout << dp[n][L] << endl;
        if (n % 2 == 0 && L == 0) ans = add(ans, dp[n][L]);
        else if (n % 2 == 1) ans = add(ans, dp[n][L]);
        //if (pre[n][b[n]]) cout << L << " " << pre[n][b[n]] << endl;
    }
    cout << ans % MOD << endl;
    return 0;
}