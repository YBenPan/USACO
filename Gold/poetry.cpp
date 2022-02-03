#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int s[5005], c[5005], char_cnt[26]; 
LL dp[5005];
vi rhy[5005], rhy_sum; 
long long binpow(LL a, LL b)
{
    a %= MOD;
    LL res = 1;
    while (b > 0)
    {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int main()
{
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) 
    {
        cin >> s[i] >> c[i];
        rhy[c[i]].pb(i);   
    }
    dp[0] = 1;
    for (int i = 0; i <= k; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i >= s[j])
            {
                dp[i] += dp[i - s[j]];
                dp[i] %= MOD; 
            }
        }
    }
    for (int i = 1; i <= n; ++i) //iterate through rhyme classes
    {
        LL sum = 0;
        for (auto j : rhy[i])
        {
            sum += dp[k - s[j]]; 
            sum %= MOD;
        }
        if (sum != 0) rhy_sum.pb(sum); 
    }
    char ch;
    for (int i = 0; i < m; ++i) 
    {
        cin >> ch;
        char_cnt[ch - 'A']++;
    }
    LL ans = 1;
    for (int i = 0; i < 26; ++i)
    {
        if (char_cnt[i] == 0) continue;
        LL sum = 0;
        for (auto j : rhy_sum) 
        {
            sum += binpow(j, char_cnt[i]);
            sum %= MOD;  
        }
        ans *= sum; 
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}