#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL b, e, p, n, m;
vector<LL> g[40005];
LL dist[3][40005]; 
bool visited[40005];
//dist[0]: from field 1
//dist[1]: from field 2
//dist[2]: from field n
void bfs(int ty, int s)
{
    queue<pair<LL, LL> > q;
    memset(visited, 0, sizeof(visited));
    q.push({s, 0});
    visited[s] = true;
    dist[ty][s] = 0;
    while (!q.empty())
    {
        pi t = q.front(); q.pop();
        int node = t.first;
        //cout << node << " ";
        for (auto i : g[node])
        {
            if (!visited[i])
            {
                q.push({i, t.second + 1});
                visited[i] = true;
            }
        }
        dist[ty][t.first] = t.second;
    }
}
int main()
{
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> b >> e >> p >> n >> m;
    int input1, input2;
    for (int i = 0; i < m; ++i)
    {
        cin >> input1 >> input2;
        g[input1].pb(input2);
        g[input2].pb(input1);
    }
    bfs(0, 1);
    //for (int i = 1; i <= n; ++i) cout << dist[0][i] << " ";
    bfs(1, 2);
    bfs(2, n);
    LL minn = dist[2][1] * b + dist[2][2] * e;
    for (int i = 1; i <= n; ++i)
    {
        minn = min(minn, ((LL)dist[0][i] * b + dist[1][i] * e + dist[2][i] * p));
    }
    cout << minn << endl;
    return 0;
}