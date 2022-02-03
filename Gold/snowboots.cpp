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
int a[100005];
vector<pi> tile;
int pre[100005], nxt[100005], ans[100005];
bool cmp(pi a, pi b)
{
    return a.fi > b.fi;
}
struct boot
{
    int depth, step, ind;
};
boot boots[100005];
bool cmp1(boot a, boot b)
{
    return a.depth > b.depth;
}
main()
{
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, b;
    cin >> n >> b;
    int max_step = 1;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        tile.pb({a[i], i});
    }
    for (int i = 0; i < n; i++)
    {
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }
    sort(tile.begin(), tile.end(), cmp);
    for (int i = 0; i < b; i++)
    {
        cin >> boots[i].depth >> boots[i].step;
        boots[i].ind = i;
    }
    sort(boots, boots + b, cmp1);
    int j = 0;
    for (int i = 0; i < b; i++)
    {
        while (j < n && tile[j].fi > boots[i].depth)
        {
            int ind = tile[j].se;
            pre[nxt[ind]] = pre[ind];
            nxt[pre[ind]] = nxt[ind];
            max_step = max(max_step, nxt[ind] - pre[ind]);
            j++;
        }
        //cout << i << " " << max_step << endl;
        if (boots[i].step >= max_step) ans[boots[i].ind] = 1;
        else ans[boots[i].ind] = 0;
    }
    for (int i = 0; i < b; i++) cout << ans[i] << endl;
    return 0;
}