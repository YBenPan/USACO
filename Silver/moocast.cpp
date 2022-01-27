#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int N;
bool connected[205][205] = {false};
bool visited[205];
int dfs(int s)
{
    visited[s] = true;
    int cnt = 1;
    for (int i = 0; i < N; ++i)
        if (!visited[i] && connected[s][i])
            cnt += dfs(i);
    return cnt;
}
int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    int p[205], x[205], y[205];
    for (int i = 0; i < N; ++i)
    {
        cin >> x[i] >> y[i] >> p[i];
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            int dist = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
            int sq = p[i] * p[i];
            //cout << i << " " << j << " " << dist << endl;
            if (dist <= sq)
            {
                //cout << i << " " << j << endl;
                connected[i][j] = true;
            }
        }
    int maxx = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 205; ++j) visited[j] = false;
        maxx = max(maxx, dfs(i));            
    }
    cout << maxx << endl;
    return 0;
}