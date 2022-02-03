#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m;
vi gs[100005], gd[100005];
int visited[100005] = {0};
bool flag = true;
int cnt = 0;
void dfs(int s, int color)
{
    visited[s] = color;
    for (int i = 0; i < gs[s].size(); ++i)
    {
        if (visited[gs[s][i]] == 0) dfs(gs[s][i], color);
        else if (visited[gs[s][i]] != color)
        {
            flag = false;
            return;
        }
    }
    for (int i = 0; i < gd[s].size(); ++i)
    {
        if (visited[gd[s][i]] == 0) dfs(gd[s][i], 3 - color);
        else if (visited[gd[s][i]] == color)
        {
            flag = false;
            return;
        }
    }
}
int main()
{
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int x, y; char c;
    for (int i = 0; i < m; ++i)
    {
        cin >> c >> x >> y;
        if (c == 'S') 
        {
            gs[x].pb(y);
            gs[y].pb(x);
        }
        else
        {
            gd[x].pb(y);
            gd[y].pb(x);
        }
    }
    for (int i = 1; i <= n && flag; ++i)
    {
        if (visited[i] == 0)
        {
            dfs(i, 1);
            cnt++;
        }
    }
    if (!flag) cout << 0 << endl;
    else
    {
        cout << 1;
        for (int i = 0; i < cnt; ++i) cout << 0;
        cout << endl;
    }
    return 0;
}