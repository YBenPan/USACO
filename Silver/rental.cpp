#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi = vector<int>;
using namespace std;
LL cow[100005], rent[100005];
pair<LL, LL> p[100005];
LL sum[100005];
bool cmp(const pair<LL, LL> &a, const pair<LL, LL> &b)
{
  return a.second > b.second;
}
int main()
{
  freopen("rental.in", "r", stdin);
  freopen("rental.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  LL n, m, rt;
  cin >> n >> m >> rt;
  for (int i = 1; i <= n; ++i) cin >> cow[i];
  for (int i = 1; i <= m; ++i) cin >> p[i].first >> p[i].second;
  for (int i = 1; i <= rt; ++i) cin >> rent[i];
  sort(rent + 1, rent + rt + 1, greater<LL>());
  sort(cow + 1, cow + n + 1, greater<LL>());
  sort(p + 1, p + m + 1, cmp);
  /*
  sum[1] = p[1].first * p[1].second;
  for (int i = 2; i <= m; ++i)
    {
      p[i].first += p[i - 1].first;
      sum[i] = sum[i - 1] + p[i].first * p[i].second;
      }*/
  for (int i = 2; i <= rt; ++i) rent[i] += rent[i - 1];
  LL ans = 0;
  LL j = 1;
  LL cost = 0;
  LL milk = 0;
  for (int i = 0; i <= n; ++i)
    {
      milk += cow[i];
      while (j <= m && milk >= p[j].first)
        {
          cost += (LL)p[j].first * p[j].second;
          milk -= p[j].first;
          j++;
        }
      if (j <= m)
        {
          cost += (LL)milk * p[j].second;
          p[j].first -= milk;
          milk = 0;
        }
      ans = max(ans, cost + rent[min(rt, n - i)]);
    }
  cout << ans << endl;
  return 0;
}
