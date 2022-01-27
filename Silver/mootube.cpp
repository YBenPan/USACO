#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
bool visited[5005];
int val[5005][5005];
vi g[5005];
int n, q;
int dfs(int s, int k, int minn)
{
    //cout << s << " " << minn << endl;
    visited[s] = true;
    int cnt = 1;
    for (int i = 0; i < g[s].size(); ++i)
    {
        int node = g[s][i];
        if (visited[node]) continue;
        if (min(minn, val[s][node]) >= k) cnt += dfs(node, k, min(minn, val[s][node]));
    }
    return cnt;
}
int main()
{
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    int a, b, c;
    memset(g, 0, sizeof(g));
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a >> b >> c;
        g[a].pb(b);
        g[b].pb(a);
        val[a][b] = c;
        val[b][a] = c;
    }
    for (int i = 0; i < q; ++i)
    {
        memset(visited, 0, sizeof(visited));
        cin >> a >> b;
        cout << dfs(b, a, 1E9) - 1 << endl;
    }
    return 0;
}