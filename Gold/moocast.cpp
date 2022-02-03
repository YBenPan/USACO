#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n;
LL x[1005], y[1005], dist[1005][1005];
bool g[1005][1005], visited[1005];
int dfs(int s)
{
    visited[s] = true;
    int cnt = 1;
    for (int i = 1; i <= n; ++i)
        if (!visited[i] && g[s][i])
            cnt += dfs(i);
    return cnt;
}
int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dist[i][j] = abs(x[j] - x[i]) * abs(x[j] - x[i]) + abs(y[j] - y[i]) * abs(y[j] - y[i]);
    LL low = 1, high = 1250000000, ans = -1;
    while (low <= high)
    {
        LL mid = (low + high) / 2;
        memset(g, 0, sizeof(g));
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dist[i][j] <= mid) g[i][j] = true;
        if (dfs(1) == n)
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << ans << endl;
    return 0;
}