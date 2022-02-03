#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int dp[1005][1005] = {0}; 
int maxx[1005] = {0};
int main()
{
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int a[1005], b[1005];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) 
    {
        cin >> b[i]; 
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int tmp = 0;
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = tmp;
            if (abs(a[i] - b[j]) <= 4) dp[i][j]++;
            dp[i][j] = max(dp[i][j], dp[i - 1][j]); 
            tmp = max(tmp, dp[i - 1][j]); 
            if (i == n) ans = max(ans, dp[i][j]);   
        }
    }
    cout << ans << endl;
    return 0;
}