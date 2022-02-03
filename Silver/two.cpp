#include <bits/stdc++.h>
using namespace std; 
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; 
    cin >> n >> q; 
    char str[100005];
    bool active[30] = {0}; 
    int pre[100005], suf[100005]; 
    pre[0] = 0; suf[n] = 0; 
    for (int i = 1; i <= n; ++i) cin >> str[i]; 
    //build prefix
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        int cur = str[i] - 'A'; 
        for (int j = cur + 1; j < 26; ++j)
        {
            active[j] = false; 
        }
        if (!active[cur])
        {
            active[cur] = true; 
            cnt++; 
        }
        pre[i] = cnt; 
        //cout << pre[i] << " ";
    }
    //build suffix 
    cnt = 0; 
    memset(active, 0, sizeof(active)); 
    for (int i = n; i >= 1; --i)
    {
        int cur = str[i] - 'A'; 
        for (int j = cur + 1; j < 26; ++j)
        {
            active[j] = false; 
        }
        if (!active[cur])
        {
            active[cur] = true; 
            cnt++; 
        }
        suf[i] = cnt; 
        //cout << suf[i] << " ";
   }
   int in1, in2;
   for (int i = 0; i < q; ++i)
   {
       cin >> in1 >> in2;
       cout << suf[in2 + 1] + pre[in1 - 1] << endl;
   }
}