#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
pi sq[50005];
main()
{
    freopen("squares.in", "r", stdin);
    freopen("squares.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> sq[i].first >> sq[i].second;
    sort(sq, sq + n);
    set<pi> active;
    active.insert(sq[0]);
    int left = 0, tot = 0, area = 0;
    for (int i = 1; i < n; i++)
    {
        while (left < i && sq[left].first <= sq[i].first - k)
            active.erase(sq[left++]);
        for (auto found = active.lower_bound({sq[i].first - k + 1, sq[i].second - k + 1}); found != active.end(); found++)
        {
            pi target = *found;
            if (target.second > sq[i].second - k && target.second < sq[i].second + k)
            {
                tot++;
                area = (k - sq[i].first + target.first) * (k - abs(sq[i].second - target.second));
                if (tot > 1) 
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
        active.insert(sq[i]);        
    }
    cout << area << endl;
    return 0;
}