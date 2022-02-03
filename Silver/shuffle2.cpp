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
int b[100005];
main()
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int in;
    for (int i = 1; i <= m; i++) 
    {
        cin >> in;
        b[in] = i;
    }
    int cur, x;
    for (int i = 1; i <= q; i++)
    {
        cin >> x;
        cur = n - x + 1;
        for (int j = n - m + 1; j >= 1; j--)
        {
            if (cur >= j && cur <= (j + m - 1))
            {
                cur = b[cur + 1 - j] - 1 + j;
            }
            //if (cur > j + m - 1) break;
        }
        cout << cur << "\n";
    }
       
    return 0;
}

