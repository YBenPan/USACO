/*
ID: benpan04
TASK: sort3
LANG: C++
*/
#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ifstream fin("sort3.in");
  ofstream fout("sort3.out");
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  fin >> N;
  vector<int> a(N);
  int cnt[5] = {0};
  for (int i = 0; i < N; ++i)
    {
      fin >> a[i];
      if (a[i] == 1) cnt[1]++;
    }
  int ans = 0;
  for (int i = 0; i < cnt[1]; ++i)
    {
      if (a[i] == 2) cnt[2]++;
      else if (a[i] == 3) cnt[3]++;
      else ans--;
      ans++;
      a[i] = 1;
    }
  for (int i = N - 1; i >= 0 && (cnt[2] > 0 || cnt[3] > 0); i--)
    {
      if (a[i] == 1)
        {
          if (cnt[3]) {a[i] = 3; cnt[3]--;}
          else {a[i] = 2; cnt[2]--;}
        }
    }
  for (int i = cnt[1]; i < N; ++i)
    cnt[a[i]]++;
  for (int i = cnt[1]; i < cnt[1] + cnt[2]; ++i)
    if (a[i] != 2) ans++;
  fout << ans << endl;
  //for (int i = 0; i < N; ++i) fout << a[i] << " ";
  return 0;
}
