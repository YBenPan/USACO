#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
pi cow[10005]; 
bool cmp(pi a, pi b)
{
    return a.second < b.second; 
}
main()
{
    freopen("msched.in", "r", stdin);
    freopen("msched.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> cow[i].first >> cow[i].second; 
    sort(cow, cow + n, cmp); 
    // for (int i = 0; i < n; ++i) cout << cow[i].first << " " << cow[i].second << endl;
    int j = n - 1, tot = 0;
    multiset<int> m; 
    for (int i = 10000; i >= 1; --i) 
    {
        while (j >= 0 && cow[j].second == i) 
        {
            m.insert(cow[j--].first); 
        }
        if (!m.empty())
        {
            int t = *m.rbegin(); 
            auto loc = m.find(t); 
            m.erase(loc); 
            tot += t; 
        }
        //cout << tot << endl;
    }
    cout << tot << endl;
    return 0;
}