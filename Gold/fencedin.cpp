#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int tx, ty, n, m;
int v_in[2005], h_in[2005];
struct Edge
{
    int w, ind, type;
    bool operator<(Edge const& rhs) const
    {
        return w < rhs.w;
    }
};
vector<Edge> g;
pi parent[2005][2005];
int depth[2005][2005];
pi findRoot(int x, int y)
{
    if (parent[x][y] == make_pair(x, y))
        return {x, y};
    return parent[x][y] = findRoot(parent[x][y].first, parent[x][y].second);
}
void merge(int x1, int y1, int x2, int y2)
{
    pi a = findRoot(x1, y1);
    pi b = findRoot(x2, y2);

    if (a == b) return;

    if (depth[a.first][a.second] < depth[b.first][b.second]) 
        parent[a.first][a.second] = make_pair(b.first, b.second);
    else 
    {
        parent[b.first][b.second] = make_pair(a.first, a.second);
        depth[a.first][a.second] = max(depth[a.first][a.second], depth[b.first][b.second] + 1);
    }
}
main()
{
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);   
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> tx >> ty >> n >> m;
    v_in[0] = 0, h_in[0] = 0;
    v_in[n + 1] = tx, h_in[m + 1] = ty;
    for (int i = 1; i <= n; i++)
        cin >> v_in[i];
    for (int i = 1; i <= m; i++)    
        cin >> h_in[i];
    for (int i = 1; i <= m + 1; i++)
        for (int j = 1; j <= n + 1; j++)
            parent[i][j] = make_pair(i, j);
    sort(v_in + 1, v_in + 1 + n);
    sort(h_in + 1, h_in + 1 + m);
    for (int i = 1; i <= n + 1; i++)
        g.pb({v_in[i] - v_in[i - 1], i, 0});
    for (int i = 1; i <= m + 1; i++)
        g.pb({h_in[i] - h_in[i - 1], i, 1});
    sort(g.begin(), g.end());
    int ans = 0;
    for (auto i : g)
        if (i.type == 0) // vertical
            for (int j = 1; j <= m; j++)
                if (findRoot(j, i.ind) != findRoot(j + 1, i.ind))
                {
                    merge(j, i.ind, j + 1, i.ind);
                    ans += i.w;
                }
        else
            for (int j = 1; j <= n ; j++)
                if (findRoot(i.ind, j) != findRoot(i.ind, j + 1))
                {
                    merge(i.ind, j, i.ind, j + 1);
                    ans += i.w;
                }
    cout << ans << endl;
    return 0;
}