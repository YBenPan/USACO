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
pi a[100005];
int n;
int ft[100005];
void update(int x, int v) {while (x <= n) ft[x] += v, x += (x & -x);}
int query(int x) {return x > 0 ? ft[x] + query(x - (x & -x)):0;}
main()
{
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
        update(i, 1);
    }
    sort(a + 1, a + 1 + n);
    int j = 1, inv = 0;
    for (int i = 0; i < n; i++)
    {
        while (j <= n && a[j].fi < i)
        {
            update(a[j].se, -1);
            inv += query(a[j].se);
            j++;
        }
        cout << inv << endl;
    }
    return 0;
}