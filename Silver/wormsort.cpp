#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m;
int p[100005];
vector<pi> g[100005];
//bool visited[1005];
vi component(100005);
void dfs(int s, int fill_index, int width)
{
    component[s] = fill_index;
    for (int i = 0; i < g[s].size(); ++i)
    {
        if (component[g[s][i].first] == -1 && g[s][i].second >= width)
            dfs(g[s][i].first, fill_index, width);
    }
}
int main()
{
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int input;
    bool check = true;
    for (int i = 1; i <= n; ++i) 
    {
        cin >> p[i];
        if (p[i] != i) check = false;
    }
    int a, b, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> w;
        g[a].pb({b, w});
        g[b].pb({a, w});
    }
    if (check) {cout << -1 << endl; return 0;}
    int low = 0, high = 1E9;
    int ans = -2;
    //cout << g[1][2] << endl;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        fill (component.begin(), component.end(), -1);
        //memset(visited, 0, sizeof(visited));
        int fill_index = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (component[i] > -1) continue;
            dfs(i, fill_index, mid);
            fill_index++;
        }
        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            if (component[i] != component[p[i]])
                flag = false;
        }
        if (flag) 
        {
            ans = mid;
            low = mid + 1;
        }
        else 
            high = mid - 1;
    }
    cout << ans << endl;
    return 0;
}