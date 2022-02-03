#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int x, y, k, m, minn = 1E9;
bool visited[105][105][105] = {false};
void search(int a, int b, int t)
{
    if (a < 0 || a > x) return;
    if (b < 0 || b > y) return;
    if (t > k) return;
    if (visited[a][b][t]) return;
    //cout << a << " " << b << " " << t << endl;
    //system("pause");
    visited[a][b][t] = true;
    minn = min(minn, abs(m - a - b));
    t++;
    search(0, b, t);
    search(a, 0, t);
    search(x, b, t);
    search(a, y, t);
    int pour = min(a, y - b); //pour pail 1 to pail 2
    search(a - pour, b + pour, t);
    pour = min(x - a, b);
    search(a + pour, b - pour, t);
}
int main()
{
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> x >> y >> k >> m;
    search(0, 0, 0);
    cout << minn << endl;
    return 0;
}