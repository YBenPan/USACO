#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
bool visited[1000005] = {0};
main()
{
    freopen("invite.in", "r", stdin);
    freopen("invite.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, g, s, in;
    cin >> n >> g;
    vector<set<int>> group(g);
    vector<vi> rev(n + 5);
    for (int i = 0; i < g; i++)
    {
        cin >> s;
        for (int j = 0; j < s; j++)
        {
            cin >> in;
            group[i].insert(in);
            rev[in].pb(i);
        }
    }
    queue<int> q;
    q.push(1);
    int ans = 0;
    while (!q.empty())
    {
        int t = q.front(); q.pop();
        if (visited[t]) continue;
        visited[t] = 1;
        ans++;
        for (auto i : rev[t])
        {
            group[i].erase(t);
            if (group[i].size() == 1)
            {
                int x = *group[i].begin();
                if (!visited[x])
                    q.push(x);
            }
        }
    }
    cout << ans << endl;
    return 0;
}