#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n;
int g[2005][2005]; 
int a[2005];
bool mstSet[2005];
int key[2005], parent[2005];
LL tot = 0;
void MST(int s)
{
    memset(key, 1E9, sizeof(key));
    key[s] = 0;
    //key[i]: minimum edge weight from MST to vertex i
    parent[s] = s;
    for (int mstCnt = 0; mstCnt < n; ++mstCnt)
    {
        int minn = 1E9 + 5, u;
        /* Find the cheapest vertex to add to MST */
        for (int i = 1; i <= n; ++i)
        {
            if (!mstSet[i] && key[i] < minn)
            {
                minn = key[i]; 
                u = i;
            }
        }
        // add the vertex
        mstSet[u] = true;
        tot += g[parent[u]][u];

        //update neighbors of new vertex and calculate the new key value
        //update the parent of neighbors
        for (int i = 1; i <= n; ++i)
        {
            if (g[u][i] && !mstSet[i] && g[u][i] < key[i])
            {
                parent[i] = u;
                key[i] = g[u][i];
            }
        }
    }
}
int main()
{
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i + 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) continue;
            int val = -(a[i] ^ a[j]);
            g[i][j] = val;
            g[j][i] = val;
        }
    }
    MST(1);
    cout << -tot << endl;
    return 0;
}