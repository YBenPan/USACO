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
int n, k;
vi g[100005];
int dp[100005][4] = {0};
int c[100005] = {0};
void dfs(int s, int pa)
{
    if (g[s].size() == 1 && s != 1) 
    {
        if (c[s]) 
            dp[s][c[s]] = 1;
        else
        {
            dp[s][1] = 1; dp[s][2] = 1; dp[s][3] = 1;
        }
        return;
    }
    for (int i : g[s])
        if (i != pa)
            dfs(i, s);
    for (int i = 1; i <= 3; i++)
    {
        if (c[s] && c[s] != i) 
            continue;
        int cnt = 1;
        for (int j : g[s])
            if (j != pa)
            {
                int a, b;
                if (i == 1) a = 2, b = 3;
                else if (i == 2) a = 1, b = 3;
                else a = 1, b = 2;
                cnt = cnt * ((dp[j][a] + dp[j][b]) % MOD);
                cnt %= MOD;
            }
        dp[s][i] = cnt;
    }
}
main()
{
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    int in1, in2;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> in1 >> in2;
        g[in1].pb(in2);
        g[in2].pb(in1);
    }

    for (int i = 0; i < k; i++)
    {
        cin >> in1 >> in2;
        c[in1] = in2;
    }
    dfs(1, 1);
    cout << (dp[1][1] + dp[1][2] + dp[1][3]) % MOD << endl;
    return 0;
}