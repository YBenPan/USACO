/*
ID: benpan01
LANG: C++
TASK: numtri
*/

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main()
{
  ifstream fin("numtri.in");
  ofstream fout("numtri.out");
  ios_base::sync_with_stdio(false);
  fin.tie(NULL);
  int N;
  fin >> N;
  int a[1005][1005] = {0}, dp[1005][1005] = {0};
  for (int i = 1; i <= N; ++i)
    {
      for (int j = 1; j <= i; ++j)
        {
          fin >> a[i][j];
        }
    }
  fin.close();
  dp[1][1] = a[1][1];
  int max_dp = 0;
  for (int i = 2; i <= N; ++i)
    {
      for (int j = 1; j <= i; ++j)
        {
          dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j])+ a[i][j];
          max_dp = max(max_dp, dp[i][j]);
        }
    }
  fout << max_dp << endl;
  fout.close();
  return 0;
}
