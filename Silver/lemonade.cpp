#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int a[100005];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n, greater<int>());
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= i) cnt++;
    }
    cout << cnt << endl;
    return 0;
}