#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
vector<pair<LL, LL> > cow; 
multiset<LL> chick; 
bool cmp(pair<LL, LL> a, pair<LL, LL> b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second; 
}
int main()
{
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    LL c, n;
    cin >> c >> n;
    LL in1, in2;
    for (int i = 0; i < c; ++i) 
    {
        cin >> in1; chick.insert(in1);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> in1 >> in2; 
        cow.pb({in1, in2});
    }
    //sort(chick.begin(), chick.end());
    sort(cow.begin(), cow.end(), cmp);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        auto it = chick.lower_bound(cow[i].first); 
        if (it != chick.end() && *it <= cow[i].second) 
        {
            chick.erase(it); 
            cnt++; 
        }       
    }
    cout << cnt << endl;
    return 0;
}