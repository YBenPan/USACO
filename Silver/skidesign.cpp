/*
ID: benpan01
LANG: C++
TASK: skidesign
*/

#include <bits/stdc++.h>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
  ifstream fin("skidesign.in");
  ofstream fout("skidesign.out");
  ios_base::sync_with_stdio(false);
  fin.tie(NULL);
  int N;
  fin >> N;
  int a[1005];
  for (int i = 0; i < N; ++i)
    {
      fin >> a[i];
    }
  long long minimum = 1000000000;
  for (int i = 0; i <= 83; ++i)
    {
      long long sum = 0;
      int start = i;
      int end = i + 17;
      for (int j = 0; j < N; ++j)
        {
          if (a[j] < start)
            {
              sum += ((start - a[j]) * (start - a[j]));
            }
          else if (a[j] > end)
            {
              sum += ((a[j] - end) * (a[j] - end));
            }
        }
      minimum = min(sum, minimum);
    }
  fout << minimum << endl;
  return 0;
}
