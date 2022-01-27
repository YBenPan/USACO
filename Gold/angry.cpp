
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
vi a;
int dp[2][50005];
main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int in;
    for (int i = 1; i <= n; i++)
    {
        cin >> in;
        a.pb(2 * in);
        // easier when a is integer array
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (int it = 0; it <= 1; it++)
    {
        dp[it][0] = -2;
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            while (j + 1 < i && abs(a[i] - a[j + 1]) > dp[it][j + 1] + 2)
                j++;
            //cout << it << " " << i << " " << j << endl;
            dp[it][i] = min(abs(a[i] - a[j]), dp[it][j + 1] + 2);
        }
        reverse(a.begin(), a.end());
    }
    int st = 0, end = n - 1;
    while (st < end)
    {
        int tmp = dp[1][st];
        dp[1][st] = dp[1][end];
        dp[1][end] = tmp;
        st++;
        end--;
    }
    int i = 0, j = n - 1, res = 1E10;
    while (i < j)
    {
        res = min(res, max((a[j] - a[i]) / 2, 2 + max(dp[0][i], dp[1][j])));
        if (dp[0][i + 1] < dp[1][j - 1])
            i++;
        else 
            j--;
    }
    if (res % 2 == 1) cout << res / 2 << ".5" << endl;
    else cout << res / 2 << ".0" << endl;
    return 0;
}
