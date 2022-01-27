#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int a[100005], start[100005], last[100005]; 
stack<int> range; 
int main()
{
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    memset(start, 0x3f3f3f3f, sizeof(start)); 
    memset(last, 0, sizeof(last)); 
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i]; 
        if (a[i] == 0) continue;
        start[a[i]] = min(start[a[i]], i); 
        last[a[i]] = max(last[a[i]], i); 
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0) continue;
        if (i == start[a[i]]) // Open range
        {
            range.push(a[i]); 
            if (i == last[a[i]])
            {
                cnt = max(cnt, (int)range.size()); 
                range.pop(); 
                continue;
            }
        }
        else if (i == last[a[i]]) // Close range
        {
            int t = range.top();
            if (t != a[i])
            {
                cout << -1 << endl;
                return 0;
            }
            range.pop(); 
        }   
        cnt = max(cnt, (int)range.size()); 
        //cout << i << " " << cnt << endl;
    }
    cout << cnt << endl;
    return 0;
}