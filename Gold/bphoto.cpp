#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int a[100005], ap[100005], ft[100005], l[100005], r[100005];
int n;
map<int, int> in;
void update(int x, int v) {while (x <= n) ft[x] += v, x += (x & -x);}
int query(int x) {return x > 0 ? ft[x] + query(x - (x & -x)) : 0;}
main()
{
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> ap[i];
        a[i] = ap[i];
    }
    sort(ap + 1, ap + n + 1, greater<int>());
    for (int i = 1; i <= n; i++)
        in[ap[i]] = i;
    memset(ft, 0, sizeof(ft));
    for (int i = 1; i <= n; i++)
    {
        update(in[a[i]], 1);
        l[i] = query(in[a[i]] - 1);
    }
    memset(ft, 0, sizeof(ft));
    for (int i = n; i >= 1; i--)
    {
        update(in[a[i]], 1);
        r[i] = query(in[a[i]] - 1);
    }
    int tot = 0;
    for (int i = 1; i <= n; i++)
        if (l[i] > 2 * r[i] || r[i] > 2 * l[i]) tot++; 
    cout << tot << endl;
    return 0;
}