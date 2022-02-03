#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m, c;
int a[100005];
bool check(int mid)
{
    int i = 0, j = 0, cnt = 0, maxx = 0;
    while (i < n && cnt < m)
    {
        while (j < i + c - 1 && j < n) 
        {
            if (a[j + 1] - a[i] <= mid) j++;
            else break;
        }
        cnt++;
        i = j + 1;
    }
    if (i < n && cnt == m) return false;
    return true;
}
int main()
{
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int l = 0, r = 1E9, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}