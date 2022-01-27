#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
struct input
{
  int day, ID, change;
};
LL maxx, maxx_cnt = 0, ans = 0;
map<int, int> cow;
map<int, int, greater<int> > cnt;
bool cmp(const input &a, const input &b)
{
  return a.day < b.day;
}
int main()
{
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, G;
  cin >> N >> G;
  maxx = G;
  vector<input> in(N);
  for (int i = 0; i < N; ++i)
    {
      cin >> in[i].day >> in[i].ID >> in[i].change;
    }
  cnt[0] = N + 1;
  sort(in.begin(), in.end(), cmp);
  for (auto& it : in)
    {
      int& original = cow[it.ID];
      bool isTopBefore = cnt.begin()->first == original;
      int CntBefore = cnt[original]--;
      if (cnt[original] == 0) cnt.erase(original);
      original += it.change;
      int CntAfter = ++cnt[original];
      bool isTopAfter = cnt.begin()->first == original;
      if ((isTopBefore ^ isTopAfter) || ((isTopBefore && isTopAfter) && (CntBefore != CntAfter))) ans++;
      /*if (isTopBefore)
        {
          if (!isTopAfter || CntBefore != 1 || CntAfter != 1) ans++;
        }
        else if (isTopAfter) ans++;*/
      //cout << cnt.begin() -> first << " " << CntBefore << " " << CntAfter << endl;
    }
  cout << ans << endl;
  return 0;
}
