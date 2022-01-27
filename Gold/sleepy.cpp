#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int n;
int a[100005], ft[100005] = {0};
void update(int x, int v) {while (x <= n) ft[x] += v, x += (x & -x);}
int query(int x) {return x > 0 ? ft[x] + query(x - (x & -x)) : 0;}
main()
{
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    update(a[n], 1);
    int tot = n - 1;
    for (int i = n - 1; i >= 1 && a[i] < a[i + 1]; i--)
    {
        update(a[i], 1);
        tot--;
    }
    cout << tot << endl;
    for (int i = 1; i <= tot; i++)
    {
        update(a[i], 1);
        int p = query(n) - query(a[i]);
        cout << n - 1 - p;
        if (i != tot) cout << " ";
    }
    cout << endl;
    return 0;
}