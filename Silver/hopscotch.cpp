#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int g[105][105], dp[105][105];
main()
{
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int r, c, k; 
    cin >> r >> c >> k;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> g[i][j]; 
    dp[1][1] = 1;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)   
            for (int k = 1; k < i; ++k)
                for (int l = 1; l < j; ++l)
                {
                    if (g[i][j] != g[k][l]) dp[i][j] = (dp[i][j] + dp[k][l]) % MOD; 
                }
    cout << dp[r][c] << endl;
    return 0;
}