#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int g[1005][2]; 
int dir[505], rep[1005], rep2[1005], rep3[1005]; 
int main()
{
    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> g[i][0] >> g[i][1]; 
    char ch;
    for (int i = 0; i < m; ++i)
    {
        cin >> ch; 
        if (ch == 'L') dir[i] = 0;
        else if (ch == 'R') dir[i] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        int cur = i;
        for (int j = 0; j < m; ++j)
            cur = g[cur][dir[j]]; 
        rep[i] = cur; 
        rep2[i] = i; 
        rep3[i] = i;
    }
    for (int i = 1; i <= 1000; ++i)
        for (int j = 1; j <= n; ++j)
            rep2[j] = rep[rep2[j]];
    for (int i = 1; i <= 1000; ++i)
        for (int j = 1; j <= n; ++j)
            rep3[j] = rep2[rep3[j]]; 
    int k1 = k % 1000; 
    int k2 = k / 1000 % 1000; 
    int k3 = k / 1000 / 1000; 
    int cur = 1;
    for (int i = 1; i <= k3; ++i) cur = rep3[cur]; 
    for (int i = 1; i <= k2; ++i) cur = rep2[cur]; 
    for (int i = 1; i <= k1; ++i) cur = rep[cur]; 
    cout << cur << endl;
    return 0;
}