#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
struct edge
{
    int x, y, w; 
};
struct que
{
    int k, v, index; 
};
vector<edge> g(100005);
vector<que> query(100005); 
int ht[100005], pa[100005], ans[100005]; 
int n, q;
bool cmp1(edge a, edge b)
{
    return a.w > b.w; 
}
bool cmp2(que a, que b)
{
    return a.k > b.k; 
}
int get(int s)
{
    return pa[s] == s ? s : get(pa[s]); 
}
void merge(int a, int b)
{
    a = get(a); b = get(b); 
    if (a == b) return; 
    if (ht[a] < ht[b]) swap(a, b);
    pa[b] = a; 
    ht[a] += ht[b]; 
}
int main()
{
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> g[i].x >> g[i].y >> g[i].w; 
    }
    sort(g.begin(), g.end(), cmp1);
    for (int i = 0; i < q; ++i)
    {
        cin >> query[i].k >> query[i].v; 
        query[i].index = i; 
    }
    sort(query.begin(), query.end(), cmp2);
    for (int i = 1; i <= n; ++i)
    {
        ht[i] = 1; 
        pa[i] = i; 
    } 
    int j = 0;
    for (int i = 0; i < q; ++i)
    {
        int cur = query[i].k, node = query[i].v; 
        while (j < n && g[j].w >= cur) 
        {
            merge(g[j].x, g[j].y); 
            j++; 
        }
        int loc = get(node); 
        ans[query[i].index] = ht[loc]; 
    }
    for (int i = 0; i < q; ++i) cout << ans[i] - 1 << endl;
    return 0;
}