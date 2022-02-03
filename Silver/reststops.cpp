#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
#define pll pair<LL, LL>
bool cmp(pll a, pll b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
int main()
{
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    LL l, n, john, bes; 
    cin >> l >> n >> john >> bes; 
    vector<pll> stops(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> stops[i].first >> stops[i].second;
    }
    sort(stops.begin(), stops.end(), cmp);
    //for (auto i : stops) cout << i.first << " " << i.second << endl;
    LL cur = 0; 
    LL ans = 0;
    for (auto i : stops)
    {
        LL indx = i.first, reward = i.second;
        if (indx < cur) continue;
        LL time = (indx - cur) * (john - bes); 
        ans += time * reward; 
        cur = indx; 
    }
    cout << ans << endl;
    return 0;
}