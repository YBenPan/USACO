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
int dp[1000005] = {0}, pre[1000005] = {0};
int exp(int b, int p)
{
    int x = 1;
    for (int i = 1; i <= p; i++) x = x * b % MOD;
    return x;
}
main()
{
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    dp[0] = 1;
    pre[0] = 1;
    for (int i = 1; i <= k - 1; i++)
    {
        dp[i] = (dp[i - 1] * m) % MOD;
        pre[i] = (pre[i - 1] + dp[i]) % MOD;
    }
    for (int i = k; i <= n; i++)
    {
        dp[i] = (dp[i] + (pre[i - 1] - pre[i - k]) * (m - 1) % MOD) % MOD;
        pre[i] = (pre[i - 1] + dp[i]) % MOD;
    }
    cout << (exp(m, n) - dp[n] + MOD) % MOD << endl;
    return 0;
}