#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
map<LL, LL> crit;
vector<pi> v;
int main()
{
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    LL a, b, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        v.pb({a, b});
        sum += abs(a - b);
        if (abs(a) < abs(a - b))
        {
            LL lt = b - abs(a - b) + abs(a);
            LL rt = b + abs(a - b) - abs(a);
            crit[lt]--; crit[rt]--;
            crit[b] += 2;
        }
    }
    LL ans = sum, minn = ans, last = -1E9, pos, slope = 0; 
    for (auto i : crit)
    {
        LL pos = i.first, cur = i.second;
        sum += (pos - last) * slope;
        slope += cur; 
        last = pos; 
        minn = min(minn, sum);
    }
    cout << minn << endl;
    return 0;
}