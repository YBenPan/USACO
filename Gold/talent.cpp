#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int wt[255], t[255];
int dpo[250005], dpn[250005]; 
pi pairmax(pi a, pi b)
{
    if (a.first * b.second > a.second * b.first) 
        return a;
    return b;
} 
main()
{
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dpo, 0x2f2f2f2f, sizeof(dpo)); 
    int n, w;
    cin >> n >> w;
    int lim = 0; 
    for (int i = 1; i <= n; ++i)
    {
        cin >> wt[i] >> t[i];  
        lim += t[i]; 
    }
    pi ans = {0, 0};
    dpo[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= lim; ++j)
        {
            dpn[j] = dpo[j];
            if (j >= t[i]) 
            {
                dpn[j] = min(dpo[j], dpo[j - t[i]] + wt[i]); 
            }
            if (i == n && dpn[j] >= w && dpn[j] <= lim)
            {
                ans = pairmax(ans, {j, dpn[j]}); 
            }
            // cout << i << " " << j << " " << dpn[j] << endl;
        }
        for (int j = 0; j <= lim; ++j) dpo[j] = dpn[j];
    }
    // cout << ans.first << " " << ans.second << endl;
    cout << floor((double)ans.first / (double)ans.second * 1000.0) << endl;
    return 0;
}