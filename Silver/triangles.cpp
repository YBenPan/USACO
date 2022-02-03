#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi = vector<int>;
using namespace std;
int N;
const int maxlim = 1E5 + 5;
const int convert = 1E4 + 5;
LL sumX[2 * convert], sumY[2 * convert], cntX[2 * convert], cntY[2 * convert], lastX[2 * convert], lastY[2 * convert];
struct point
{
  int x, y;
}pts[maxlim];
LL ans = 0;
bool cmp1(const point &a, const point &b)
{
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
bool cmp2(const point &a, const point &b)
{
  if (a.x == b.x) return a.y > b.y;
  return a.x < b.x;
}
bool cmp3(const point &a, const point &b)
{
  if (a.x == b.x) return a.y < b.y;
  return a.x > b.x;
}
bool cmp4(const point &a, const point &b)
{
  if (a.x == b.x) return a.y > b.y;
  return a.x > b.x;
}
void solve()
{
  memset(sumX, 0, sizeof(sumX));
  memset(sumY, 0, sizeof(sumY));
  memset(cntX, 0, sizeof(cntX));
  memset(cntY, 0, sizeof(cntY));
  for (int i = 0; i < N; ++i)
    {
      int x = pts[i].x, y = pts[i].y;
      sumX[x] = (sumX[x] + abs(y - lastX[x]) * cntX[x]) % MOD;
      cntX[x]++;
      lastX[x] = y;
      sumY[y] = (sumY[y] + abs(x - lastY[y]) * cntY[y]) % MOD;
      cntY[y]++;
      lastY[y] = x;
      ans = (ans + sumX[x] * sumY[y]) % MOD;
    }
}
int main()
{
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; ++i)
    {
      cin >> pts[i].x >> pts[i].y;
      pts[i].x += convert; //prevent negative
      pts[i].y += convert;
    }
  sort(pts, pts + N, cmp1);
  solve();
  sort(pts, pts + N, cmp2);
  solve();
  sort(pts, pts + N, cmp3);
  solve();
  sort(pts, pts + N, cmp4);
  solve();
  cout << ans << endl;
  return 0;
}
