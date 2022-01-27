#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int a[1005];
int dp[1005][1005][2]; 
main()
{
    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n); 
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 2; ++j)
            dp[i][i][j] = abs(a[i]) * n; 
    for (int i1 = 1; i1 <= n; ++i1) // left endpoint
        for (int j1 = i1 - 1; j1 >= 1; --j1) // right endpoint
        {
            int i = j1, j = i1;
            dp[i][j][0] = min(dp[i + 1][j][0] + (a[i + 1] - a[i]) * (n - j + i), dp[i + 1][j][1] + (a[j] - a[i]) * (n - j + i));
            dp[i][j][1] = min(dp[i][j - 1][1] + (a[j] - a[j - 1]) * (n - j + i), dp[i][j - 1][0] + (a[j] - a[i]) * (n - j + i));             
            // cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
        }
    cout << min(dp[1][n][0], dp[1][n][1]) << endl;
    return 0;
}