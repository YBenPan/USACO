#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int dp[1005] = {0}; 
int main()
{
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[10005];
    for (int i = 1; i <= n; ++i) cin >> a[i]; 
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; ++i)
    {
        int maxx = 0;
        for (int j = i; j >= max(1, i - k + 1); --j)
        {
            maxx = max(maxx, a[j]); 
            dp[i] = max(dp[i], dp[j - 1] + maxx * (i - j + 1)); 
        }
        //cout << i << " " << dp[i] << endl;
    }
    cout << dp[n] << endl;
    return 0;
}