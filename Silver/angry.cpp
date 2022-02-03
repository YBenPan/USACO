#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int a[50005];
int n, k;
bool check(int mid)
{
    int l = 0, r = 0, cnt = 0;
    while (l < n)
    {
        while (a[r + 1] - a[l] <= 2 * mid && r < n - 1) r++;
        cnt++;
        l = r + 1;
    }
    return cnt <= k;
}
int main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int i = 0, j = 1E9, ans = -1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (check(mid)) 
        {
            j = mid - 1;
            ans = mid;
        }
        else i = mid + 1;
    }
    cout << ans << endl;
    return 0;
}