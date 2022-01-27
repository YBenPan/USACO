#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, cnt = 0;
char g[20][20];
set<string> lt[20], rt[20], ans;
void search_left(int x, int y, string s)
{
    s.pb(g[x][y]);
    if (s.length() == n)
    {
        lt[x].insert(s);
        return;
    }
    search_left(x + 1, y, s);
    search_left(x, y + 1, s);
}
void search_right(int x, int y, string s)
{
    s.pb(g[x][y]);
    if (s.length() == n)
    {
        rt[x].insert(s);
        return;
    }
    search_right(x - 1, y, s);
    search_right(x, y - 1, s);
}
int main()
{
    freopen("palpath.in", "r", stdin);
    freopen("palpath.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> g[j][i];
        }
    }
    search_left(0, 0, "");
    search_right(n - 1, n - 1, "");
    for (int i = 0; i < n; ++i)
    {
        for (auto j : lt[i])
        {
            if (rt[i].count(j))
            {
                ans.insert(j);
            }
        }
    }
    cout << ans.size() << endl;
    return 0;
}