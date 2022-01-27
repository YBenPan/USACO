#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
int main()
{
  freopen("div7.in", "r", stdin);
  freopen("div7.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int input;
  int first[7], last[7];
  for (int i = 0; i < 7; ++i) first[i] = -1;
  int sum = 0;
  for (int i = 1; i <= n; ++i)
    {
      cin >> input;
      sum = (sum + input % 7) % 7;
      if (first[sum] == -1) first[sum] = i;
      last[sum] = i;
    }
  int ans = 0;
  for (int i = 0; i < 7; ++i)
    if (first[i] != -1)
      ans = max(ans, last[i] - first[i]);
  cout << ans << endl;
  return 0;
}
