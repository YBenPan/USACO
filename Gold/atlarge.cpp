#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, k;
vi g[100005]; 
int dist[100005], min_dist[100005], parent[100005]; 
set<int> leaves; 
bool visited[100005] = {0}; 
void bfs_dist() 
{
    queue<int> q;
    visited[k] = 1;
    q.push(k); 
    while (!q.empty())
    {
        int t = q.front(); q.pop(); 
        if (g[t].size() == 1)
        {  //leaf
            leaves.insert(t); 
            min_dist[t] = dist[t];
        }
        for (auto j : g[t])
        {
            if (visited[j]) continue; 
            visited[j] = true; 
            dist[j] = dist[t] + 1;
            parent[j] = t;
            q.push(j);
        }
    }
}
int main()
{
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(min_dist, 0x3f, sizeof(min_dist)); 
    cin >> n >> k;
    int in1, in2;
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> in1 >> in2;
        g[in1].pb(in2); 
        g[in2].pb(in1); 
    }
    bfs_dist();
    bool flag = false; 
    while (!flag)
    {
        set<int> new_leaves; 
        for (auto i : leaves)
        {
            min_dist[parent[i]] = min(min_dist[parent[i]], min_dist[i]); 
            new_leaves.insert(parent[i]); 
            if (i == k) flag = true; 
        }
        leaves = new_leaves;
    }
    memset(visited, 0, sizeof(visited)); 
    queue<int> q;
    visited[k] = 1; 
    q.push(k); 
    int ans = 0;
    while (!q.empty())
    {
        int t = q.front(); q.pop(); 
        for (auto j : g[t])
        {
            if (visited[j]) continue;
            visited[j] = true;
            if (dist[j] * 2 >= min_dist[j]) ans++; 
            else q.push(j); 
        }
    }
    cout << ans << endl;
    return 0;
}