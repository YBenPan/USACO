#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
bool dp[2][5000005] = {0};
int main()
{
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, a, b;
    cin >> t >> a >> b;
    dp[0][0] = 1; 
    int maxx = 0;
    for (int j = 0; j <= t; ++j)
    {
        if (j - a >= 0) dp[0][j] |= dp[0][j - a];
        if (j - b >= 0) dp[0][j] |= dp[0][j - b]; 
        if (dp[0][j]) 
        {
            dp[1][j / 2] = true; 
            maxx = max(maxx, j); 
        }
    }
    for (int j = 0; j <= t; ++j)
    {
        if (j - a >= 0) dp[1][j] |= dp[1][j - a];
        if (j - b >= 0) dp[1][j] |= dp[1][j - b];
        if (dp[1][j]) maxx = max(maxx, j);
    }
    cout << maxx << endl;
    return 0;
}