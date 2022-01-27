#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int tx, ty, n, m;
int v[2005], h[2005];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct Edge 
{
    int w, tox, toy;
    Edge(int _w = 1E10, int _tox = -1, int _toy = -1)
        :w(_w), tox(_tox), toy(_toy){}
    
    bool operator<(Edge const& rhs) const
    {
        if (w != rhs.w) return w < rhs.w;
        if (tox != rhs.tox) return tox < rhs.tox;
        return toy < rhs.toy;
    }
};
priority_queue<Edge> q;
Edge min_e[2005][2005];
bool visited[2005][2005] = {0};
int dist(int x, int y, int nx, int ny)
{
    if (nx < x) swap(nx, x);
    if (ny < y) swap(ny, y);
    if (x == nx)
        return h[x] - h[x - 1];
    if (y == ny)
        return v[y] - v[y - 1];
    return -1;
}
void prim()
{
    int tot = 0, cnt = 0;
    q.push(Edge(0, 1, 1));
    min_e[1][1] = Edge(0, 1, 1);
    while (!q.empty() && cnt < (n + 1) * (m + 1))
    {
        Edge t = q.top();
        q.pop();
        if (visited[t.tox][t.toy]) continue;
        tot += t.w;
        cnt++;
        visited[t.tox][t.toy] = 1;
        for (int j = 0; j < 4; j++)
        {
            int x = t.tox + dx[j];
            int y = t.toy + dy[j];
            if (x > m + 1 || x <= 0 || y > n + 1 || y <= 0) continue;
            int wt = dist(t.tox, t.toy, x, y);
            if (!visited[x][y] && wt < min_e[x][y].w)
            {
                //q.erase(Edge(min_e[x][y].w, x, y));
                min_e[x][y] = Edge(wt, t.tox, t.toy);
                q.push(Edge(-wt, x, y));
            }
        }
    }
    cout << -tot << endl;
}
main()
{
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> tx >> ty >> n >> m;
    v[0] = 0, h[0] = 0;
    v[n + 1] = tx, h[m + 1] = ty;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= m; i++)    
        cin >> h[i];
    sort(v + 1, v + 1 + n);
    sort(h + 1, h + 1 + m);
    prim();
    return 0;
}