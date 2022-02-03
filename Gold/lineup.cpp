#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int a[100005]; 
multiset<int> m; 
int ans = 0, l = 0, r = -1, breed = 0;
void add()
{
    r++; 
    if (m.find(a[r]) == m.end()) // new breed
        breed++; 
    m.insert(a[r]); 
}
void remove()
{
    auto loc = m.find(a[l]); 
    m.erase(loc); 
    if (m.count(a[l]) == 0) 
        breed--; 
    l++; 
}
main()
{
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k; 
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    for (int i = 0; i < n; ++i)
    {
        add();
        while (breed > (k + 1))
            remove(); 
        ans = max(ans, (int)m.count(a[r]));
    }
    cout << ans << endl;
    return 0;
}