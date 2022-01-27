#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
vector<pi> p; 
bool cmp(pi a, pi b)
{
    if (a.second == b.second) return a.first < b.first; 
    return a.second < b.second; 
}
int main()
{
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int in1, in2, n;
    cin >> n;
    map<int, set<int>> g; 
    for (int i = 0; i < n; ++i)
    {
        cin >> in1 >> in2;
        p.pb({in1, in2});
        g[in1].insert(in2); 
    }
    sort(p.begin(), p.end(), cmp); 
    int down = 0, up; 
    int minn = 1E9;
    while (down < n)
    {
        while (down < n - 1 && p[down + 1].second == p[down].second) down++;
        up = n - down; 
        int ul = 0, ur = up - 1, dl = 0, dr = down + 1;
        int y = p[down].second + 1; 
        for (auto i : g)
        {
            auto it = (i.second).lower_bound(y); 
            int s = (i.second).size();
            int b = distance(i.second.begin(), it);
            dl += b; 
            ul += (s - b); 
            dr -= b; 
            ur -= (s - b); 
            int maxx = max(dl, max(ul, max(dr, ur)));
            minn = min(minn, maxx); 
        }
        down++; 
    }
    cout << minn << endl;
    return 0;
}