#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n;
vi a, clck;
bool removed[2505];
map<int, vi> g;
void dfs(int s, int last)
{
    for (auto i : g[s])
    {
        if (i == last) continue;
        dfs(i, s);
        //post order traversal
        clck[s] = (clck[s] + 12 - clck[i]) % 12;
    }
}
int main()
{
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int in1, in2;
    a.pb(0);
    for (int i = 0; i < n; ++i) 
    {
        cin >> in1;
        a.pb(in1); 
    }
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> in1 >> in2;
        g[in1].pb(in2);
        g[in2].pb(in1);
    }
    int cnt = 0; 
    for (int i = 1; i <= n; ++i)
    {
        clck = a;
        dfs(i, i); 
        if (clck[i] == 0 || clck[i] == 1) cnt++;
    }
    cout << cnt << endl;
    return 0;
}