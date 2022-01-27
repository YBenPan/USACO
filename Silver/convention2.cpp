#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
struct cow
{
  int senior, arrive, time;
  bool operator <(const cow &a) const
  {
    return senior > a.senior;
  }
};
vector<cow> c;
bool cmp(const cow &a, const cow &b)
{
  if (a.arrive == b.arrive) return a.senior < b.senior;
  return a.arrive < b.arrive;
}
int main()
{
  freopen("convention2.in", "r", stdin);
  freopen("convention2.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  int a, b;
  for (int i = 0; i < N; ++i)
    {
      cin >> a >> b;
      c.push_back({i, a, b});
    }
  sort(c.begin(), c.end(), cmp);
  int i = 0, maxx = 0, time = 0;
  priority_queue<cow> q;
  while (i < N)
    {
      while (!q.empty())
        {
          cow t = q.top();
          q.pop();
          int diff = time - t.arrive;
          maxx = max(maxx, diff);
          time += t.time;
          while (c[i].arrive <= time && i < N) q.push(c[i++]);
        }
      q.push(c[i]);
      if (i < N - 1) i++;
      time = q.top().arrive;
    }
  cout << maxx << endl;
  return 0;
}
