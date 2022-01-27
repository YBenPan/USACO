#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int a[105];
int dp[105][105][105];
int main()
{
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i]; 
    if (n == 1) {cout << (a[1] != 0) << endl; return 0;}
    for (int p = 1; p <= n; ++p)
    {
        int ans = 1E9; 
        memset(dp, 0x3f, sizeof(dp));
        dp[1][1][1] = (0 != a[1]); 
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= p && j <= i; ++j)
            {
                for (int k = 1; k < i; ++k)
                {
                    dp[i][j][i] = min(dp[i][j][i], dp[i - 1][j - 1][k] + (0 != a[i])); 
                    if (j > k) continue;       
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + (i - k != a[i]));
                    if (i == n && j == p) ans = min(ans, dp[i][j][k]); 
                }
                if (i == n && j == p) ans = min(ans, dp[i][j][i]); 
            }
        }
        cout << ans << endl;
    }
    return 0;
}