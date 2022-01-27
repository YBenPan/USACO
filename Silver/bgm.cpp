#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int mapped(char ch)
{
    if (ch == 'B') return 0;
    if (ch == 'E') return 1; 
    if (ch == 'S') return 2; 
    if (ch == 'I') return 3;
    if (ch == 'G') return 4;
    if (ch == 'O') return 5;
    if (ch == 'M') return 6;
    return 10; 
}
int cnt[7][7] = {0}; // number of values with letter i and mod j
main()
{
    freopen("bgm.in", "r", stdin);
    freopen("bgm.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    char ch;
    int in2;
    for (int i = 0; i < n; ++i)
    {
        cin >> ch >> in2;
        int in1 = mapped(ch); 
        in2 %= 7; 
        if (in2 < 0) in2 += 7;
        cnt[in1][in2]++; 
    }
    int tot = 0;
    for (int i0 = 0; i0 < 7; ++i0)
        for (int i1 = 0; i1 < 7; ++i1)
            for (int i2 = 0; i2 < 7; ++i2)
                for (int i3 = 0; i3 < 7; ++i3)
                    for (int i4 = 0; i4 < 7; ++i4)
                        for (int i5 = 0; i5 < 7; ++i5)
                            for (int i6 = 0; i6 < 7; ++i6)
                            {
                                int bessie = (i0 + 2 * i1 + 2 * i2 + i3) % 7; 
                                int goes = (i4 + i5 + i1 + i2) % 7; 
                                int moo = (i6 + i5 * 2) % 7; 
                                if (bessie * goes * moo == 0)
                                {
                                    tot += (cnt[0][i0] * cnt[1][i1] * cnt[2][i2] * cnt[3][i3] * cnt[4][i4] * cnt[5][i5] * cnt[6][i6]); 
                                }
                            }
    cout << tot << endl;
    return 0;
}