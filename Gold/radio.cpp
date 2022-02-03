#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
pi corn[1005], corm[1005]; 
int dp[3][1005][1005];
pi move(pi point, char dir)
{
    int x = point.first, y = point.second;
    if (dir == 'N') return {x, y + 1};
    if (dir == 'S') return {x, y - 1};
    if (dir == 'E') return {x + 1, y};
    if (dir == 'W') return {x - 1, y};
    return {-1, -1};
}
int dist(pi a, pi b)
{
    return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second); 
}
int minn(int a, int b, int c)
{
    return min(a, min(b, c));
}
int main()
{
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    cin >> corn[0].first >> corn[0].second;
    cin >> corm[0].first >> corm[0].second;
    string str1, str2;
    cin >> str1; cin >> str2;
    for (int i = 1; i <= str1.size(); ++i)
        corn[i] = move(corn[i - 1], str1[i - 1]);
    for (int i = 1; i <= str2.size(); ++i)
        corm[i] = move(corm[i - 1], str2[i - 1]);
    for (int i = 0; i <= 2; ++i)
        for (int j = 0; j <= n; ++j) 
            for (int k = 0; k <= m; ++k)
                dp[i][j][k] = 1E9; 
    dp[0][0][0] = 0;
    dp[1][0][0] = 0;
    dp[2][0][0] = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            int add = dist(corn[i], corm[j]); 
            if (i > 0) dp[0][i][j] = minn(dp[0][i - 1][j], dp[1][i - 1][j], dp[2][i - 1][j]) + add;
            if (j > 0) dp[1][i][j] = minn(dp[0][i][j - 1], dp[1][i][j - 1], dp[2][i][j - 1]) + add;
            if (i > 0 && j > 0) dp[2][i][j] = minn(dp[0][i - 1][j - 1], dp[1][i - 1][j - 1], dp[2][i - 1][j - 1]) + add; 
        }
    }
    cout << minn(dp[0][n][m], dp[1][n][m], dp[2][n][m]) << endl;
    return 0;
}