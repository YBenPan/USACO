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
bool visited[100005] = {0};
int n, m;
int prims(int s)
{
    int tot = 0;
    priority_queue<pi> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        pi t = pq.top();
        int v = t.se, d = t.fi;
        pq.pop();
        if (visited[v]) continue; else visited[v] = true;
        tot += -d;
        for (auto j : g[v])
            if (!visited[j.first])
                pq.push({-j.second, j.first});
    }
    return tot;
}
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int in[3];
    for (int i = 1; i <= m; i++)
    {
        cin >> in[0] >> in[1] >> in[2];
        g[in[0]].pb({in[1], in[2]});
        g[in[1]].pb({in[0], in[2]});
    }
    int ans = prims(1);
    for (int i = 1; i <= n; i++) if (!visited[i]) ans = -1;
    if (ans == -1) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
    return 0;
}