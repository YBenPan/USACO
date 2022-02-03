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
int n, m, k, q;
vector<pi> g[205];
bool visited[205][205] = {0};
int dist[205][205];
void dijkstra(int s)
{
    priority_queue<pi> pq;
    dist[s][s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        pi t = pq.top();
        int v = t.se, d = t.fi;
        pq.pop();
        if (visited[s][v]) continue; visited[s][v] = true;
        for (auto i : g[v])
            if (dist[s][i.fi] > dist[s][v] + i.se)
            {
                dist[s][i.fi] = dist[s][v] + i.se;
                pq.push({-dist[s][i.fi], i.fi});
            }
    }
}
main()
{
    freopen("vacation.in", "r", stdin);
    freopen("vacation.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    cin >> n >> m >> k >> q;
    int in1, in2, in3;
    for (int i = 0; i < m; i++)
    {
        cin >> in1 >> in2 >> in3;
        g[in1].pb({in2, in3});
    }
    for (int i = 1; i <= n; i++)
        dijkstra(i);
    int cnt = 0, ans = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> in1 >> in2;
        int minn = 1E18;
        bool flag = 0;
        for (int j = 1; j <= k; j++)
        {
            if (visited[in1][j] && visited[j][in2]) flag = 1;
            minn = min(minn, dist[in1][j] + dist[j][in2]);
        }
        if (flag)
        {
            cnt++;
            ans += minn;
        }
    }
    cout << cnt << endl;
    cout << ans << endl;
    return 0;
}