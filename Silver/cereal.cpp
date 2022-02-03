#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxint = 100005;
pair<int, int> cereal[maxint];
int ans[maxint], open[maxint];
int cnt = 0;
void dfs(int cur, int fav)
{
  if (open[fav] == -1)
    {
      open[fav] = cur;
      cnt++;
      return;
    }
  else if (open[fav] > cur)
    {
      int temp = open[fav];
      open[fav] = cur;
      if (cereal[temp].first == fav) dfs(temp, cereal[temp].second);
    }
}
int main()
{
  ifstream fin("cereal.in");
  ofstream fout("cereal.out");
  ios_base::sync_with_stdio(false);
  fin.tie(NULL);
  fout.tie(NULL);
  int N, M;
  fin >> N >> M;
  for (int i = 0; i < N; ++i)
    fin >> cereal[i].first >> cereal[i].second;
  memset(open, -1, sizeof(open));
  for (int i = N - 1; i >= 0; --i)
    {
      dfs(i, cereal[i].first);
      ans[i] = cnt;
    }
  for (int i = 0; i < N; ++i) fout << ans[i] << endl;
  return 0;
}
