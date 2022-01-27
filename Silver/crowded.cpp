#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
pi cow[50005]; 
multiset<int> m1, m2; 
main()
{
    freopen("crowded.in", "r", stdin);
    freopen("crowded.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) cin >> cow[i].first >> cow[i].second; 
    sort(cow, cow + n); 
    int l = 0, r = 0, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        while (cow[r].first - cow[i].first <= d && r <= n - 1)
        {
            m2.insert(cow[r].second); 
            r++; 
        }
        while (cow[i].first - cow[l].first > d && l < i)
        {
            auto loc = m1.find(cow[l].second);
            m1.erase(loc); 
            l++; 
        }
        int curl = -1; 
        if (!m1.empty()) curl = *m1.rbegin(); 
        int curr = -1;
        if (!m2.empty()) curr = *m2.rbegin(); 
        if (curl >= 2 * cow[i].second && curr >= 2 * cow[i].second) ans++; 

        m1.insert(cow[i].second);
        auto loc = m2.find(cow[i].second); 
        if (loc != m2.end()) m2.erase(loc);
    }
    cout << ans << endl;
    return 0;
}