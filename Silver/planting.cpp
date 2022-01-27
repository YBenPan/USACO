#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, maxx = 0;
int g[100005];
int main()
{
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int in1, in2;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> in1 >> in2;
        g[in1]++;
        g[in2]++;
    }
    sort(g + 1, g + 1 + n, greater<int>());
    cout << g[1] + 1 << endl;
    return 0;
}