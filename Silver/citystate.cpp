#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
map<string, int> m; 
int main()
{
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string str1, str2, str3, str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str1 >> str2;
        //cout << str1 << " " << str2 << endl;
        str3 = str1.substr(0, 2); 
        str = str3 + str2; 
        //cout << str << endl;
        m[str]++; 
    }
    //for (auto i : m) cout << i.first << " " << i.second << endl;
    int cnt = 0;
    for (auto i : m)
    {
        str = i.first;
        str1 = str.substr(0, 2); 
        str2 = str.substr(2, 2); 
        str3 = str2 + str1; 
        //cout << str3 << endl;   
        if (str != str3) cnt += m[str3] * i.second; 
    }
    cout << cnt / 2 << endl;
    return 0;
}