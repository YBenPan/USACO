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
int n, m;
struct edge
{
    int v, w1, w2;
};
vector<edge> g[105];
set<int> p[2][105];
void dfs(int s)
{
    if (!p[0][s].empty() || !p[1][s].empty()) return;
    if (s == 1)
    {
        p[0][s].insert(0);
        p[1][s].insert(0);
    }
    for (auto i : g[s])
    {
        dfs(i.v);
        int w[2] = {i.w1, i.w2};
        for (int j = 0; j < 2; j++)
        {
            for (int k : p[j][i.v])
            {
                p[j][s].insert(k + w[j]);
            }
        }
    }
}
main()
{
    freopen("meeting.in", "r", stdin);
    freopen("meeting.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int a, b, c, d;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c >> d;
        if (a < b) g[b].pb({a, c, d});
        else g[a].pb({b, c, d});
    }
    dfs(n);
    /*
    for (int i = 0; i < 2; i++)
    {
        for (int j : p[i][n])
            cout << j << " ";
        cout << endl;
    }*/
    for (int j : p[0][n])
    {
        if (p[1][n].find(j) != p[1][n].end()) 
        {
            cout << j << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}