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
int n, e;
vi g[1005];
int d[1005][1005], dp[1005];
pi a[1005];
void bfs(int s)
{
    bool visited[1005] = {0};
    d[s][s] = 0;
    visited[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (auto i : g[v])
            if (!visited[i])
            {
                d[s][i] = d[s][v] + e;
                visited[i] = true;
                q.push(i);
            }
    }
}
main()
{
    freopen("buffet.in", "r", stdin);
    freopen("buffet.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(d, 0x3f3f3f3f, sizeof(d));
    cin >> n >> e;
    int in1, in2; 
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi; a[i].se = i;
        cin >> in1;
        for (int j = 0; j < in1; j++)
        {
            cin >> in2;
            g[i].pb(in2);
        }
    }
    for (int i = 1; i <= n; i++)
        bfs(i);
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = a[i].fi;
        int v1 = a[i].se;
        for (int j = 1; j < i; j++)
        {
            int v2 = a[j].se;
            dp[i] = max(dp[i], dp[j] - d[v1][v2] + a[i].fi);    
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}