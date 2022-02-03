#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m;
vi g[3005]; 
bool removed[3005] = {0}, visited[3005] = {0}; 
set<int> in_set; 
int dfs(int s)
{
    visited[s] = true; 
    int cnt = 1;
    for (auto i : g[s])
    {
        if (!visited[i] && !removed[i])
        {
            cnt += dfs(i); 
        }
    }
    return cnt; 
}
int main()
{
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int in1, in2;
    for (int i = 0; i < m; ++i)
    {
        cin >> in1 >> in2;
        g[in1].pb(in2); 
        g[in2].pb(in1); 
    }
    for (int i = 1; i <= n; ++i) in_set.insert(i);
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            cin >> in1; 
            removed[in1] = true; 
            in_set.erase(in1);
            memset(visited, 0, sizeof(visited));
        }
        int start = *in_set.begin();
        int res = dfs(start); 
        if (res == in_set.size()) cout << "YES" << endl;
        else cout << "NO" << endl;
        //cout << res << endl;
    }
    return 0;
}