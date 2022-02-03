#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int g[505][505];
int sizes[505][505], loc[505][505] = {0};
pi parent[505][505];
int n, m, t, ans = 0;
pi findRoot(pi a)
{
    if (parent[a.first][a.second] == a)
        return a;
    return parent[a.first][a.second] = findRoot(parent[a.first][a.second]);
}
void join(pi a, pi b, int wt)
{
    a = findRoot(a);
    b = findRoot(b);
    if (a == b) return; 
    if (sizes[a.first][a.second] < sizes[b.first][b.second])
    {
        parent[a.first][a.second] = b;
        int newloc = loc[a.first][a.second] + loc[b.first][b.second];
        if (sizes[a.first][a.second] + sizes[b.first][b.second] >= t)
        {
            if (sizes[a.first][a.second] < t) 
            {
                ans += wt * loc[a.first][a.second];
                newloc -= loc[a.first][a.second];
            }
            if (sizes[b.first][b.second] < t) 
            {
                ans += wt * loc[b.first][b.second];
                newloc -= loc[b.first][b.second];
            }
        }
        loc[b.first][b.second] = newloc;
        sizes[b.first][b.second] += sizes[a.first][a.second];
    }
    else 
    {
        parent[b.first][b.second] = a;
        int newloc = loc[a.first][a.second] + loc[b.first][b.second];
        if (sizes[a.first][a.second] + sizes[b.first][b.second] >= t)
        {
            if (sizes[a.first][a.second] < t) 
            {
                ans += wt * loc[a.first][a.second];
                newloc -= loc[a.first][a.second];
            }
            if (sizes[b.first][b.second] < t) 
            {
                ans += wt * loc[b.first][b.second];
                newloc -= loc[b.first][b.second];
            }
        }
        loc[a.first][a.second] = newloc;
        sizes[a.first][a.second] += sizes[b.first][b.second];
    }
}
struct edge 
{
    int x1, y1, x2, y2, wt;
    bool operator<(const edge &rhs) const
    {
        return wt < rhs.wt;
    }
};
vector<edge> edges;
pi dxy[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
main()
{
    freopen("skilevel.in", "r", stdin);
    freopen("skilevel.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            parent[i][j] = {i, j};
            sizes[i][j] = 1;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1) loc[i][j] = 1;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {   
            for (int k = 0; k < 4; k++)
            {
                int x = (i + dxy[k].first), y = (j + dxy[k].second);
                if (x >= 1 && x <= n && y >= 1 && y <= m) 
                {
                    edge tmp;
                    tmp.x1 = i, tmp.y1 = j, tmp.x2 = x, tmp.y2 = y, tmp.wt = abs(g[x][y] - g[i][j]);
                    edges.pb(tmp);
                }
            }
        }
    sort(edges.begin(), edges.end());
    for (auto i : edges)
        join({i.x1, i.y1}, {i.x2, i.y2}, i.wt);
    cout << ans << endl;
    return 0;
}