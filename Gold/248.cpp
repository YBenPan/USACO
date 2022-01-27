#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int a[250], dp[205][205] = {0};
main()
{
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int maxx = 0;
    for (int i = 1; i <= n; ++i) 
    {
        cin >> a[i]; 
        dp[i][i] = a[i]; 
        maxx = (maxx, dp[i][i]); 
    }
    for (int j = 1; j <= n; ++j)
        for (int i = j - 1; i >= 1; --i)
        {
            for (int k = i; k <= j - 1; ++k)
            {
                if (dp[i][k] == dp[k + 1][j] && dp[i][k] != 0)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k] + 1); 
                }
                
            }
            //cout << i << " " << j << " " << dp[i][j] << endl;
            maxx = max(maxx, dp[i][j]); 
        }
    cout << maxx << endl;
    return 0;
}