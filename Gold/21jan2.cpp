#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, k;
int b[50005], dist[50005][55]; 
int s[55][55]; 
int main()
{
    //freopen("21jan2.in", "r", stdin);
    //freopen("21jan2.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> b[i]; 
    char input;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= k; ++j)
        {
            cin >> input;
            s[i][j] = input - '0';
        }
    for (int i = 1; i <= k; ++i) 
        if (s[i][b[n]] == 1) s[i][0] = 1; 
        else s[i][0] = 0; 
    b[n] = 0; 
    deque<pi> q; 
    memset(dist, 0x3f, sizeof(dist)); 
    q.push_front({1, b[1]}); 
    dist[1][b[1]] = 0; 
    while (!q.empty())
    {
        pi t = q.front(); q.pop_front(); 
        int x = t.first, y = t.second; 
        // x: node, y: sender breed
        if (x == n && y == b[n]) break; 
        if (s[y][b[x]] == 1 && dist[x][y] < dist[x][b[x]])
        {
            dist[x][b[x]] = dist[x][y]; 
            q.push_front({x, b[x]}); 
        }
        if (x > 1 && dist[x][y] + 1 < dist[x - 1][y]) 
        {
            dist[x - 1][y] = dist[x][y] + 1; 
            q.push_back({x - 1, y}); 
        }
        if (x < n && dist[x][y] + 1 < dist[x + 1][y])
        {
            dist[x + 1][y] = dist[x][y] + 1;
            q.push_back({x + 1, y}); 
        }
    }
    if (dist[n][b[n]] < 1E9) cout << dist[n][b[n]] << endl;
    else cout << -1 << endl;
    return 0;
}