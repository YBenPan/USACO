#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int a[405], dp[405][405] = {0}, sum = 0;
int main()
{
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) 
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            int maxx = a[i];
            dp[i][j] = 1E9; 
            for (int k = i - 1; k >= 1; --k)
            {
                if (j > 0) dp[i][j] = min(dp[i][j], dp[k][j - 1] + maxx * (i - k)); 
                maxx = max(maxx, a[k]); 
            }
            if (j == 0) dp[i][j] = maxx * i; 
        }
    }
    cout << dp[n][m] - sum << endl;
    return 0;
}