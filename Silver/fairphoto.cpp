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
pi a[100005];
vector<pi> pre[2];
main()
{
    freopen("fairphoto.in", "r", stdin);
    freopen("fairphoto.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >> a[i].first;
        cin >> ch;
        if (ch == 'W') a[i].second = -1;
        else a[i].second = 1;
    }
    sort(a , a + n);
    int ps = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (pre[ps & 1].empty() || ps >= pre[ps & 1].back().fi)
        {
            pre[ps & 1].pb({ps, a[i].fi});
        }
        ps += a[i].se;
        if (!pre[ps & 1].empty() && ps <= pre[ps & 1].back().fi)
        {
            int loc = lower_bound(pre[ps & 1].begin(), pre[ps & 1].end(), make_pair(ps, (int)-1E10))->second;
            ans = max(ans, a[i].first - loc);
        }
    }
    cout << ans << endl;
    return 0;
}
