#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int n, b;
int w[20], cnt[1000005], a[105];
main()
{
    freopen("mooomoo.in", "r", stdin);
    freopen("mooomoo.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> b;
    for (int i = 0; i < b; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(w, w + b);
    cnt[0] = 0;
    for (int i = 1; i <= 1E6; i++)
    {
        int minn = 1E10, minn_index = -1;
        cnt[i] = 1E10;
        for (int j = 0; j < b; j++)
            if (i >= w[j] && cnt[i - w[j]] < minn) 
            {
                minn = cnt[i - w[j]];
                minn_index = i - w[j];
            }
        if (minn_index == -1) continue;
        cnt[i] = cnt[minn_index] + 1;
    }
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        int t = a[i];
        if (i > 0 && a[i - 1] > 0) t = a[i] - (a[i - 1] - 1);
        if (cnt[t] < 1E9)
            tot += cnt[t];
        else 
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << tot << endl;
    return 0;
}