#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
int main()
{
  freopen("paintbarn.in", "r", stdin);
  freopen("paintbarn.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int x1, x2, y1, y2, maxx = 0, maxy = 0;
  int cnt[1005][1005] = {0};
  for (int i = 0; i < n; ++i)
    {
      cin >> x1 >> y1 >> x2 >> y2;
      for (int j = y1; j < y2; ++j)
        cnt[x1][j]++, cnt[x2][j]--;
    }
  int ans = 0;
  for (int i = 0; i < 1000; ++i)
    {
      int tot = 0;
      for (int j = 0; j < 1000; ++j)
        {
          tot += cnt[j][i];
          //cout << cnt[j][i] << " ";
          ans += (tot == k);
        }
      //cout << endl;
    }
  cout << ans << endl;
  return 0;
}
