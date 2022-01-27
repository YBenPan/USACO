/*
ID: benpan01
LANG: C++
TASK: pprime
*/

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
set<int> pal;
vector<int> prime;
void gen_palindromes()
{
  pal.insert(5);
  pal.insert(6);
  pal.insert(7);
  pal.insert(8);
  pal.insert(9);
  pal.insert(11);
  int d1, d2, d3, d4;
  for (d1 = 1; d1 <= 9; d1 += 2)
    for (d2 = 0; d2 <= 9; ++d2)
      {
        pal.insert(d1 * 100 + d2 * 10 + d1);
        pal.insert(d1 * 1000 + d2 * 100 + d2 * 10 + d1);
      }
  for (d1 = 1; d1 <= 9; d1 += 2)
    for (d2 = 0; d2 <= 9; ++d2)
      for (d3 = 0; d3 <= 9; ++d3)
        {
          pal.insert(d1 * 10000 + d2 * 1000 + d3 * 100 + d2 * 10 + d1);
          pal.insert(d1 * 100000 + d2 * 10000 + d3 * 1000 + d3 * 100 + d2 * 10 + d1);
        }
  for (d1 = 1; d1 <= 9; d1 += 2)
    for (d2 = 0; d2 <= 9; ++d2)
      for (d3 = 0; d3 <= 9; ++d3)
        for (d4 = 0; d4 <= 9; ++ d4)
          {
            pal.insert(d1 * 1000000 + d2 * 100000 + d3 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1);
            pal.insert(d1 * 10000000 + d2 * 1000000 + d3 * 100000 + d4 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1);
          }
}
void gen_primes()
{
  for (int i = 2; i <= 10000; ++i)
    {
      bool flag = true;
      for (int j = 2; j <= sqrt(i) && flag; ++j)
        {
          if (i % j == 0)
            flag = false;
        }
      if (flag)
        prime.push_back(i);
    }
}
int main()
{
  ifstream fin("pprime.in");
  ofstream fout("pprime.out");
  ios_base::sync_with_stdio(false);
  fin.tie(NULL);
  int a, b;
  fin >> a >> b;
  gen_palindromes();
  gen_primes();
  for (auto i : pal)
    {
      if (i >= a && i <= b)
        {
          int num = i;
          bool flag = true;
          for (auto j : prime)
            {
              if (num % j == 0)
                flag = false;
              if (j >= sqrt(num))
                break;
            }
          if (flag)
            fout << num << endl;
        }
    }
  return 0;
}
