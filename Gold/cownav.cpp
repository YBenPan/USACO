#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int n;
/*
Directions:
0 -> North
1 -> East
2 -> South
3 -> West
*/
bool visited[21][21][21][21][4][4] = {0}; 
int dp[21][21][21][21][4][4]; 
char g[21][21]; 
struct cows
{
    int x[2], y[2], dir[2]; 
};
queue<cows> q; 
cows t1; 
void forward()
{
    for (int i = 0; i < 2; ++i)
    {
        if (t1.x[i] == n && t1.y[i] == n) continue; 
        if (t1.dir[i] == 0 && t1.y[i] < n && g[t1.x[i]][t1.y[i] + 1] == 'E') t1.y[i]++;
        if (t1.dir[i] == 1 && t1.x[i] < n && g[t1.x[i] + 1][t1.y[i]] == 'E') t1.x[i]++; 
        if (t1.dir[i] == 2 && t1.y[i] > 1 && g[t1.x[i]][t1.y[i] - 1] == 'E') t1.y[i]--;
        if (t1.dir[i] == 3 && t1.x[i] > 1 && g[t1.x[i] - 1][t1.y[i]] == 'E') t1.x[i]--;
    }
}

void left()
{
    for (int i = 0; i < 2; ++i)
    {
        if (t1.x[i] == n && t1.y[i] == n) continue; 
        t1.dir[i] = (t1.dir[i] + 3) % 4; 
    }
}
void right()
{
    for (int i = 0; i < 2; ++i)
    {
        if (t1.x[i] == n && t1.y[i] == n) continue; 
        t1.dir[i] = (t1.dir[i] + 1) % 4; 
    }
}
main()
{
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dp, 0x3f3f3f3f, sizeof(dp)); 
    cin >> n;
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= n; ++j)
            cin >> g[i][j]; 
    dp[1][1][1][1][0][1] = 0; 
    visited[1][1][1][1][0][1] = 1; 
    q.push({1, 1, 1, 1, 0, 1}); 
    while (!q.empty())
    {
        cows t = q.front(); 
        q.pop(); 
        for (int i = 0; i < 3; ++i)
        {
            t1 = t; 
            if (i == 0) forward(); 
            if (i == 1) left(); 
            if (i == 2) right(); 
            
            if (!visited[t1.x[0]][t1.y[0]][t1.x[1]][t1.y[1]][t1.dir[0]][t1.dir[1]])
            {
                dp[t1.x[0]][t1.y[0]][t1.x[1]][t1.y[1]][t1.dir[0]][t1.dir[1]] = \
                min(dp[t1.x[0]][t1.y[0]][t1.x[1]][t1.y[1]][t1.dir[0]][t1.dir[1]], dp[t.x[0]][t.y[0]][t.x[1]][t.y[1]][t.dir[0]][t.dir[1]] + 1); 

                visited[t1.x[0]][t1.y[0]][t1.x[1]][t1.y[1]][t1.dir[0]][t1.dir[1]] = 1;
                q.push(t1); 
            }
        }
    }
    int ans = 1E18; 
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            ans = min(ans, dp[n][n][n][n][i][j]); 
    cout << ans << endl;
    return 0;
}