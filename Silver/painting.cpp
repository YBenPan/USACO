#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
struct field
{
    int c[4]; 
    bool operator<(const field &a) const
    {
        if (c[0] == a.c[0]) return c[2] < a.c[2];
        else return c[0] < a.c[0]; 
    }
};
struct order 
{
    int x, type, index; 
    bool operator<(const order &a) const
    {
        return x < a.x; 
    }
    // type = 0 for open, 1 for close
};
vector<field> g;
vector<order> poi; 
map<int, int> m; 
int cnt = 0;
int main()
{
    freopen("painting.in", "r", stdin);
    freopen("painting.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int in1, in2, in3, in4;
    for (int i = 0; i < n; ++i)
    {
        cin >> in1 >> in2 >> in3 >> in4; 
        g.pb({in1, in2, in3, in4});
    }
    sort(g.begin(), g.end()); 
    for (int i = 0; i < n; ++i)
    {
        poi.pb({g[i].c[0], 0, i}); 
        poi.pb({g[i].c[2], 1, i}); 
    }
    sort(poi.begin(), poi.end()); 
    for (int i = 0; i < poi.size(); ++i)
    {
        order req = poi[i]; 
        field cur = g[req.index]; 
        if (req.type == 1)
        {
            auto it = m.find(cur.c[3]); 
            if (it != m.end()) m.erase(it); 
            continue;
        }
        auto it = m.upper_bound(cur.c[3]);
        if (it == m.end()) // No open fields above current field
        {
            m[cur.c[3]] = req.index; 
            cnt++; 
        }
        else 
        {
            int index = it->second;
            if (g[index].c[1] > cur.c[1])
            {
                m[cur.c[3]] = req.index;
                cnt++; 
            }
        }
    }
    cout << cnt << endl;
    return 0;
}