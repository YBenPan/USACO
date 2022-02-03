#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<pi> a;
    int x;
    for (int i = 0; i < n; ++i) 
    {
        cin >> x;
        a.pb({x, i});
    }
    sort(a.begin(), a.end());
    int maxx = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i].second > i)
        {
            maxx = max(maxx, a[i].second - i);
        }
    }
    cout << maxx + 1 << endl;
    return 0;
}