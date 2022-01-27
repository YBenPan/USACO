#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
struct flavor {
    int f[5];
    int num; 
    bool operator<(const flavor &a) const
    {
        for (int i = 0; i < 5; ++i)
            if (f[i] != a.f[i]) return f[i] < a.f[i]; 
        return false;
    }
};
map<flavor, int> m; 
int main()
{
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    LL n;
    cin >> n;
    int in[5], c[5]; 
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 5; ++j) cin >> in[j]; 
        for (int j = 1; j <= 31; ++j)
        {
            c[4] = j % 2; 
            c[3] = j / 2 % 2; 
            c[2] = j / 4 % 2;
            c[1] = j / 8 % 2; 
            c[0] = j / 16 % 2; 
            flavor new_flavor = {{0, 0, 0, 0, 0}, 0};
            for (int k = 0; k < 5; ++k)
                if (c[k] > 0) 
                {
                    new_flavor.f[k] = in[k];
                    new_flavor.num++; 
                }
            sort(new_flavor.f, new_flavor.f + 5); 
            m[new_flavor]++; 
        }
    }    
    LL sum = 0; 
    for (auto it : m)
    {
        LL cnt = it.second; 
        int num = it.first.num; 
        if (num % 2)
            sum += (cnt * (cnt - 1)) / 2; 
        else sum -= (cnt * (cnt - 1)) / 2;
    }
    sum = n * (n - 1) / 2 - sum; 
    cout << sum << endl;
    return 0;
}