/*
BP
10/10/21
1. Dijkstra to calculate shortest paths between farm and all other vertices in a graph with reversed edges
2. Meanwhile, calculate number of complaints on each edge
3. Run another Dijkstra to find path with least complaints 
*/


#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
vector< pair<int, pi> > g[10005];
bool visited[10005] = {0}; 
vi dist(10005, 1E18); 
map<int, int> wt[10005]; 
struct state
{
    int d, v, last; 
    bool operator<(const state &rhs) const
    {
        return d > rhs.d; 
    }
}; 
priority_queue< state > pq; 
main()
{   
    freopen("gpsduel.in", "r", stdin);
    freopen("gpsduel.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int in[4]; 
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < 4; ++j) cin >> in[j]; 
        g[in[1]].pb({in[0], {in[2], in[3]}}); 
        wt[in[0]][in[1]] = 2; 
    }
    dist[n] = 0; 
    pq.push({0, n, 0}); 
    while (!pq.empty())
    {
        state t = pq.top(); 
        pq.pop(); 
        if (visited[t.v])
        {
            if (t.d == dist[t.v]) //duplicate
                if (wt[t.v][t.last] == 2) 
                    wt[t.v][t.last]--;
            continue;
        }
        dist[t.v] = t.d; 
        wt[t.v][t.last]--;
        visited[t.v] = 1;
        for (auto i : g[t.v]) 
        {
            if (visited[i.first] && dist[t.v] + i.second.first != dist[i.first]) continue;
            pq.push({dist[t.v] + i.second.first, i.first, t.v}); 
        }
    }
    fill(dist.begin(), dist.end(), 0);
    memset(visited, 0, sizeof(visited));
    dist[n] = 0; 
    pq.push({0, n, 0}); 
    while (!pq.empty())
    {
        state t = pq.top(); 
        pq.pop(); 
        if (visited[t.v])
        {
            if (t.d == dist[t.v]) //duplicate
                if (wt[t.v][t.last] == 2) 
                    wt[t.v][t.last]--;
            continue;
        }
        dist[t.v] = t.d; 
        wt[t.v][t.last]--;
        visited[t.v] = 1;
        for (auto i : g[t.v]) 
        {
            if (visited[i.first] && dist[t.v] + i.second.second != dist[i.first]) continue;
            pq.push({dist[t.v] + i.second.second, i.first, t.v}); 
        }
    }
    fill(dist.begin(), dist.end(), 0);
    memset(visited, 0, sizeof(visited));
    pq.push({0, 1, 0}); 
    while (!pq.empty())
    {
        state t = pq.top(); 
        pq.pop(); 
        if (visited[t.v]) continue; 
        if (t.v == n) 
        {
            cout << t.d << endl;
            break;
        }
        visited[t.v] = 1; 
        for (int i = 1; i <= n; ++i)
        {
            if (visited[i] || wt[t.v].count(i) == 0) continue; 
            pq.push({t.d + wt[t.v][i], i, t.v}); 
        }
    }
    return 0;
}