#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n;
pi a[100005];
int dist[100005]; 
bool visited[100005] = {0}; 
map<int, vi> x, y;
int main()
{
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> a[0].first >> a[0].second >> a[n + 1].first >> a[n + 1].second;
    for (int i = 0; i <= n + 1; ++i)
    {
        if (i >= 1 && i <= n) cin >> a[i].first >> a[i].second;
        x[a[i].first].pb(i); 
        y[a[i].second].pb(i); 
    }
    queue<pi> q;
    //dir = 0: horizantal, dir = 1: vertical
    visited[0] = 1;
    dist[0] = 0;
    q.push({0, 0}); 
    q.push({0, 1});
    bool found = false;
    while (!q.empty() && !found)
    {
        pi t = q.front(); q.pop(); 
        int node = t.first, dir = t.second;
        if (dir == 1)
        {
            for (auto i : x[a[node].first])
            {
                if (visited[i]) continue;
                visited[i] = 1;
                dist[i] = dist[node] + 1;
                q.push({i, 0}); 
                if (i == n + 1) found = true; 
            }
        }
        else
        {
            for (auto i : y[a[node].second])
            {
                if (visited[i]) continue;
                visited[i] = 1;
                dist[i] = dist[node] + 1;
                q.push({i, 1}); 
                if (i == n + 1) found = true; 
            }
        }
        
    }
    if (!found) {cout << -1 << endl; return 0;}
    cout << dist[n + 1] - 1 << endl;
    return 0;
}