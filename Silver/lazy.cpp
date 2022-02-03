#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL pre[405][405] = {0};
LL g[405][405];
LL n, k;
int main()
{
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> g[i][j];
            pre[i][j] = pre[i][j - 1] + g[i][j];
        }
    }
    LL maxx = 0;
    for (int i = 1; i <= n; ++i) //rows
    {
        for (int j = 1; j <= n; ++j) //columns
        {
            LL sum = 0, num = -1;
            for (int p = i - k; p <= i + k; ++p)
            {
                if (p <= i) num++;
                else num--;
                if (p < 1 || p > n) continue;
                sum += pre[p][min(j + num, n)] - pre[p][max(j - num - 1, (LL)0)];
                //if (i == 1 && j == 1) cout << p << " " << sum << endl;
            }
            maxx = max(maxx, sum);
            //cout << sum << " ";
        }
        //cout << endl;
    }
    cout << maxx << endl;
    return 0;
}