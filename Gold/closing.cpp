#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m;
int parent[200005], ht[200005], query[200005]; 
vi g[200005]; 
bool active[200005] = {0}; 
vector<bool> ans; 
void init()
{
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i; 
        ht[i] = 1;
    }
}
int find(int node)
{
    if (parent[node] != node) 
        parent[node] = find(parent[node]); 
    return parent[node]; 
}
void unite(int node1, int node2)
{
    int root1 = find(node1); 
    int root2 = find(node2);
    if (root1 == root2) return;  
    if (ht[root1] < ht[root2]) swap(root1, root2); 
    parent[root2] = root1;
    ht[root1] += ht[root2]; 
}
int main()
{
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    init();
    int in1, in2;
    for (int i = 1; i <= m; ++i)
    {
        cin >> in1 >> in2;
        g[in1].pb(in2); 
        g[in2].pb(in1); 
    }
    for (int i = 1; i <= n; ++i) cin >> query[i]; 
    reverse(query + 1, query + n + 1); 
    for (int i = 1; i <= n; ++i)
    {
        int node = query[i]; 
        active[node] = 1;
        for (auto j : g[node]) 
        {
            if (active[j])
                unite(node, j); 
        }
        if (ht[find(node)] == i) ans.pb(1); 
        else ans.pb(0);  
    }
    for (int i = ans.size() - 1; i >= 0; --i) 
        if (ans[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    return 0;
}