#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
struct cow
{
    int w, x, d;
}a[50005];
bool cmp(cow a, cow b)
{
    return a.x < b.x;
}
vector<cow> leftt, rightt;
vector<pi> pairs;
int main()
{
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, l, sum_all = 0;
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].w >> a[i].x >> a[i].d;
        sum_all += a[i].w;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i)
    {
        if (a[i].d == -1) leftt.pb(a[i]);
        else rightt.pb(a[i]);
    }
    for (int i = 0; i < leftt.size(); ++i)
    {
        pairs.pb({leftt[i].x, a[i].w});
    }
    for (int i = 0; i < rightt.size(); ++i)
    {
        pairs.pb({l - rightt[i].x, a[i + leftt.size()].w});
    }
    sort(pairs.begin(), pairs.end());
    int sum = 0, t;
    for (int i = 0; i < pairs.size(); ++i)
    {
        sum += pairs[i].second;
        if (2 * sum >= sum_all) {t = pairs[i].first; break;}
    }
    //cout << t << endl;
    queue<int> q;
    int tot = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i].d == -1)
        {
            while (q.size() && q.front() + 2 * t < a[i].x) q.pop();
            tot += q.size(); 
        }
        else q.push(a[i].x);
    }
    cout << tot << endl;
    return 0;
}