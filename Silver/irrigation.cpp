#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
struct Edge
{
    int w = 1E10, to = -1;
};
int x[2005], y[2005];
int visited[2005] = {0};
Edge min_e[2005];
main()
{
    freopen("irrigation.in", "r", stdin);
    freopen("irrigation.out", "w", stdout);  
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    bool exist = true;
    int ans = 0;
    min_e[1].w = 0;
    for (int i = 1; i <= n && exist; i++)
    {
        int min_v = -1;
        for (int j = 1; j <= n; j++)
            if (!visited[j] && (min_v == -1 || min_e[j].w < min_e[min_v].w))
                min_v = j;
        if (min_e[min_v].w == 1E10)
            exist = false;
        visited[min_v] = 1;
        ans += min_e[min_v].w;
        for (int j = 1; j <= n; j++)
        {
            if (j == min_v) continue;
            int dist = (x[j] - x[min_v]) * (x[j] - x[min_v]) + (y[j] - y[min_v]) * (y[j] - y[min_v]);
            if (dist < c) continue;
            if (dist < min_e[j].w)
                min_e[j] = {dist, min_v};
        }
    }
    if (!exist) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}