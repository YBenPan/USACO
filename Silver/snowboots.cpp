#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
struct tile
{
  int depth, index;
}tiles[100005];
struct boot
{
  int depth, dist, index;
}boots[100005];
bool cmp1(const tile &a, const tile &b)
{
  return a.depth < b.depth;
}
bool cmp2(const boot &a, const boot &b)
{
  return a.depth < b.depth;
}
int main()
{
  freopen("snowboots.in", "r", stdin);
  freopen("snowboots.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, B;
  cin >> N >> B;
  int prev[100005], next[100005];
  for (int i = 0; i < N; ++i)
    {
      cin >> tiles[i].depth;
      tiles[i].index = i;
    }
  for (int i = 0; i < B; ++i)
    {
      cin >> boots[i].depth >> boots[i].dist;
      boots[i].index = i;
    }
  sort(tiles, tiles + N, cmp1);
  sort(boots, boots + B, cmp2);
  for (int i = 0; i < N; ++i)
    {
      prev[i] = i - 1;
      next[i] = i + 1;
    }
  int maxgap = 1;
  int j = N - 1;
  int ans[100005];
  for (int i = B - 1; i >= 0; --i)
    {
      while (j >= 0 && tiles[j].depth > boots[i].depth)
        {
          prev[next[tiles[j].index]] = prev[tiles[j].index];
          next[prev[tiles[j].index]] = next[tiles[j].index]; // delete node
          maxgap = max(maxgap, next[tiles[j].index] - prev[tiles[j].index]);
          j--;
        }
      ans[boots[i].index] = (boots[i].dist >= maxgap);
    }
  for (int i = 0; i < B; ++i) cout << ans[i] << endl;
  return 0;
}
