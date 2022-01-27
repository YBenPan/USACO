#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
vi g[100005];
int x[100005], y[100005];
bool visited[100005];
struct rect
{
    int maxx, minx, maxy, miny;
};
rect dfs(int s)
{
    visited[s] = true;
    rect cur = {x[s], x[s], y[s], y[s]};
    for (int i = 0; i < g[s].size(); ++i)
        if (!visited[g[s][i]])
        {
            rect tmp = dfs(g[s][i]);
            cur.maxx = max(cur.maxx, tmp.maxx);
            cur.minx = min(cur.minx, tmp.minx);
            cur.maxy = max(cur.maxy, tmp.maxy);
            cur.miny = min(cur.miny, tmp.miny);
        }
    return cur;
}
int main()
{
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i];
    }
    int p, q;
    for (int i = 1; i <= m; ++i)
    {
        cin >> p >> q;
        g[p].pb(q);
        g[q].pb(p);
    }
    int minn = 1E9;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            rect fn = dfs(i);
            //cout << i << " " << fn.maxx << " " << fn.minx << " " << fn.maxy << " " << fn.miny << endl;
            minn = min(minn, 2 * (fn.maxx - fn.minx) + 2 * (fn.maxy- fn.miny));
        }
    }
    cout << minn << endl;
    return 0;
}