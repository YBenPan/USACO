#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
vector<pi> cow;
multiset<int> l, r;
bool cmp(pi a, pi b)
{
    return a.second < b.second; 
}
int main()
{
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int in1, in2;
    for (int i = 0; i < n; ++i)
    {
        cin >> in1 >> in2;
        cow.pb({in1, in2});
        r.insert(in2); 
    }
    sort(cow.begin(), cow.end()); 
    int i = 0;
    LL minn = 1E16, area = 0;
    while (i < n)
    {
        l.insert(cow[i].second); 
        auto it = r.find(cow[i].second); 
        r.erase(it);
        while (i + 1 < n && cow[i + 1].first == cow[i].first)
        {
            l.insert(cow[i + 1].second); 
            auto it = r.find(cow[i + 1].second); 
            r.erase(it); 
            i++;
        }
        
        int ul = *l.rbegin(); 
        int ll = *l.begin(); 
        LL area1 = (LL)(cow[i].first - cow[0].first) * (LL)(ul - ll); 
        LL area2 = 0;
        if (i != n - 1)
        {
            int ur = *r.rbegin(); 
            int lr = *r.begin(); 
            area2 = (LL)(cow[n - 1].first - cow[i + 1].first) * (LL)(ur - lr); 
        }
        area = area1 + area2; 
        minn = min(minn, area); 
        i++;
    }
    l.clear(); r.clear(); 
    sort(cow.begin(), cow.end(), cmp); 
    for (auto i : cow)
    {
        r.insert(i.first);
    }
    i = 0;
    while (i < n)
    {
        l.insert(cow[i].first); 
        auto it = r.find(cow[i].first); 
        r.erase(it);
        while (i + 1 < n && cow[i + 1].second == cow[i].second)
        {
            l.insert(cow[i + 1].first); 
            auto it = r.find(cow[i + 1].first); 
            r.erase(it); 
            i++;
        }
        
        int ul = *l.rbegin(); 
        int ll = *l.begin(); 
        LL area1 = (LL)(cow[i].second - cow[0].second) * (LL)(ul - ll); 
        LL area2 = 0;
        if (i != n - 1)
        {
            int ur = *r.rbegin(); 
            int lr = *r.begin(); 
            area2 = (LL)(cow[n - 1].second - cow[i + 1].second) * (LL)(ur - lr); 
        }
        area = area1 + area2; 
        minn = min(minn, area); 
        i++;
    }
    cout << area - minn << endl;
    return 0;
}