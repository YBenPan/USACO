/*
ID: benpan04
TASK: hamming
LANG: C++
*/
#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ifstream fin("hamming.in");
  ofstream fout("hamming.out");
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, B, D;
  fin >> N >> B >> D;
  vector<int> ans;
  ans.push_back(0);
  for (int i = 1; i < (1 << B) && ans.size() < N; ++i)
    {
      bool flag = true;
      for (int j = 0; j < ans.size() && flag; ++j)
        {
          int res = i ^ ans[j];
          int cnt = 0;
          while (res > 0)
            {
              if (res % 2 == 1) cnt++;
              res /= 2;
            }
          if (cnt < D) flag = false;
        }
      if (flag) ans.push_back(i);
    }
  for (int i = 0; i < ans.size(); ++i)
    {
      if ((i + 1) % 10 == 0) fout << ans[i] << endl;
      else if (i == ans.size() - 1) fout << ans[i];
      else fout << ans[i] << " ";
    }
  if (ans.size() % 10) fout << endl;
  return 0;
}
