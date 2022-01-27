#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
string str; 
int main()
{
    freopen("clumsy.in", "r", stdin);
    freopen("clumsy.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> str;
    int open = 0, close = 0, tot = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(')
            open++; 
        else if (str[i] == ')')
        {
            close++; 
            if (close > open) // Reverse
            {
                tot++; 
                close--;
                open++; 
                str[i] = '('; 
            }
        }
    }
    //cout << str << endl;
    open = 0; close = 0;
    for (int i = str.size() - 1; i >= 0; --i)
    {
        if (str[i] == ')')
            close++; 
        else if (str[i] == '(')
        {
            open++; 
            if (open > close) // Reverse
            {
                tot++; 
                open--;
                close++; 
                str[i] = ')'; 
            }
        }
    }
    //cout << str << endl;
    cout << tot << endl;
    return 0;
}