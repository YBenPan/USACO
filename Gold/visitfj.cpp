#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int n, cost;
int g[105][105];
int dx[16] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 0, 1, -1};
int dy[16] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 1, -1, 0, 0};
bool visited[105][105] = {0};
int dist[105][105]; 
void dijkstra(int x, int y)
{
    priority_queue<pair<int, pi>> pq;
    pq.push({0, {x, y}});
    dist[x][y] = 0;
    while (!pq.empty())
    {
        pair<int, pi> t = pq.top();
        int d = t.fi, vx = t.se.fi, vy = t.se.se;
        pq.pop();
        if (vx == n - 1 && vy == n - 1)
        {
            cout << -d << endl;
            return;
        }
        if (visited[vx][vy]) continue; else visited[vx][vy] = true;
        
        for (int i = 0; i < 16; i++)
        {
            int nx = vx + dx[i], ny = vy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
            if (dist[nx][ny] > dist[vx][vy] + g[nx][ny] + 3 * cost)
            {
                dist[nx][ny] = dist[vx][vy] + g[nx][ny] + 3 * cost;
                pq.push({-dist[nx][ny], {nx, ny}});
            }
        }
        if (vx + vy == 2 * n - 4) 
            if (dist[n - 1][n - 1] > dist[vx][vy] + 2 * cost)
            {
                dist[n - 1][n - 1] = dist[vx][vy] + 2 * cost;
                pq.push({-dist[vx][vy] - 2 * cost, {n - 1, n - 1}});
            }
        if (vx + vy == 2 * n - 3) 
            if (dist[n - 1][n - 1] > dist[vx][vy] + cost)
            {
                dist[n - 1][n - 1] = dist[vx][vy] + cost;
                pq.push({-dist[vx][vy] - cost, {n - 1, n - 1}});
            }
    }
}
main()
{
    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    cin >> n >> cost;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    dijkstra(0, 0);
    //cout << dist[n - 1][n - 1] << endl;
    return 0;
}