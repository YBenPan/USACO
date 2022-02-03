#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
priority_queue< pair<int, pi> > pq;  // dist, index, prev
int pre[255], gdist[255][255];
bool visited[255] = {0}; 
main()
{
    freopen("rblock.in", "r", stdin);
    freopen("rblock.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(gdist, -1, sizeof(gdist)); 
    int n, m;
    cin >> n >> m;
    int in[3]; 
    for (int i = 0; i < m; ++i)
    {
        cin >> in[0] >> in[1] >> in[2]; 
        gdist[in[0]][in[1]] = in[2]; 
        gdist[in[1]][in[0]] = in[2]; 
    }
    pq.push({0, {1, 0}});
    int dist; 
    while (!pq.empty())
    {
        pair<int, pi> t = pq.top(); 
        pq.pop(); 
        int d = t.first, vertex = t.second.first, prev_vertex = t.second.second; 
        if (visited[vertex]) continue; 
        if (vertex == n) 
            dist = -d; 
        pre[vertex] = prev_vertex; 
        visited[vertex] = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (visited[i] || gdist[vertex][i] == -1) continue; 
            pq.push({d - gdist[vertex][i], {i, vertex}}); 
        }
    }
    int point = n, maxx = 0; 
    int precur[255]; 
    while (point != 1) 
    {
        gdist[point][pre[point]] *= 2; 
        gdist[pre[point]][point] *= 2; 
        memset(visited, 0, sizeof(visited));
        memset(precur, 0, sizeof(precur)); 
        pq.push({0, {1, 0}});
        int dist_cur; 
        while (!pq.empty())
        {
            pair<int, pi> t = pq.top(); 
            pq.pop(); 
            int d = t.first, vertex = t.second.first, prev_vertex = t.second.second; 
            if (visited[vertex]) continue; 
            if (vertex == n) 
                dist_cur = -d; 
            precur[vertex] = prev_vertex; 
            visited[vertex] = 1;
            for (int i = 1; i <= n; ++i)
            {
                if (visited[i] || gdist[vertex][i] == -1) continue; 
                pq.push({d - gdist[vertex][i], {i, vertex}}); 
            }
        }   
        maxx = max(maxx, dist_cur - dist); 
        gdist[point][pre[point]] /= 2; 
        gdist[pre[point]][point] /= 2; 
        point = pre[point];
    }
    cout << maxx << endl;
    return 0;
}