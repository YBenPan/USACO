#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int a[100005];
    bool ex[100005] = {0};
    for (int i = 0; i < n; ++i) 
    {
        cin >> a[i]; 
        ex[a[i]] = true;
    }
    sort(a, a + n);
    vi b;
    for (int i = 1; i <= 2 * n; ++i)
    {
        if (!ex[i]) b.pb(i); 
    }
    //for (auto i : b) cout << i << " ";
    int j = 0, cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        while (j < n && b[j] < a[i]) j++; 
        if (j < n) {cnt++; j++;}
    }
    cout << cnt << endl;
    return 0;
}