/*
ID: benpan04
LANG: C++
TASK: sprime
*/

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int N;
ifstream fin("sprime.in");
ofstream fout("sprime.out");
bool check_prime(int i)
{
  bool flag = true;
  for (int j = 2; j <= sqrt(i) && flag; ++j)
    if (i % j == 0)
       flag = false;
  return flag;
}
void find(int d, int num_d)
{
  if (num_d == N)
    {
      if (check_prime(d))
        fout << d << endl;
      return;
    }
  if (!check_prime(d))
    return;
  ++num_d;
  d *= 10;
  find(d + 1, num_d);
  find(d + 3, num_d);
  find(d + 7, num_d);
  find(d + 9, num_d);
}
int main()
{
  ios_base::sync_with_stdio(false);
  fin.tie(NULL);
  fin >> N;
  find(2, 1);
  find(3, 1);
  find(5, 1);
  find(7, 1);
  return 0;
}
