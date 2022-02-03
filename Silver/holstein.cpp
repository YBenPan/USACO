/*
ID: benpan04
TASK: holstein
LANG: C++
*/
#include <bits/stdc++.h>
#define LL long long
using namespace std;
int V, G;
int a[30];
int f[20][30];
vector<int> ans;
int selec[20];
void search(int last, int num)
{
  if (num == G)
    {
      int sum[30] = {0};
      int cnt = 0;
      int minn = -1;
      for (int i = 0; i < G; ++i)
        if (selec[i] == 1)
          {
            cnt++;
            if (minn == -1) minn = i;
            for (int j = 0; j < V; ++j)
              {
                sum[j] += f[i][j];
              }
          }
      bool flag = true;
      for (int i = 0; i < V && flag; ++i)
        if (sum[i] < a[i])
          flag = false;
      if (flag)
        {
          if (ans.size() > cnt || (ans.size() == cnt && ans[0] > minn) || ans.size() == 0)
            {
              ans.clear();
              for (int i = 0; i < G; ++i)
                if (selec[i] == 1) ans.push_back(i);
            }
        }
    }
  else
    {
      selec[num] = last;
      search(0, num + 1);
      search(1, num + 1);
    }
}
int main()
{
  ifstream fin("holstein.in");
  ofstream fout("holstein.out");
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fin >> V;
  for (int i = 0; i < V; ++i) fin >> a[i];
  fin >> G;
  for (int i = 0; i < G; ++i)
    for (int j = 0; j < V; ++j)
      fin >> f[i][j];
  search(0, 0);
  search(1, 0);
  fout << ans.size();
  for (int i : ans) fout << " " << i + 1;
  fout << endl;
  return 0;
}
