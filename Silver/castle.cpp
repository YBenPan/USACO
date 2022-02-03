/*
ID: benpan04
TASK: castle
LANG: C++
*/
#include <bits/stdc++.h>
#include <fstream>
#define LL long long
using namespace std;
vector< vector<int> > g(2505);
bool visited[2505] = {false};
vector< vector<int> > CC(2505);
int vCC[2505];
void dfs(int num, int s)
{
  visited[s] = true;
  CC[num].push_back(s);
  vCC[s] = num;
  for (int i = 0; i < g[s].size(); ++i)
    if (!visited[g[s][i]])
      dfs(num, g[s][i]);
}
struct room
{
  int row;
  int col;
  char dir;
};
int main()
{
  ifstream fin("castle.in");
  ofstream fout("castle.out");
  ios_base::sync_with_stdio(false);
  fin.tie(NULL);
  fout.tie(NULL);
  int M, N;
  fin >> M >> N;
  int index = 0, input;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      {
        fin >> input;
        if (input < 8 && i < N - 1)
          {
            g[index].push_back(index + M);
            g[index + M].push_back(index);
          }
        else input -= 8;
        if (input < 4 && j < M - 1)
          {
            g[index].push_back(index + 1);
            g[index + 1].push_back(index);
          }
        else input -= 4;
        if (input < 2 && i > 0)
          {
            g[index].push_back(index - M);
            g[index - M].push_back(index);
          }
        else input -= 2;
        if (input < 1 && j > 0)
          {
            g[index].push_back(index - 1);
            g[index - 1].push_back(index);
          }
        else input -= 1;
        index++;
      }
  int cnt = 0, max_room = 0, max_change = 0;
  for (int i = 0; i < M * N; ++i)
    {
      if (!visited[i])
        {
          dfs(cnt, i);
          max_room = max(max_room, (int)CC[cnt].size());
          cnt++;
        }
    }
  fout << cnt << endl;
  fout << max_room << endl;
  index = 0;
  room ans;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      {
        int change = 0;

        if (i > 0 && vCC[index] != vCC[index - M])
          {
            change = CC[vCC[index]].size() + CC[vCC[index - M]].size();
            if (change > max_change)
              {
                max_change = change;
                ans.row = i; ans.col = j; ans.dir = 'N';
              }
            else if (max_change == change)
              {
                if (ans.col > j)
                  {ans.row = i; ans.col = j; ans.dir = 'N';}
                else if (ans.col == j)
                  {
                    if (ans.row < i)
                      {ans.row = i; ans.col = j; ans.dir = 'N';}
                    else if (ans.row == i)
                      if (ans.dir == 'E') {ans.row = i; ans.col = j; ans.dir = 'N';}
                  }
              }
          }
        if (j < M - 1 && vCC[index] != vCC[index + 1])
          {
            change = CC[vCC[index]].size() + CC[vCC[index + 1]].size();
            if (change > max_change)
              {
                max_change = change;
                ans.row = i; ans.col = j; ans.dir = 'E';
              }
            else if (max_change == change)
              {
                if (ans.col > j)
                  {ans.row = i; ans.col = j; ans.dir = 'E';}
                else if (ans.col == j)
                  {
                    if (ans.row < i) {ans.row = i; ans.col = j; ans.dir = 'E';}
                  }
              }
          }
        index++;
      }
  fout << max_change << endl;
  fout << ans.row + 1 << " " << ans.col + 1 << " " << ans.dir << endl;
  return 0;
}
