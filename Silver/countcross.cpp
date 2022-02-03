#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, k, r;
map<int, set<int>> g; 
int cow[105]; 
int cc[10005]; 
bool visited[10005] = {0}; 
int getNode(int x, int y)
{
    return (x - 1) * n + y; 
}
int main()
{
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k >> r;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int cur = getNode(i, j); 
            //cout << cur << " ";
            if (j > 1) g[cur].insert(cur - 1); 
            if (j < n) g[cur].insert(cur + 1); 
            if (i > 1) g[cur].insert(cur - n); 
            if (i < n) g[cur].insert(cur + n); 
        }
    
    int in1, in2, in3, in4;
    for (int i = 0; i < r; ++i)
    {
        cin >> in1 >> in2 >> in3 >> in4;
        int cur1 = getNode(in1, in2);
        int cur2 = getNode(in3, in4);
        auto it = g[cur1].find(cur2); 
        if (it != g[cur1].end()) g[cur1].erase(cur2); 
        it = g[cur2].find(cur1);
        if (it != g[cur2].end()) g[cur2].erase(cur1); 
    }
    for (int i = 0; i < k; ++i)
    {
        cin >> in1 >> in2;
        cow[i] = getNode(in1, in2);
    }
    int cnt = 0, r = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int node = getNode(i, j); 
            if (visited[node]) continue; 
            deque<int> q;
            q.push_back(node);
            cc[node] = ++r; 
            while (!q.empty())
            {
                int t = q.front(); q.pop_front();
                cc[t] = r; 
                for (auto i : g[t]) 
                    if (!visited[i]) 
                    {
                        visited[i] = true; 
                        q.push_back(i); 
                    }
            }
        }
    }
    for (int i = 0; i < k; ++i)
    {
        for (int j = i + 1; j < k; ++j)
        {
            if (cc[cow[i]] != cc[cow[j]]) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}