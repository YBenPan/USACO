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
vector<pi> g[100005];
int dist[100005];
bool visited[100005] = {0};
int n, m;
void dijkstra(int s)
{
    priority_queue<pi> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty())
    {
        pi t = pq.top();
        int v = t.se, d = t.fi;
        pq.pop();
        if (visited[v]) continue; else visited[v] = true;
        for (auto i : g[v])
            if (dist[i.fi] > dist[v] + i.se)
            {
                dist[i.fi] = dist[v] + i.se;
                pq.push({-dist[i.fi], i.fi});
            }
    }
}
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    cin >> n >> m;
    int in[3];
    for (int i = 1; i <= m; i++)
    {
        cin >> in[0] >> in[1] >> in[2];
        g[in[0]].pb({in[1], in[2]});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++) 
        cout << dist[i] << " ";
    return 0;
}