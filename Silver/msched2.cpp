#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int n, m;
set<int> v;
int a[10005], dp[10005] = {0}, ans = 0;
vi g[10005];
void dfs(int s)
{   
    if (dp[s] > 0) return;
    if (g[s].size() == 0) 
    {
        dp[s] = a[s];
        return;
    }
    int cnt = 0;
    for (int i : g[s])
    {
        dfs(i);
        cnt = max(cnt, dp[i]);
    }
    dp[s] = cnt + a[s];    
}
main()
{
    freopen("msched.in", "r", stdin);
    freopen("msched.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
    {
        v.insert(i);
        cin >> a[i];
    }
    int in1, in2;
    for (int i = 1; i <= m; i++)
    {
        cin >> in1 >> in2;
        g[in2].pb(in1);
        v.erase(in1);
    }
    for (auto i : v)
        dfs(i);
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}