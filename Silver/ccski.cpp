#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int g[505][505];
bool waypt[505][505], visited[505][505]; 
main()
{
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> g[i][j]; 
        }
    int waypt_cnt = 0, waypt_i, waypt_j;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> waypt[i][j]; 
            if (waypt[i][j]) 
            {
                if (waypt_cnt == 0)
                {
                    waypt_i = i; 
                    waypt_j = j; 
                }
                waypt_cnt++; 
            }
        }
    int l = 0, r = 1E9, mid; 
    while (l != r)
    {
        mid = (l + r) / 2; 
        //cout << mid << endl;
        memset(visited, 0, sizeof(visited));
        queue<pi> q;
        q.push({waypt_i, waypt_j}); 
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 
        int cnt = 0;
        while (!q.empty())
        {
            pi t = q.front();
            q.pop(); 
            if (visited[t.first][t.second]) continue;
            // if (mid == 20) cout << t.first << " " << t.second << endl;    
            visited[t.first][t.second] = true; 
            if (waypt[t.first][t.second]) 
            {
                cnt++; 
            }
            for (int i = 0; i < 4; ++i)
            {
                int x = t.first + dx[i], y = t.second + dy[i]; 
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                int diff = abs(g[x][y] - g[t.first][t.second]); 
                if (diff <= mid) q.push({x, y}); 
            }   
        }
        if (cnt == waypt_cnt) // True
            r = mid; 
        else 
            l = mid + 1; 
    }
    cout << l << endl;
    return 0;
}