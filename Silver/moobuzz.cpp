#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL n;
int main()
{
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    LL i = 1, j = 1E16, ans = -1;
    while (i <= j)
    {
        LL mid = (i + j) / 2;
        LL cnt = mid - (mid / 3) - (mid / 5) + (mid / 15);
        if (cnt >= n)
        {
            j = mid - 1;
            ans = mid;
        }
        else
        {
            i = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}