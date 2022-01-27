#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int n;
int dp[105][105];
int check(string a, string b)
{
    if (a == b) return 0;
    if (a.size() < b.size()) swap(a, b);
    int pre = 1, suf = 1;
    for (int i = 0; i < b.size() && pre; i++)
        if (a[i] != b[i]) pre = 0;
    for (int i = 0; i < b.size() && suf; i++)
        if (a[a.size() - 1 - i] != b[b.size() - 1 - i]) suf = 0;
    return (pre + suf);
}
main()
{
    freopen("scode.in", "r", stdin);
    freopen("scode.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
    cin >> str;
    n = str.size();
    for (int len = 1; len <= n; len++)
        for (int st = 1; st <= n - len + 1; st++)
        {
            int end = st + len - 1;
            dp[st][end] = 1;
            for (int i = st; i <= end - 1; i++)
            {
                string a = "", b = "";
                for (int j = st; j <= i; j++) a += str[j - 1];
                for (int j = i + 1; j <= end; j++) b += str[j - 1];
                int res = check(a, b);
                if (a.size() > b.size()) 
                    dp[st][end] = (dp[st][end] + res * dp[st][i]) % 2014;
                else 
                    dp[st][end] = (dp[st][end] + res * dp[i + 1][end]) % 2014;
            }
        }
    if (dp[1][n] == 0) cout << 2013 << endl;
    else cout << dp[1][n] - 1 << endl;
    return 0;
}