#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
struct cow
{
    int x, y;
};
vector<cow> a;
int n, ans = 2E9;
int here[500005], index_1[500005], index_2[500005];
bool cmp1(int a1, int b1)
{
    if (a[a1].x == a[b1].x) return a[a1].y < a[b1].y;
    return a[a1].x < a[b1].x;
}
bool cmp2(int a1, int b1)
{
    if (a[a1].y == a[b1].y) return a[a1].x < a[b1].x;
    return a[a1].y < a[b1].y;
}
void solve(int cntlt, int cntrt, int cntdown)
{
    int cntup = 3 - cntlt - cntrt - cntdown;
    memset(here, 0, sizeof(here));
    for (int i = 0; i < cntlt; ++i) here[index_1[i]]++;
    for (int i = 0; i < cntrt; ++i) {here[index_1[n - 1 - i]]++;}
    int it = 0;
    for (int i = 0; i < n; ++i)
    {
        //cout << here[i] << " ";
        if (here[i] == 0)
            index_2[it++] = i;
    }
    sort(index_2, index_2 + it, cmp2);
    //for (int i = 0; i < n; ++i) cout << index_2[i] << " " << a[i].x << " " << a[i].y << endl;
    for (int i = 0; i < cntdown; ++i) {here[index_2[i]]++;}
    for (int i = 0; i < cntup; ++i) here[index_2[n - 1 - i]]++;
    int xmax = 0, ymax = 0, xmin = 2E9, ymin = 2E9;
    for (int i = 0; i < n; ++i)
    {
        if (here[i] == 0) 
        {
            xmax = max(xmax, a[i].x);
            xmin = min(xmin, a[i].x);
            ymax = max(ymax, a[i].y);
            ymin = min(ymin, a[i].y);
        }
    }
    ans = min(ans, (ymax - ymin) * (xmax - xmin));
}
int main()
{
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int input1, input2;
    cin >> n;
    for (int i = 0; i < n; ++i) 
    {
        cin >> input1 >> input2;
        a.pb({input1, input2});
        index_1[i] = i;
    }
    sort(index_1, index_1 + n, cmp1); //sort by x increasing
    //for (int i = 0; i < n; i++) cout << index_1[i] << " ";
    
    for (int i = 0; i <= 3; ++i)
        for (int j = 0; i + j <= 3; ++j)
            for (int k = 0; i + j + k <= 3; ++k)
                solve(i, j, k);
    cout << ans << endl;
    
    return 0;
}