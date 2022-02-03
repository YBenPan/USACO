#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int n;
int a[100005], ft[100005] = {0}, start[100005] = {0};
void update(int x, int v)
{
    while (x <= 2 * n)
    {
        ft[x] += v;
        x += (x & -x);
    }
}
int query(int x)
{
    return x > 0 ? ft[x] + query(x - (x & -x)) : 0;
}
main()
{
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (start[a[i]] == 0)
        {
            start[a[i]] = i;
            update(i, 1);
        }
        else 
        {
            ans += (query(i - 1) - query(start[a[i]]));
            update(start[a[i]], -1);
        }
    }
    cout << ans << endl;
    return 0;
}