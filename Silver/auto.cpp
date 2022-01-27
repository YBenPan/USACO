#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
vector<pair<string, int>> v; 
bool check_prefix(string str, string pre)
{
    if (str.size() < pre.size()) return false; 
    auto flag = mismatch(pre.begin(), pre.end(), str.begin()); 
    if (flag.first == pre.end()) return true; 
    return false;
}
main()
{
    freopen("auto.in", "r", stdin);
    freopen("auto.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int w, n;
    cin >> w >> n;
    string str;
    for (int i = 0; i < w; ++i)
    {
        cin >> str;
        v.pb({str, i + 1}); 
    }
    sort(v.begin(), v.end());
    int k;
    for (int i = 0; i < n; ++i)
    {
        cin >> k >> str; 
        int l = 0, r = v.size() - 1, mid; 
        // smallest that works
        while (l != r)
        {
            mid = (l + r) / 2;
            if (v[mid].first >= str)
                r = mid;
            else
                l = mid + 1; 
        }
        //cout << l << " " << v[l].first << endl;
        int cur = l + k - 1; 
        if (cur >= w || !check_prefix(v[cur].first, str))
            cout << -1 << endl;
        else
            cout << v[cur].second << endl;        
    }
    return 0;
}