#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int g[1005][1005]; 
int odd[1005], even[1005]; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) //row
    {
        for (int j = 1; j <= n; ++j) //column
        {
            cin >> g[i][j]; 
            if (i % 2) odd[j] += g[i][j]; 
            else even[j] += g[i][j]; 
        }
    }
    int maxx = 0;
    for (int i = 1; i <= n; ++i)
    {
        maxx += max(odd[i], even[i]); 
    }
    int maxx1 = 0;
    for (int i = 1; i <= n; ++i)
    {
        int a = 0, b = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (j % 2) a += g[i][j]; 
            else b += g[i][j]; 
        }
        maxx1 += max(a, b); 
    }
    cout << max(maxx, maxx1) << endl;
    return 0;
}