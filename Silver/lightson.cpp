#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m, cnt = 1;
vi g[105][105];
int visited[105][105] = {0}; 
// 0: off and not visited
// 1: on and visited
// 2: on and not visitied
void dfs(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n) return;
    if (visited[x][y] < 2) return;
    visited[x][y] = 1; 
    //cout << x << " " << y << endl;
    for (int i = 0; i < g[x][y].size(); ++i)
    {
        int x1 = g[x][y][i] / 1000;
        int y1 = g[x][y][i] % 1000;
        if (visited[x1][y1] == 0) 
        {
            //cout << x1 << " " << y1 << endl;
            visited[x1][y1] = 2;
            cnt++;
            if (visited[x1 - 1][y1] == 1 || visited[x1 + 1][y1] == 1 || visited[x1][y1 - 1] == 1 || visited[x1][y1 + 1] == 1)
                dfs(x1, y1);
        }
    }
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}
int main()
{
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int x, y, a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> a >> b;
        g[x][y].pb(1000 * a + b);
        //g[y][x].pb(1000 * a + b);
    }
    visited[1][1] = 2;
    dfs(1, 1);
    cout << cnt << endl;
    return 0;
}