#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, cnt = 0;
char g[25][25];
bool square_visited[25][25][25][25];
bool visited[25][25];
struct node
{
    int x1, x2, y1, y2;
};
vector<node> ans;
void dfs(int x, int y, int x1, int x2, int y1, int y2)
{
    if (x < x1 || x > x2 || y < y1 || y > y2) return;
    if (visited[x][y]) return;
    visited[x][y] = true;
    if (g[x][y] == g[x + 1][y]) dfs(x + 1, y, x1, x2, y1, y2);
    if (g[x][y] == g[x - 1][y]) dfs(x - 1, y, x1, x2, y1, y2);
    if (g[x][y] == g[x][y + 1]) dfs(x, y + 1, x1, x2, y1, y2);
    if (g[x][y] == g[x][y - 1]) dfs(x, y - 1, x1, x2, y1, y2);
}
bool check(int x1, int x2, int y1, int y2)
{
    memset(visited, 0, sizeof(visited));
    int cc[26] = {0};
    int color_cnt = 0;
    for (int i = x1; i <= x2; ++i)
    {
        for (int j = y1; j <= y2; ++j)
        {
            if (!visited[i][j])
            {
                //cout << i << " " << j << " " << g[i][j] << endl;
                int cur = g[i][j] - 'A';
                if (cc[cur] == 0) color_cnt++;
                cc[cur]++;
                dfs(i, j, x1, x2, y1, y2);
                
            }
        }
    }
    if (color_cnt != 2) return false;
    bool flag1 = false, flag2 = false;
    for (int i = 0; i < 26; ++i)
    {
        if (cc[i] == 1) flag1 = true;
        if (cc[i] > 1) flag2 = true;
    }
    return flag1 && flag2;
}
void build()
{
    for (int x1 = 1; x1 <= n; ++x1)
    {
        for (int x2 = x1; x2 <= n; ++x2)
        {
            for (int y1 = 1; y1 <= n; ++y1)
            {
                for (int y2 = y1; y2 <= n; ++y2)
                {
                    if (check(x1, x2, y1, y2))
                    {
                        ans.pb({x1, x2, y1, y2});
                    }
                }
            }
        }
    }
}
int main()
{
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> g[j][i];
    }
    //cout << check(1, 3, 1, 4) << endl;
    build();
    for (int i = 0; i < ans.size(); ++i)
    {
        //cout << ans[i].x1 << " " << ans[i].x2 << " " << ans[i].y1 << " " << ans[i].y2 << endl;
        bool flag = true;
        for (int j = 0; j < ans.size() && flag; ++j)
        {
            if (j == i) continue;
            if (ans[j].x1 <= ans[i].x1 && ans[j].x2 >= ans[i].x2 && ans[j].y1 <= ans[i].y1 && ans[j].y2 >= ans[i].y2)
                flag = false;
        }
        if (flag) cnt++;
    }
    cout << cnt << endl;
    return 0;
}