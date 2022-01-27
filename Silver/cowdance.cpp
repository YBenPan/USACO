#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
vi cow;
int n, t;
bool check(int mid)
{
    priority_queue<int> q;
    for (int i = 0; i < mid; ++i) q.push(-cow[i]);
    int time = 0, i = mid;
    while (!q.empty())
    {
        time = q.top();
        q.pop();
        if (i < n)
        {
            q.push(-cow[i++] + time);
        }
    }
    //cout << mid << " " << time << endl;
    return -time <= t;
}
int main()
{
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int input;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {cin >> input; cow.pb(input);}
    int l = 1, r = n, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}