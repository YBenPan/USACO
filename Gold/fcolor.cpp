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
int pa[200005], d[200005], pre[200005];
int n, m;
int findRoot(int a)
{
    if (pa[a] == a) return a;
    return pa[a] = findRoot(pa[a]);
}
void join(int a, int b)
{
    a = findRoot(a);
    b = findRoot(b);
    if (a == b) return;
    if (d[a] < d[b]) pa[a] = b;
    else 
    {
        pa[b] = a;
        d[a] = max(d[a], d[b] + 1);
    }
}
main()
{
    freopen("fcolor.in", "r", stdin);
    freopen("fcolor.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(pre, 0, sizeof(pre));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        pa[i] = i;
        d[i] = 1;
    }
    int v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> v >> w;
        int r = findRoot(w);
        if (pre[r] == 0) pre[r] = v;
        else
        {
            join(v, pre[w]);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << i << " " << pre[i] << endl;
    return 0;
}