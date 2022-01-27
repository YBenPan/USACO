#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
vector<pi> g[10005]; 
struct path
{
    int dist, node, prev; 
    bool operator<(const path& rhs) const
    {
        if (dist != rhs.dist) return dist > rhs.dist;
        return prev > rhs.prev;  
    }
};
priority_queue<path> pq; 
bool visited[10005] = {0}; 
int pre[10005] = {0}, dp[10005] = {0}; 
vi dist(10005, 1E18); 
main()
{
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    int c[10005]; 
    for (int i = 1; i <= n; ++i) cin >> c[i]; 
    int in[3]; 
    for (int i = 1; i <= m; ++i)
    {
        cin >> in[0] >> in[1] >> in[2]; 
        g[in[0]].pb({in[1], in[2]}); 
        g[in[1]].pb({in[0], in[2]}); 
    }
    pq.push({0, 1, 0}); 
    while (!pq.empty())
    {
        path t = pq.top(); 
        pq.pop(); 
        if (visited[t.node]) continue; 
        visited[t.node] = 1;
        pre[t.node] = t.prev; 
        for (auto i : g[t.node])
        {
            int v = i.first; 
            if (visited[v]) continue;
            int new_dist = i.second; 
            if (new_dist + t.dist <= dist[v])
            {
                dist[v] = new_dist + t.dist; 
                pq.push({dist[v], v, t.node});
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        int cur = i; 
        while (cur != 1)
        {
            if (dist[cur] > t)
                dp[cur] += (dist[cur] - t) * c[i]; 
            cur = pre[cur]; 
        }
    }
    int ans = 0; 
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]); 
    cout << ans << endl;
    return 0;
}