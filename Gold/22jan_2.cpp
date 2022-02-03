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
vector<pi> e; // added edges
bool active[1000005];
vector<pi> q; // q=0: D, q=1: R
int pa[1000005], d[1000005], tim[1000005] = {0};
int findRoot(int a)
{
    if (pa[a] == a) return a;
    return findRoot(pa[a]);
}
void join(int a, int b, int cur_ti)
{
    a = findRoot(a);
    b = findRoot(b);
    if (a == b) return;
    if (!active[a] && active[b])
    {
        tim[a] = cur_ti;
        active[a] = 1;
    }
    else if (!active[b] && active[a])
    {
        tim[b] = cur_ti;
        active[b] = 1;
    }
    if (d[a] < d[b]) pa[a] = b;
    else {
        pa[b] = a;
        d[a] = max(d[a], d[b] + 1);
    }
}
int findTime(int a)
{
    if (tim[a] > 0) return tim[a];
    if (pa[a] == a) return tim[a];
    return findTime(pa[a]);
}
main()
{
    //freopen("2.in", "r", stdin);
    //freopen("2.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, query;
    cin >> n >> query;
    memset(active, 1, sizeof(active));
    memset(d, 1, sizeof(d)); 
    for (int i = 1; i <= n; i++) {pa[i] = i; tim[i] = query;}
    vector<bool> e_active;
    for (int i = 0; i < query; i++)
    {
        char ch; cin >> ch;
        if (ch == 'A') 
        {
            int x, y; cin >> x >> y;
            e.pb({x, y});
            q.pb({-1, -1});
            e_active.pb(1);
        }
        else if (ch == 'D')
        {
            int x; cin >> x;
            active[x] = 0;
            tim[x] = 0;
            q.pb({0, x});
        }
        else if (ch == 'R')
        {
            int x; cin >> x;
            q.pb({1, x - 1});
            e_active[x - 1] = 0;
        }
    }
    for (int i = 0; i < e.size(); i++)
        if (e_active[i]) join(e[i].fi, e[i].se, query);
    for (int i = q.size() - 1; i >= 0; i--)
    {
        int t = q[i].fi, v = q[i].se;
        if (t == -1) continue;
        if (t == 0)
        {
            v = pa[v];
            if (!active[v])
            {
                active[v] = 1;     
                tim[v] = i;
            }
        }
        else 
        {
            int a = e[v].fi, b = e[v].se;
            join(a, b, i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << findTime(i) << endl;
    }
    return 0;
}