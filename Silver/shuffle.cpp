#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int a[100005], indeg[100005];
queue<int> q;
int main()
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        indeg[a[i]]++; 
    }    
    
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (indeg[i] == 0) 
        {
            ans++;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int t = q.front(); q.pop();
        
        indeg[a[t]]--;
        if (indeg[a[t]] == 0)
        {
            //cout << t << endl;
            ans++;
            q.push(a[t]);
        }
    }
    cout << n - ans << endl;
    return 0;
}