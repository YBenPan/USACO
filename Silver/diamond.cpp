#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    int cnt[50005] = {0};
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0, j = 0;
    for (int i = 0; i < n; ++i)
    {
        while (j < n && a[j] - a[i] <= k)
            j++;
        cnt[i] = j - i;
    }
    int maxx[50005] = {0};
    for (int i = n - 1; i >= 0; i--)
    {
        maxx[i] = max(maxx[i + 1], cnt[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, cnt[i] + maxx[i + cnt[i]]);
    }
    cout << ans << endl;
    return 0;
}