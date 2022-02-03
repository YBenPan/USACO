#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    LL t, a, b;
    cin >> t >> a >> b;
    bool flag = false;
    if (a + b > t) flag = true; 
    double j = 1; 
    LL maxx = 0;
    for (double i = 0; j > 0 && i * a <= t; i += 0.5)
    {
        LL x = floor(a * i); 
        LL y = t - x; 
        j = (double)y / b; 
        if (j - floor(j) < 0.5) j = floor(j); 
        else if (i - floor(i) != 0.5 || !flag) j = floor(j) + 0.5; 
        else j = floor(j); 
        LL res = floor(i * a) + floor(j * b); 
        maxx = max(maxx, res); 
        //cout << i << " " << j << " " << res << endl;
    }
    j = 1; 
    for (double i = 0; j > 0 && i * b <= t; i += 0.5)
    {
        LL x = floor(b * i); 
        LL y = t - x; 
        j = (double)y / a; 
        if (j - floor(j) < 0.5) j = floor(j); 
        else if (i - floor(i) != 0.5 || !flag) j = floor(j) + 0.5; 
        else j = floor(j); 
        LL res = floor(i * b) + floor(j * a); 
        maxx = max(maxx, res); 
        //cout << i << " " << j << " " << res << endl;
    }
    cout << maxx << endl;
    return 0;
}