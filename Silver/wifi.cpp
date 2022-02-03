#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>

main()
{
    freopen("wifi.in", "r", stdin);
    freopen("wifi.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int cow[2005];
    int dp[2005];
    int a, b;
    int n;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) cin >> cow[i]; 
    sort(cow + 1, cow + n + 1); 
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 9 * 1E18; 
        for (int j = 0; j <= i - 1; ++j)
        {
            int cost = 2.0 * a + (cow[i] - cow[j + 1]) * b;             
            dp[i] = min(dp[i], dp[j] + cost); 
        }
        //cout << i << " " << dp[i] << endl;
    }
    if (dp[n] % 2 == 0) cout << (int)dp[n] / 2 << endl;
    else cout << fixed << setprecision(1) << dp[n] / 2.0 << endl;
    return 0;
}