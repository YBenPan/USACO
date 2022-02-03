#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m;
int dist[505][505];  
pi bound[505][505];
char g[505][505]; 
struct node
{
    int x, y;
};
node start, finish;
bool operator<(node a, node b)
{
    return dist[a.x][a.y] > dist[b.x][b.y]; 
}
priority_queue<node> q; 
node fall(node p, int dir) //-1: up, 1: down
{
    if (dir == 1)
        return {p.x, bound[p.x][p.y].second}; 
    return {p.x, bound[p.x][p.y].first}; 
}
node move(node p, int type, int dir) //1: right, 0: flip, -1: left
{
    if (type == 1 || type == -1)
    {
        p.x += type; 
        if (p.x < 1 || p.x > m || g[p.x][p.y] == '#') return {-1, -1}; 
    }
    else dir = -dir; 
    return fall(p, dir); 
}
int main()
{
    freopen("gravity.in", "r", stdin);
    freopen("gravity.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dist, -1, sizeof(dist)); 
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> g[j][i];
            bound[j][i] = {-1, -1}; 
            if (g[j][i] == 'C') start = {j, i}; 
            else if (g[j][i] == 'D') 
            {
                finish = {j, i};
                bound[j][i] = {i, i};
            }
        }
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (g[j][i] == '#' || g[j][i] == 'D') continue;
            if (g[j][i - 1] == 'D') bound[j][i].first = i - 1;
            else if (g[j][i - 1] == '#') bound[j][i].first = i;
            else bound[j][i].first = bound[j][i - 1].first;
        }    
    for (int i = n - 1; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
        {
            if (g[j][i] == '#' || g[j][i] == 'D') continue;
            if (g[j][i + 1] == 'D') bound[j][i].second = i + 1;
            else if (g[j][i + 1] == '#') bound[j][i].second = i;
            else bound[j][i].second = bound[j][i + 1].second; 
        }
    start = fall(start, 1); 
    if (start.y < 0) {cout << -1 << endl; return 0;}
    dist[start.x][start.y] = 0; 
    q.push(start); 
    while (!q.empty())
    {
        node t = q.top(); q.pop();
        if (t.x == finish.x && t.y == finish.y) break;
        int dir = dist[t.x][t.y] % 2 ? -1 : 1;
        for (int i = -1; i <= 1; ++i)
        {
            node p = move(t, i, dir); 
            if (p.y != -1 && dist[p.x][p.y] == -1)
            {
                dist[p.x][p.y] = dist[t.x][t.y];
                if (i == 0) dist[p.x][p.y]++; 
                q.push(p); 
            }
        }
    }
    cout << dist[finish.x][finish.y] << endl;
    return 0;
}