#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m;
vi g[100005]; 
int parent[100005];
char milk[100005];
bool visited[100005];
int cc[100005], cc_index = 0; 
void dfs(int s, int last)
{
    //out << last << " " << s << endl;
    if (milk[s] == milk[last]) cc[s] = cc[last]; 
    else 
    {
        //cout << "NEW " << s << endl;
        cc_index++;
        cc[s] = cc_index; 
    }
    for (auto i : g[s])
    {
        if (i != last) dfs(i, s); 
    }
}
int main()
{
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> milk[i]; 
    int in1, in2; char want;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> in1 >> in2;
        g[in1].pb(in2);
        g[in2].pb(in1);
    }
    dfs(1, 1);
    for (int i = 0; i < m; ++i)
    {
        cin >> in1 >> in2 >> want;
        if (cc[in1] == cc[in2] && milk[in1] != want) cout << 0;
        else cout << 1;
    }
    return 0;
}