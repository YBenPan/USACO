#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
struct cow
{
    int x, y, index; 
};
vector<cow> N, E; 
bool visited[2005] = {0}; 
vi g[2005]; 
bool cmp1(cow a, cow b)
{
    return a.x < b.x; 
}
bool cmp2(cow a, cow b)
{
    return a.y < b.y;
}
int dfs(int s)
{
    visited[s] = true; 
    int cnt = 1;
    for (auto i : g[s])
    {
        if (!visited[i]) cnt += dfs(i); 
    }
    return cnt; 
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    char in1; 
    int in2, in3; 
    for (int i = 0; i < n; ++i)
    {
        cin >> in1 >> in2 >> in3; 
        if (in1 == 'E') E.pb({in2, in3, i + 1}); 
        else N.pb({in2, in3, i + 1}); 
    }
    bool stop[2005] = {0}; 
    sort(N.begin(), N.end(), cmp1); 
    sort(E.begin(), E.end(), cmp2);
    for (int i = 0; i < N.size(); ++i)
    {
        for (int j = 0; j < E.size(); ++j)
        {
            if (stop[E[j].index]) continue; 
            if (E[j].x >= N[i].x || N[i].y >= E[j].y) continue; 
            if (N[i].x - E[j].x > E[j].y - N[i].y) //north stops east
            {
                stop[E[j].index] = true; 
                g[N[i].index].pb(E[j].index); 
            }
            else if (N[i].x - E[j].x < E[j].y - N[i].y) //east stops north
            {
                stop[N[i].index] = true;
                g[E[j].index].pb(N[i].index);  
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        memset(visited, 0, sizeof(visited)); 
        int res = dfs(i); 
        cout << res - 1 << endl;
    }
    return 0;
}