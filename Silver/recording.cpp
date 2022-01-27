#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
pi a[155];
bool cmp(pi x, pi y)
{
    if (x.second == y.second) return x.first < y.first;
    return x.second < y.second;
}
main()
{
    freopen("recording.in", "r", stdin);
    freopen("recording.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n, cmp);
    int t1 = 0, t2 = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].first >= t1 && a[i].first >= t2)
        {
            if (t1 > t2) t1 = a[i].second;
            else t2 = a[i].second;
            ans++;
        }
        else if (a[i].first >= t1) 
        {
            t1 = a[i].second;
            ans++;
        }
        else if (a[i].first >= t2)
        {
            t2 = a[i].second;
            ans++; 
        }
    }
    cout << ans << endl;
    return 0;
}