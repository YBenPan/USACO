#include <bits/stdc++.h>
using namespace std;
long long n, t = 0;
vector<int> g[100005];
void dfs(int s, int last)
{
    int si = g[s].size();
    if (si == 1) return;
    if (t == 0) t += ceil(log2(si + 1));
    else t += ceil(log2(si));
    for (int i = 0; i < g[s].size(); ++i)
    {
        if (g[s][i] != last) {t++; dfs(g[s][i], s);}
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int x, y;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, -1);
    cout << t << endl;
}