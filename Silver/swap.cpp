#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int f[35][100005];
int main()
{
  ifstream fin("swap.in");
  ofstream fout("swap.out");
  ios_base::sync_with_stdio(false);
  fin.tie(NULL);
  int N, M, K;
  fin >> N >> M >> K;
  int l[105], r[105];
  for (int i = 1; i <= M; ++i)
    {
      fin >> l[i] >> r[i];
    }
  int rot[100005];
  for (int i = 1; i <= N; ++i) rot[i] = i;
  for (int i = 1; i <= M; ++i)
    {
      reverse(rot + l[i], rot + r[i] + 1);
    }
  for (int i = 1; i <= N; ++i)
    f[0][i] = rot[i];
  for (int i = 1; i <= 30; ++i)
    for (int j = 1; j <= N; ++j)
      f[i][j] = f[i - 1][f[i - 1][j]];
  for (int i = 1; i <= N; ++i)
    {
      int x = i, m = K;
      for (int j = 30; j >= 0; j--)
        if (m >= (1 << j))
          {
            x = f[j][x];
            m -= (1 << j);
          }
      fout << x << endl;
    }
  return 0;
}
