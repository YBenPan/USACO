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
int n, l;
vi adj[200005];
vector<vi> up; // up[i][j] is the 2^j-th ancestor above node i
int tin[200005], tout[200005];
int timer = 0;
void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; i++) up[v][i] = up[up[v][i - 1]][i - 1]; // go up
    for (int u : adj[v])
        if (u != p) dfs(u, v);
    tout[v] = ++timer;
}
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v]; // u is ancestor of v
}
int lca(int u, int v)
{
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = l; i >= 0; --i) 
        if (!is_ancestor(up[u][i], v)) u = up[u][i]; // binary lifting
    return up[u][0];
}
void preprocess(int root)
{
    l = ceil(log2(n));
    up.assign(n, vi(l + 1));
    dfs(root, root);
}
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    preprocess(1);
    return 0;
}