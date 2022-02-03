#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int n, ans = 1;
int a[100005], ft[100005] = {0};
pi cow[100005];
void update(int x, int v) {while (x <= n) ft[x] += v, x += (x & -x);}
int query(int x) {return x > 0 ? ft[x] + query(x - (x & -x)) : 0;}
main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        cow[i] = {a[i], i};
    }
    sort(cow + 1, cow + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        update(cow[i].second, 1);
        ans = max(ans, i - query(i));
    }
    cout << ans << endl;
    return 0;
}