#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
vi g[100005], inp[50005];
int indeg[100005] = {0};
main()
{
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int len, in;
        cin >> len;
        for (int j = 0; j < len; j++)
        {
            cin >> in;
            inp[i].pb(in);
        }
    }
    int l = -1, r = m - 1, mid = m - 1;
    priority_queue<int> q;
    vi ans;
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        memset(g, 0, sizeof(g));
        memset(indeg, 0, sizeof(indeg));
        for (int i = 0; i <= mid; i++)
            for (int j = 1; j < inp[i].size(); j++)
                g[inp[i][j - 1]].pb(inp[i][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < g[i].size(); j++)
                indeg[g[i][j]]++;
        for (int i = 1; i <= n; i++)
            if (indeg[i] == 0) 
                q.push(-i);
        vi topo; int cnt = 0;
        while (!q.empty())
        {
            int t = q.top();
            q.pop();
            topo.pb(t);
            cnt++;
            for (auto i : g[-t])
                if (--indeg[i] == 0)
                    q.push(-i);
        }
        if (cnt != n) 
            r = mid - 1;
        else 
        {
            l = mid;
            ans = topo;
        }
    }
    for (int i = 0; i < ans.size(); i++) 
    {
        cout << -ans[i];
        if (i < ans.size() - 1) cout << " ";
    }
    return 0;
}