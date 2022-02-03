/*
ID: benpan01
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <vector>
int main()
{
  std::ofstream fout ("barn1.out");
  std::ifstream fin ("barn1.in");
  std::vector <int> stall, gap;
  int stallCovered, stallNumber, M, S, C, diff;
  fin >> M >> S >> C;
  if (M > C)
    {
      stallCovered = C;
    }
  else
    {
      for (int i = 0; i < C; ++i)
        {
          fin >> stallNumber;
          stall.push_back (stallNumber);
        }
      std::sort (stall.begin(), stall.end());
      stallCovered = M;
      for (int i = 1; i < C; ++i)
        {
          diff = stall[i] - stall[i - 1];
          gap.push_back (diff);
        }
      std::sort (gap.begin(), gap.end());
      for (int i = 0; i < C - M; ++i)
        stallCovered += gap[i];
    }
  fout << stallCovered << std::endl;
  return 0;
}
