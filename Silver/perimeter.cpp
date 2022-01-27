#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, area, perimeter, max_area = 0, max_perimeter = 0;
char g[1005][1005];
int pm[1005][1005] = {0};
bool visited[1005][1005] = {0};
void dfs(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n) return;
    if (visited[x][y]) return;
    if (g[x][y] != '#') return;
    visited[x][y] = true;
    area++;
    perimeter += pm[x][y];
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}
int main()
{
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> g[i][j];
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (g[i][j] == '#')
            {
                if (g[i - 1][j] != '#') pm[i][j]++;
                if (g[i + 1][j] != '#') pm[i][j]++;
                if (g[i][j - 1] != '#') pm[i][j]++;
                if (g[i][j + 1] != '#') pm[i][j]++;
            }
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            area = 0;
            perimeter = 0;
            dfs(i, j);
            if (area == max_area)
                max_perimeter = min(max_perimeter, perimeter);
            else if (area > max_area)
            {
                max_area = area;
                max_perimeter = perimeter;
            }
        }
    cout << max_area << " " << max_perimeter << endl;
    return 0;
}