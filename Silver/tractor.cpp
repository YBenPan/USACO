#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int g[505][505];
bool visited[505][505];
main()
{
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j]; 
    int l = 0, r = 1E6, mid;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 
    while (l != r)
    {
        mid = (l + r) / 2; 
        memset(visited, 0, sizeof(visited)); 
        int maxx = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (visited[i][j]) continue; 
                visited[i][j] = 1;
                stack<pi> q;
                q.push({i, j}); 
                int cnt = 1;
                while (!q.empty())
                {
                    pi t = q.top(); 
                    q.pop(); 
                    for (int k = 0; k < 4; ++k)
                    {
                        int x = t.first + dx[k], y = t.second + dy[k]; 
                        if (visited[x][y]) continue;
                        if (x < 0 || y < 0 || x >= n || y >= n) continue; 
                        if (abs(g[x][y] - g[t.first][t.second]) <= mid)
                        {
                            q.push({x, y});  
                            visited[x][y] = 1;
                            cnt++; 
                        }
                    }
                }
                maxx = max(maxx, cnt); 
            }
        if (maxx >= ceil(n * n / 2.0)) 
            r = mid;
        else 
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}