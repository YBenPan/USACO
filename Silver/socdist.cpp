#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
vector< pair<LL, LL> > itv;
int N, M;
bool cmp(pair<int, int> i, pair<int, int> j)
{
  return i.first < j.first;
}
bool check(int mid)
{
  LL cnt = 0;
  LL last = 0;
  for (int i = 0; i < M; ++i)
    {
      //if (mid == 4) cout << i << " " << cnt << " " << last << endl;
      LL diff = itv[i].second - max(last, itv[i].first) + 1;
      LL num;
      if (diff < 1) num = 0;
      else num = (diff - 1) / mid + 1;
      cnt += num;
      if (num > 0) last = max(last, itv[i].first) + num * mid;
    }
  //if (mid == 7)cout << cnt << endl;
  return cnt >= N;
}
int main()
{
  ifstream fin("socdist.in");
  ofstream fout("socdist.out");
  ios_base::sync_with_stdio(false);
  fin.tie(NULL);
  fout.tie(NULL);
  fin >> N >> M;
  LL a, b;
  for (int i = 0; i < M; ++i)
    {
      fin >> a >> b;
      itv.push_back({a ,b});
    }
  sort(itv.begin(), itv.end(), cmp);
  LL l = 0;
  LL r = itv[M - 1].second;
  while (l < r)
    {
      //cout << l << " " << r << endl;
      if (l + 1 == r)
        {
          if (check(l)) r = l;
          break;
        }
      LL m = l + (r - l) / 2;
      if (check(m)) l = m;
      else r = m;
    }
  fout << r << endl;
  return 0;
}
