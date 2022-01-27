/*
ID: benpan01
LANG: C++
TASK: milk3
*/

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("milk3.in");
ofstream fout("milk3.out");
bool visited[21][21][21] = {false};
set<int> sol;
int A, B, C;
int transfer(int p, int q, int c2)
{
  int cap = c2 - q;
  if (p >= cap)
    {
      return cap;
    }
  else
    {
      return p;
    }
}
void dfs(int m1, int m2, int m3)
{
  visited[m1][m2][m3] = true;
  //fout << m1 << " " << m2 << " " << m3 << endl;
  int tr;
  if (m1 == 0)
    {
      sol.insert(m3);
    }
  if (m1 > 0)
    {
      tr = transfer(m1, m2, B);
      if (visited[m1 - tr][m2 + tr][m3] == false)
        {
          dfs(m1 - tr, m2 + tr, m3);
        }
      tr = transfer(m1, m3, C);
      if (visited[m1 - tr][m2][m3 + tr] == false)
        {
          dfs(m1 - tr, m2, m3 + tr);
        }
    }
  if (m2 > 0)
    {
      tr = transfer(m2, m1, A);
      if (visited[m1 + tr][m2 - tr][m3] == false)
        {
          dfs(m1 + tr, m2 - tr, m3);
        }
      tr = transfer(m2, m3, C);
      if (visited[m1][m2 - tr][m3 + tr] == false)
        {
          dfs(m1, m2 - tr, m3 + tr);
        }
    }
  if (m3 > 0)
    {
      tr = transfer(m3, m1, A);
      if (visited[m1 + tr][m2][m3 - tr] == false)
        {
          dfs(m1 + tr, m2, m3 - tr);
        }
      tr = transfer(m3, m2, B);
      if (visited[m1][m2 + tr][m3 - tr] == false)
        {
          dfs(m1, m2 + tr, m3 - tr);
        }
    }
}
int main()
{
  ios_base::sync_with_stdio(false);
  fin.tie(NULL);
  fin >> A >> B >> C;
  dfs(0, 0, C);
  int s = sol.size();
  int j = 0;
  for (auto i : sol)
    {
      ++j;
      if (j != s)
        {
          fout << i << " ";
        }
      else
        fout << i;
    }
  fout << endl;
  return 0;
}
