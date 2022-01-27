#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi = vector<int>;
using namespace std;
struct lg
{
  int l, r;
}a[100005];
bool cmp(const lg &a, const lg &b)
{
  if (a.l == b.l) return a.r < b.r;
  return a.l < b.l;
}
int main()
{
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> a[i].l >> a[i].r;
  sort(a, a + N, cmp);
  int ans = 0;
  int last = 0;
  for (int i = 0; i < N; ++i)
    {
      if (a[i].r > last)
        {
          int t = max(last, a[i].l);
          ans += a[i].r - t;
          last = a[i].r;
        }
    }
  last = 0;
  int minn = 1E9;
  a[N].l = a[N - 1].r;
  for (int i = 0; i < N; ++i)
    {
      if (a[i].r <= last) {minn = 0; break;}
      int t = min(a[i + 1].l, a[i].r) - max(a[i].l, last);
      minn = min(minn, t);
      last = max(last, a[i].r);
    }
  minn = max(0, minn);
  cout << ans - minn << endl;
  return 0;
}
