#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int snow[255], depth[255], dist[255];
int ans = 1E9, n, b;
bool visited[255][255] = {0};
void traverse(int node, int boots)
{
    if (visited[node][boots]) return;
    visited[node][boots] = true;
    if (node == n - 1) 
    {
        ans = min(ans, boots);
        return;
    }
    //traverse to next nodes
    for (int i = node + 1; i < n && i <= node + dist[boots]; ++i)
    {
        if (snow[i] <= depth[boots]) traverse(i, boots);
    }
    //change boots
    for (int i = boots + 1; i < b; ++i)
    {
        if (depth[i] >= snow[node]) traverse(node, i);
    }
}
int main()
{
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> b;
    for (int i = 0; i < n; ++i) cin >> snow[i];
    for (int i = 0; i < b; ++i) cin >> depth[i] >> dist[i];
    traverse(0, 0);
    cout << ans << endl;
    return 0;
}