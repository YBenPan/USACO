#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int a[200005];
main()
{
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        queue<int> q;
        int cnt = 0;
        for (int j = i; j < i + n; j++)
        {
            while (a[j] > 0)
            {
                q.push(j);
                a[j]--;
            }
            if (a[j] != 0) continue;
            if (q.empty()) // don't have enough cows to fill the 0s
            {
                cnt = -1;
                i = j;
                break;
            }
            int t = q.front();
            cnt += (j - t) * (j - t);
            q.pop();
        }
        if (cnt != -1)
        {
            cout << cnt << endl;
            return 0;
        }
    }
    return 0;
}
