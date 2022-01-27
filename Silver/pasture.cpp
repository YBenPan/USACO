#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
vi x, y;
vector<pi> points; 
LL pre[2505][2505] = {0}; 
bool cmp(pi a, pi b)
{
    return a.second < b.second; 
}
int calc(int x1, int y1, int x2, int y2)
{
    return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1]; 
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, in1, in2;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> in1 >> in2; 
        x.pb(in1); y.pb(in2); 
        points.pb({in1, in2}); 
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i = 0; i < n; ++i)
    {
        points[i].first = lower_bound(x.begin(), x.end(), points[i].first) - x.begin() + 1; 
        points[i].second = lower_bound(y.begin(), y.end(), points[i].second) - y.begin() + 1;
        pre[points[i].first][points[i].second] = 1; 
        //cout << i.first << " " << i.second << " " << x1 << " " << y1 << endl;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]; 
        }
    }
    /*
    for (int i = n; i >= 1; --i)
    {
        for (int j = 1; j <= n; ++j) cout << pre[i][j] << " ";
        cout << endl;
    }*/
    sort(points.begin(), points.end(), cmp); 
    LL cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i ; j < n; ++j)
        {
            int x1 = min(points[i].first, points[j].first); 
            int x2 = max(points[i].first, points[j].first); 
            //cout << i << " " << j << " " << calc(1, points[i].second, x1, points[j].second) << " " << calc(x2, points[i].second, n, points[j].second) << endl;
            cnt += calc(1, points[i].second, x1, points[j].second) * calc(x2, points[i].second, n, points[j].second);
        }
    }
    cout << cnt + 1 << endl;
    return 0;
}