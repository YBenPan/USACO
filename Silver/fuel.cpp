#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
pi a[50005];
int n, g, b, d;
int next(int cur, int range)
{
    int i = cur;
    while (i < n - 1)
    {
        i++;
        if (a[i].first - a[cur].first > range) return -1;
        if (a[i].second <= a[cur].second) return i;
    }
    return -1;
}
main()
{
    freopen("fuel.in", "r", stdin);
    freopen("fuel.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n >> g >> b >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    int fuel = b;
    fuel -= a[0].first;
    if (fuel < 0 || d - a[n - 1].first > g) {cout << -1 << endl; return 0;}
    for (int i = 1; i < n; i++)
        if (a[i].first - a[i - 1].first > g) {cout << -1 << endl; return 0;}
    int i = 0, tot = 0;
    while (i < n)
    {
        int j = next(i, g);
        // cout << i << " " << j << " " << tot << " " << fuel << endl;
        if (j == -1)
        {
            if (d - a[i].first <= g)
            {
                fuel -= (d - a[i].first);
                if (fuel < 0) tot += (-fuel) * a[i].second;
                i = n; break;
            }
            else
            {
                tot += (g - fuel) * a[i].second;
                fuel = g - (a[i + 1].first - a[i].first);
                i++;
            }
        }
        else
        {
            fuel -= (a[j].first - a[i].first);
            if (fuel < 0) 
            {
                tot += (-fuel) * a[i].second; //buy
                fuel = 0;
            }
            i = j;
        }
    }
    cout << tot << endl;
    return 0;
}