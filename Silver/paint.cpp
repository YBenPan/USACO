#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
map<int, int> m;
main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    int delta, cur = 0; char type;
    for (int i = 0; i < n; ++i)
    {
        cin >> delta >> type; 
        int curcpy = cur; 
        if (type == 'R') cur += delta;
        else cur -= delta;
        int start = min(curcpy, cur), end = max(curcpy, cur); 
        m[start]++;
        m[end]--; 
    }
    int tot = 0, sum = 0, last;
    bool first = true; 
    for (auto i : m)
    {
        int loc = i.first, change = i.second; 
        if (!first && tot >= k)
            sum += (loc - last); 
        else if (first)
            first = false; 
        tot += change; 
        last = loc; 
    }
    cout << sum << endl;
    return 0;
}