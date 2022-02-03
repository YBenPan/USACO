#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    n /= 2;
    int a[50005];
    bool av[100005];
    for (int i = 0; i < 100005; i++) av[i] = false;
    for (int i = 0; i < 2 * n; ++i)
    {
        cin >> a[i];
        av[a[i]] = true;
    }
    sort(a, a + n);
    sort(a + n, a + 2 * n, greater<int>());
    vi b;
    for (int i = 1; i <= 4 * n; ++i)
    {
        if (!av[i])
            b.pb(i);
    }
    int j = n, cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        while (j < 2 * n && b[j] < a[i])
            j++;
        if (j >= 2 * n) break;
        j++;
        cnt++;
    }
    j = n - 1;
    for (int i = n; i < 2 * n; ++i)
    {
        while (j >= 0 && b[j] > a[i])
            j--;
        if (j < 0) break;
        j--;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}