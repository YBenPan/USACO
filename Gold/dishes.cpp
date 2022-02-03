// 8/10 test cases
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
bool visited[100005] = {0};
int a[100005], ind[100005];
main()
{
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ind[a[i]] = i;
    }
    int l = 0, r = n - 1;
    int ans = 1;
    while (l != r)
    {
        int mid = (l + r + 1) / 2;
        int rl = 1E10, rr = a[0];
        for (int i = 0; i <= mid; i++) rl = min(rl, a[i]);
        bool flag = 1;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i <= mid && flag; i++)
        {
            if (visited[a[i]]) continue;
            if (i > 0)
            {
                rl = rr + 1;
                rr = a[i];
            }
            stack<int> st;
            vector<pi> nums;
            vector<int> min_arr;
            for (int j = rl; j <= rr; j++)
                if (ind[j] <= mid)
                {
                    nums.pb({ind[j], j});
                    min_arr.pb(j);
                }
            int minn = 0;
            sort(nums.begin(), nums.end());
            for (int jj = 0; jj < nums.size(); jj++)
            {
                int j = nums[jj].second;
                visited[j] = 1;
                st.push(j);
                while (!st.empty() && st.top() == min_arr[minn])
                {
                    st.pop();
                    minn++;        
                }
            }
            if (st.size() == 0) continue;
            int last = st.top(); 
            st.pop();
            while (!st.empty())
            {
                if (st.top() < last) flag = 0;
                last = st.top();
                st.pop();
            }
        }
        if (!flag)
            r = mid - 1;
        else
        {
            l = mid;
            ans = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}