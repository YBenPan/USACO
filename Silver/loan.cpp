#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL n, k, m;
bool check(LL x)
{
    LL debtLeft = n, daysLeft = k; 
    while (debtLeft > 0 && daysLeft > 0)
    {
       LL y = debtLeft / x; 
       if (y < m)
       {
           LL remaining = (debtLeft + m - 1) / m;
           return remaining <= daysLeft;
       }
       LL a = (debtLeft - x * y) / y + 1;
       if (a > daysLeft) a = daysLeft;
       debtLeft -= (a * y);
       daysLeft -= a;
    }
    return debtLeft <= 0;
}
int main()
{
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k >> m;
    LL l = 1, r = 1E12, ans;
    while (l <= r)
    {
        LL mid = (l + r) / 2;
        if (check(mid)) 
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}