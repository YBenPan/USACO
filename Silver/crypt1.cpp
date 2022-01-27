/*
ID: benpan01
PROG: crypt1
LANG: C++
*/
#include <fstream>
bool check(int a, int b, int c, int d, int e);
int N, total, temp;
int num[10];
int main()
{
  std::ifstream fin("crypt1.in");
  std::ofstream fout("crypt1.out");
  total = 0;
  fin >> N;
  for (int i = 0; i < N; ++i)
    {
      fin >> num[i];
    }
  for (int a = 1; a <= 9; ++a)
    for (int b = 1; b <= 9; ++b)
      for (int c = 1; c <= 9; ++c)
        for (int d = 1; d <= 9; ++d)
          for (int e = 1; e <= 9; ++e)
            if (check(a, b, c, d, e)) ++total;
  fout << total << std::endl;
  return 0;
}
bool find(int a)
{
  for (int i = 0; i < N; ++i)
    if (a == num[i]) return true;
  return false;
}
bool valid(int a)
{
  while (a > 0)
    if (find(a % 10)) a /= 10;
    else return false;
  return true;
}
bool check(int a, int b, int c, int d, int e)
{
  int factor_1, factor_2, product_1, product_2, product_3;
  factor_1 = a * 100 + b * 10 + c;
  factor_2 = d * 10 + e;
  product_1 = factor_1 * d;
  product_2 = factor_1 * e;
  product_3 = factor_1 * factor_2;
  if (product_1 < 100 || product_1 >= 1000) return false;
  if (product_2 < 100 || product_2 >= 1000) return false;
  if (product_3 < 1000 || product_3 >= 10000) return false;
  if (!valid(factor_1)) return false;
  if (!valid(factor_2)) return false;
  if (!valid(product_1)) return false;
  if (!valid(product_2)) return false;
  if (!valid(product_3)) return false;
  return true;
}
