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
struct event
{
    int t, y, type;
};
bool cmp(event a, event b)
{
    if (a.t == b.t) return a.type > b.type;
    return a.t < b.t;
}
main()
{
    freopen("stampede.in", "r", stdin);
    freopen("stampede.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int x, y, r;
    vector<event> events;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> r;
        events.pb({(-x - 1) * r, y, 1});
        events.pb({(-x * r), y, -1});
    }
    sort(events.begin(), events.end(), cmp);
    
    for (auto i : events)
    {
        //cout << i.t << " " << i.y << " " << i.type << endl;
    }
    set<int> seen;
    set<int> active;
    int i = 0;
    for (; i < events.size(); )
    {
        int ii = i;
        while (ii < events.size() && events[i].t == events[ii].t)
        {
            if (events[ii].type == 1) active.insert(events[ii].y);
            else active.erase(events[ii].y);
            ii++;
        }
        if (!active.empty())
        {
            int minn = *active.begin();
            seen.insert(minn);
        }
        i = ii;
    }
    cout << seen.size() << endl;
    return 0;
}