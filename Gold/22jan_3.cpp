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
int a[100005], ans[100005] = {0};
main()
{
    //freopen("3.in", "r", stdin);
    //freopen("3.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int k = 0;
    ans[1] = 1;
    for (int i = 1; i <= n; i++) k = max(k, a[i] - i);
    cout << k << endl;
    cout << ans[1] << endl;
    for (int i = 2; i <= n; i++)
    {
        if (ans[i] == 0) ans[i] = ans[i - 1] + 1;
        if (a[i] != i) ans[a[i]] = ans[i] + k;
        ans[a[i] + 1] = ans[i] + k + 1;
        cout << ans[i] << endl;
    }
    return 0;
}