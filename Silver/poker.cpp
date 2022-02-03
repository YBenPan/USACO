#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int a[100005]; 
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[0] = 0;
    LL sum = 0;
    for (int i = 1; i <= n; ++i) 
        if (a[i] > a[i - 1]) sum += (a[i] - a[i - 1]); 
    cout << sum << endl;
    return 0;
}