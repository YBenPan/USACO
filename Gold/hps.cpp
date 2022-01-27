#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int a[100005];
int dp[25][3][100005] = {0}; 
int win(int a, int b)
{
    if (a == 0 && b == 2 || a == 2 && b == 1 || a == 1 && b == 0) return 1;
    return 0;
}
int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    char ch;
    for (int i = 1; i <= n; ++i)
    {
        cin >> ch;
        if (ch == 'H') a[i] = 0;
        else if (ch == 'P') a[i] = 1;
        else a[i] = 2;
    }
    for (int p = 1; p <= n; ++p)
        for (int i = 0; i <= k; ++i)
            for (int j = 0; j <= 2; ++j)
            {
                dp[i][j][p] = dp[i][j][p - 1] + win(a[p], j); 
                if (i == 0) continue;
                if (j != 0) dp[i][j][p] = max(dp[i][j][p], dp[i - 1][0][p - 1] + win(a[p], 0)); 
                if (j != 1) dp[i][j][p] = max(dp[i][j][p], dp[i - 1][1][p - 1] + win(a[p], 1)); 
                if (j != 2) dp[i][j][p] = max(dp[i][j][p], dp[i - 1][2][p - 1] + win(a[p], 2));
            }
    cout << max(dp[k][0][n], max(dp[k][1][n], dp[k][2][n])) << endl;
    return 0;   
}