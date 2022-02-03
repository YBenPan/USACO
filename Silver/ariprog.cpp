/*
ID: benpan01
LANG: C++
TASK: ariprog
*/

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
bool bisquare[125005] = {false};
set<int> val;
int main()
{
  ifstream fin("ariprog.in");
  ofstream fout("ariprog.out");
  ios_base::sync_with_stdio(false);
  fin.tie(NULL);
  int N, M;
  int tot = 0;
  fin >> N;
  fin >> M;
  fin.close();
  for (int i = 0; i <= M; ++i)
    {
      for (int j = 0; j <= M; ++j)
        {
          int x = i * i + j * j;
    at are       if (!bisquare[x])
            {
              bisquare[x] = true;
              val.insert(x);
            }
        }
    }
  int M_limit = M * M * 2;
  /*for (auto i : val)
    {
      fout << i << " ";
    }
  fout << endl;*/
  for (int i = 1; i <= M_limit; ++i)
    {
      for (auto j : val)
        {
          int x = j;
          if (x + (N - 1) * i <= M_limit)
            {
              //fout << j << " " << i << endl;
              bool flag = true;
              for (int k = 1; k < N; ++k)
                {
                  x += i;
                  if (!bisquare[x])
                    {
                      flag = false;
                      break;
                    }
                }
              if (flag)
                {
                  fout << j << " " << i << endl;
                  ++tot;
                }
            }
          else
            break;
        }
    }
  if (tot == 0)
    {
      fout << "NONE" << endl;
    }
  fout.close();
  return 0;
}
