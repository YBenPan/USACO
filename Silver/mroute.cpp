#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
vector< pair<int, pi> > g[505]; 
bool visited[505] = {0}; 
struct pipe
{
    double coeff; 
    int v, c, l; 
    bool operator<(const pipe& rhs) const
    {
        return coeff < rhs.coeff; 
    }
};
main()
{
    freopen("mroute.in", "r", stdin);
    freopen("mroute.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    double x; 
    cin >> n >> m >> x; 
    int in[4]; 
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < 4; ++j) cin >> in[j]; 
        g[in[0]].pb({in[1], {in[2], in[3]}}); 
        g[in[1]].pb({in[0], {in[2], in[3]}}); 
    }
    priority_queue<pipe> pq; 
    pq.push({0, 1, 1000000, 0}); 
    while (!pq.empty())
    {
        pipe t = pq.top();
        pq.pop();
        if (visited[t.v]) continue; 
        if (t.v == n) 
        {
            cout << (int)floor(-t.coeff) << endl;
            return 0;
        }
        visited[t.v] = true; 
        // g[v]: vertex, capacity, latency
        for (auto i : g[t.v])
        {
            if (visited[i.first]) continue; 
            int lnew = t.l + i.second.first; 
            int cnew = min(t.c, i.second.second); 
            double coeff_new = (double)lnew + x / (double)cnew; 
            pq.push({-coeff_new, i.first, cnew, lnew}); 
        }
    }
    return 0;
}