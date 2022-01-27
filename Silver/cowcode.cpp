#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    freopen("cowcode.in", "r", stdin); 
    freopen("cowcode.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    unsigned LL n, n1; 
    string str; 
    cin >> str >> n; 
    n1 = n; 
    unsigned LL len = str.size(), rt = len; 
    while (rt < n) rt *= 2; 
    while (n1 > len)
    {
        if (n1 > rt / 2) 
        {
            if (n1 == rt / 2 + 1) n1--; 
            else n1 -= (rt / 2 + 1); 
        }
        rt /= 2; 
    }
    cout << str[n1 - 1] << endl;
    return 0;
}