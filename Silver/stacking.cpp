#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, K;
  cin >> N >> K;
  int a[1000005] = {0};
  int x, y;
  for (int i = 0; i < K; ++i)
    {
      cin >> x >> y;
      a[x]++;
      a[y + 1]--;
    }
  multiset<int> cnt;
  int cur = 0;
  for (int i = 1; i <= N; ++i)
    {
      cur += a[i];
      cnt.insert(cur);
    }
  auto it = cnt.begin();
  advance(it, N / 2);
  cout << *it << endl;
  return 0;
}
