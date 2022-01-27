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
pi cow[1005];
int dp[1005][1005] = {0};
main()
{
    freopen("pogocow.in", "r", stdin);
    freopen("pogocow.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cow[i].fi >> cow[i].se;
    sort(cow, cow + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = cow[i].se;
        ans = max(ans, dp[i][i]);
        for (int j = 0; j < i; j++)
        {
            for (int k = j; k >= 0; k--)
            {
                if (cow[i].fi - cow[j].fi < cow[j].fi - cow[k].fi) break;
                dp[i][j] = max(dp[i][j], dp[j][k] + cow[i].se);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    memset(dp, 0, sizeof(dp));
    reverse(cow, cow + n);
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = cow[i].se;
        ans = max(ans, dp[i][i]);
        for (int j = 0; j < i; j++)
        {
            for (int k = j; k >= 0; k--)
            {
                if (abs(cow[i].fi - cow[j].fi) < abs(cow[j].fi - cow[k].fi)) break;
                dp[i][j] = max(dp[i][j], dp[j][k] + cow[i].se);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}