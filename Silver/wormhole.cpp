/*
ID: benpan01
LANG: C++
TASK: wormhole
*/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int x[13], y[13];
int partner[13];
int next_on_right[13];
int N;
int total = 0;
bool cycle()
{
  for (int i = 1; i <= N; ++i)
    {
      int pos = i;
      for (int j = 1; j <= N; ++j)
        pos = next_on_right[partner[pos]];
      if (pos != 0)
        {
          return true;
        }
    }
  return false;
}
void solve()
{
  int i;
  for (i = 1; i <= N; ++i)
    if (partner[i] == 0)
      break;
  if (i > N)
    if (cycle() == true)
      {
        ++total;
        return;
      }
  for (int j = i + 1; j <= N; ++j)
    {
      if (partner[j] == 0)
        {
          partner[i] = j;
          partner[j] = i;
          solve();
          partner[i] = 0;
          partner[j] = 0;
        }
    }
}
int main()
{
  ifstream fin("wormhole.in");
  ofstream fout("wormhole.out");
  ios_base::sync_with_stdio(false);
  fin.tie(NULL);
  fin >> N;
  for (int i = 1; i <= N; ++i)
    {
      fin >> x[i] >> y[i];
    }
  for (int i = 1; i <= N; ++i)
    {
      for (int j = 1; j <= N; ++j)
        {
          if (y[j] == y[i] && x[j] > x[i])
            {
              if (next_on_right[i] == 0 || x[j] - x[i] < x[next_on_right[i]] - x[i])
                {
                  next_on_right[i] = j;
                }
            }
        }
      //fout << next_on_right[i] << endl;
    }
  solve();
  fout << total << endl;
  return 0;
}
