#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int x[505], y[505];
int dp[505][505] = {0};
int main()
{
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i];
    }
    memset(dp, 0x7f, sizeof(dp));
    dp[1][0] = 0;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j <= min(i - 1, k); ++j)
        {
            for (int m = 0; m <= j; ++m)
            {
                //cout << i << " " << j << " " << m << " " << i - m - 1 << " " << j - m << endl;
                int dist = abs(x[i - m - 1] - x[i]) + abs(y[i - m - 1] - y[i]);
                dp[i][j] = min(dp[i][j], dp[i - m - 1][j - m] + dist);
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[n][k] << endl;
    return 0;
}

