#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
bool g[1005][1005];
int main()
{
    freopen("leftout.in", "r", stdin);
    freopen("leftout.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    char input;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> input;
            if (input == 'L') g[j][i] = 0;
            else g[j][i] = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (g[i][1] == 1) 
            for (int j = 1; j <= n; ++j)
                g[i][j] = 1 - g[i][j];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (g[1][i] == 1) 
            for (int j = 1; j <= n; ++j)
                g[j][i] = 1 - g[j][i];
    }
    /*
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j) cout << g[j][i];
        cout << endl;
    }*/
    //check for (1, 1)
    bool flag = true;
    for (int i = 2; i <= n && flag; ++i)
        for (int j = 2; j <= n && flag; ++j)
            if (g[j][i] == 0) flag = false;
    if (flag) {cout << "1 1" << endl; return 0;}

    //check for rows
    int cnt = 0, row = -1, col = -1, cnt2 = 0, x = -1, y = -1;
    for (int i = 2; i <= n; ++i)
    {
        bool flag1 = true, flag2 = true;
        for (int j = 2; j <= n; ++j)
        {
            if (g[j][i] == 0) flag1 = false; //row
            if (g[i][j] == 0) flag2 = false; //col
            if (g[i][j] == 1) 
            {
                x = i; 
                y = j; 
                cnt2++;
            }
        }
        cnt += (flag1 + flag2);
        if (flag1) row = i; 
        if (flag2) col = i;
    }
    if (cnt == 1 && cnt2 == n - 1)
    {
        if (row > 0) cout << row << " 1" << endl;
        else cout << "1 " << col << endl;
        return 0;
    }    
    if (cnt2 == 1) cout << y << " " << x << endl;
    else cout << -1 << endl;
    return 0;
}