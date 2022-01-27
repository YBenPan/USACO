#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n;
bool fence[2005][2005][2]; // 0 if horizontal, 1 if vertical
bool visited[2005][2005] = {0};
int cnt = 0;
int minx = 1E5, miny = 1E5, maxx = 0, maxy = 0;
int prev_x, prev_y;
void dfs(int x, int y, int dir)
{
    if (x < minx - 1 || x > maxx || y < miny - 1 || y > maxy) return;
    if (visited[x][y]) return;
    //cout << x << " " << y << endl;
    if (dir == 0 && fence[x][y][1]) return; //right
    if (dir == 1 && fence[x][y + 1][0]) return; //down
    if (dir == 2 && fence[x + 1][y][1]) return; //left
    if (dir == 3 && fence[x][y][0]) return; //up
    //cout << x << " " << y << endl;
    visited[x][y] = true;
    dfs(x + 1, y, 0);
    dfs(x, y - 1, 1);
    dfs(x - 1, y, 2);
    dfs(x, y + 1, 3);
}
int main()
{
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    string str;
    cin >> str;
    int x = 1001, y = 1001;
    for (char i : str)
    {
        if (i == 'N') {fence[x][y][1] = true; y++;}
        else if (i == 'S') {y--; fence[x][y][1] = true;}
        else if (i == 'E') {fence[x][y][0] = true; x++;}
        else if (i == 'W') {x--; fence[x][y][0] = true;}
        minx = min(minx, x);
        miny = min(miny, y);
        maxx = max(maxx, x);
        maxy = max(maxy, y);
    }
    for (int i = minx - 1; i <= maxx; i++)
    {
        for (int j = miny - 1; j <= maxy; ++j)
        {
            //cout << i << " " << j << endl;
            if (visited[i][j]) continue;
            cnt++;
            dfs(i, j, -1);
        }
    }
    //cout << minx - 1 << " " << maxx << " " << miny - 1 << " " << maxy << endl;
    cout << cnt - 1 << endl;
    return 0;
}