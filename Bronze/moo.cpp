#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    freopen("moo.in", "r", stdin);
    freopen("moo.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    if (n == 2) {cout << 'o' << endl; return 0;}
    else if (n == 1) {cout << 'm' << endl; return 0;}
    LL s[10000];
    s[0] = 3;
    LL l = 1, r = -1, t;
    for (int i = 1; r < 0; i++)
    {
        s[i] = 2 * s[i - 1] + i + 3;
        if (n >= s[i - 1] && n <= s[i]) 
        {
            r = s[i];
            t = i + 3;
        }
    }
    char ans = '.';
    while (l <= r && ans == '.')
    {
        LL l_r = (l + r - t - 1) / 2;
        LL r_l = (l + r + t + 1) / 2;
        //cout << l << " " << l_r << " " << r_l << " " << r << endl;
        if (n > l_r && n < r_l) 
        {
            if (n == l_r + 1) ans = 'm';
            else ans = 'o';
        }
        else if (n == l || n == r_l)
        {
            ans = 'm';
        }
        else if (l_r - l == 2) 
        {
            ans = 'o';
        }
        if (n >= l && n <= l_r) r = l_r;
        else l = r_l;
        t--;
    }
    cout << ans << endl;
    return 0;
}