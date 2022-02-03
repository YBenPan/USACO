#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
string s[505], p[505];
bool flag[5][5][5]; 
//0: A, 1: C, 2: G, 3: T
int ident(char c)
{
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    if (c == 'T') return 3; 
    return 4;
}
int main()
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        cin >> p[i]; 
    int tot = 0; 
    for (int i = 0; i < m - 2; ++i)
        for (int j = i + 1; j < m - 1; ++j)
            for (int k = j + 1; k < m; ++k)
            {
                memset(flag, 0, sizeof(flag));
                for (int it = 0; it < n; ++it)
                {
                    int n1 = ident(s[it][i]);
                    int n2 = ident(s[it][j]);
                    int n3 = ident(s[it][k]);
                    flag[n1][n2][n3] = true; 
                }
                bool unique = true; 
                for (int it = 0; it < n && unique; ++it)
                {
                    int n1 = ident(p[it][i]);
                    int n2 = ident(p[it][j]);
                    int n3 = ident(p[it][k]);
                    if (flag[n1][n2][n3]) unique = false; 
                }
                if (unique) tot++;
            }
    cout << tot << endl;
    return 0;
}