#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
const int MAXN = 100005; 
int pos[MAXN], s[MAXN]; 
LL endpos[MAXN]; 
int main()
{
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    LL n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i)
    {
        cin >> pos[i] >> s[i]; 
        endpos[i] = (LL)pos[i] + (LL)s[i] * t; 
    }
    int cnt = 0;
    LL cur = LLONG_MAX;
    for (int i = n - 1; i >= 0; --i)
    {
        if (endpos[i] < cur)
        {
            cnt++; 
            cur = endpos[i]; 
        }
    }
    cout << cnt << endl;
    return 0;
}