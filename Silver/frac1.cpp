/*
ID: benpan01
TASK: frac1
LANG: C++
*/


#include <bits/stdc++.h>
#include <fstream>
#define LL long long
using namespace std;
vector< pair<int, int> > a;
bool cmp(pair<int, int> b, pair<int, int> c)
{
  return (b.first * c.second) < (b.second * c.first);
}
int main()
{
  ifstream fin("frac1.in");
  ofstream fout("frac1.out");
  ios_base::sync_with_stdio(false);
  fin.tie(NULL);
  fout.tie(NULL);
  int N;
  fin >> N;
  a.push_back({0, 1});
  a.push_back({1, 1});
  for (int i = 2; i <= N; ++i)
    for (int j = 1; j < i; ++j)
      {
        bool flag = true;
        if (i % 2 == 0 && j % 2 == 0) flag = false;
        for (int k = 3; k <= min(i, j) && flag; k += 2)
          if (i % k == 0 && j % k == 0) flag = false;
        if (flag) a.push_back({j, i});
      }
  sort(a.begin() + 1, a.end(), cmp);
  for (int i = 0; i < a.size(); ++i)
    fout << a[i].first << '/' << a[i].second << endl;
  return 0;
}
