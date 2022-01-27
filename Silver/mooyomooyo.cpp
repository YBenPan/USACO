#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, k;
vector<char> g[10], g_new[10];
bool visited[15][105] = {0}, deleted[1005];
int cc[15][105]; 
int dfs(int x, int y, int indx, char target)
{
    if (x < 0 || x >= 10 || y < 0 || y >= n) return 0; 
    if (g[x][y] != target) return 0; 
    if (visited[x][y]) return 0; 
    int cnt = 1;
    visited[x][y] = true; 
    cc[x][y] = indx; 
    cnt += dfs(x - 1, y, indx, target); 
    cnt += dfs(x + 1, y, indx, target);
    cnt += dfs(x, y - 1, indx, target); 
    cnt += dfs(x, y + 1, indx, target); 
    return cnt; 
}
int main()
{
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    char input; 
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cin >> input; 
            g[j].pb(input); 
        }
    }
    for (int j = 0; j < 10; ++j) 
    {
        reverse(g[j].begin(), g[j].end()); 
    }
    while (true)
    {
        int indx = 0;
        bool flag = false;
        memset(visited, 0, sizeof(visited));
        memset(cc, 0, sizeof(cc));
        memset(deleted, 0, sizeof(deleted));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                if (cc[j][i] == 0 && g[j][i] != '0')
                {
                    indx++;
                    int res = dfs(j, i, indx, g[j][i]);
                    if (res >= k)
                    { 
                        deleted[indx] = true;
                        flag = true;
                    }
                }
                g_new[j].clear();
            }
        }
        if (!flag) break; 
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                int cur = g[j][i] - '0'; 
                if (g[j][i] != '0' && !deleted[cc[j][i]])
                    g_new[j].pb(g[j][i]); 
            }
        }
        for (int i = 0; i < 10; ++i) 
        {
            while (g_new[i].size() < n) g_new[i].pb('0');
            g[i] = g_new[i]; 
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < 10; ++j)
            cout << g[j][i];
        cout << endl;
    }
    return 0;
}