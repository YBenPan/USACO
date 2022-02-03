#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, k;
int main()
{
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    vi b(n);
    priority_queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        q.push(b[i]);
    }
    //int left = 2, right = 2;
    int maxx = 0, ans = 0;
    sort(b.begin(), b.end(), greater<int>());
    for (int mid = 1; mid <= 1E4; ++mid)
    {
        priority_queue<int> q1 = q;
        bool flag = true;
        int cnt = 0;
        while (!q1.empty() && cnt < k / 2)
        {
            int val = q1.top();
            if (val < mid) {flag = false; break;}
            q1.pop();
            int add = val / mid;
            if (cnt + add > k / 2)
            {
                q1.push(val - (k / 2 - cnt) * mid);
            }
            else
            {
                q1.push(val % mid);
            }
            cnt += add;
        }
        if (!flag) continue;
        int x = 0, sum = 0;
        while (!q1.empty() && x < k / 2)
        {
            x++;
            int val = q1.top();
            q1.pop();
            int y;
            if (val > mid) 
            {
                sum += mid;
                q1.push(val - mid);
            }
            else 
            {
                sum += val;
            }
        }
        maxx = max(sum, maxx);
        //cout << mid << " " << sum << endl;
    }
    cout << maxx << endl;
    return 0;
}
