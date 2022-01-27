#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
char g[35][35]; 
bool visited[35][35]; 
int n, a, b;
priority_queue< pair<int, pi> > pq; 
void add(int dist, int x, int y, int newx, int newy) 
{
    if (newx < 0 || newx >= n || newy < 0 || newy >= n || visited[newx][newy]) 
        return; 
    if (g[newx][newy] == g[x][y]) 
        pq.push({dist - a, {newx, newy}}); 
    else 
        pq.push({dist - b, {newx, newy}}); 
}
main()
{
    freopen("distant.in", "r", stdin);
    freopen("distant.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j]; 
    int maxx = 0; 
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            memset(visited, 0, sizeof(visited)); 
            pq.push({0, {i, j}}); 
            while (!pq.empty())
            {
                pair<int, pi> t = pq.top(); 
                pq.pop(); 
                int dist = t.first; 
                int x = t.second.first, y = t.second.second; 
                if (visited[x][y]) continue; 
                visited[x][y] = 1; 
                maxx = max(maxx, -dist); 
                add(dist, x, y, x - 1, y); 
                add(dist, x, y, x + 1, y); 
                add(dist, x, y, x, y - 1); 
                add(dist, x, y, x, y + 1); 
            }
        }
    cout << maxx << endl;
    return 0;
}