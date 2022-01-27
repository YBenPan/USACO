#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int n, m, c;
int s[100005];
vector<pi> g[100005];
bool visited[100005] = {0};
int dist[100005];
vector<int> topo;
int rev[100005];
void dfs(int v)
{
    visited[v] = 1;
    for (pi u : g[v])
        if (!visited[u.first]) dfs(u.first);
    topo.pb(v);
}
void dfs_main()
{
    for (int i = 1; i <= n; i++)
        if (!visited[i])
        {
            dfs(i);
        }
    reverse(topo.begin(), topo.end());
}
main()
{
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= c; i++)
    {
        int in1, in2, in3;
        cin >> in1 >> in2 >> in3;
        g[in1].pb({in2, in3});
    }
    dfs_main();
    //memset(dist, 0x3f3f3f3f, sizeof(dist));
    for (int i = 0; i < topo.size(); i++) 
    {
        dist[i] = s[topo[i]];
        rev[topo[i]] = i;
    }
    int ans[100005];
    for (int i = 0; i < topo.size(); i++)
    {
        for (pi j : g[topo[i]])
        {
            int v = j.first, d = j.second;
            dist[rev[v]] = max(dist[rev[v]], dist[i] + d);
        }
        ans[topo[i]] = dist[i];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
    return 0;
}