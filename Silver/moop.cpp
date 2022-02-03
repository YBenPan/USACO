#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int minl[100005], maxr[100005]; 
pi a[100005]; 
int main()
{
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) 
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n); 
    minl[0] = 1E9; 
    for (int i = 1; i <= n; ++i)
    {
        minl[i] = min(minl[i - 1], a[i].second);
        //cout << minl[i] << " ";
    }
    maxr[n + 1] = -1E9;
    for (int i = n; i >= 1; --i)
    {
        maxr[i] = max(maxr[i + 1], a[i].second); 
        //cout << maxr[i] << endl;
    }
    int ans = 1;
    for (int i = 1; i <= n - 1; ++i)
    {
        if (minl[i] > maxr[i + 1])
            ans++;
    }
    cout << ans << endl;
    return 0;
}