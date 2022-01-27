#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
int main()
{
  freopen("maxcross.in", "r", stdin);
  freopen("maxcross.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k, b;
  cin >> n >> k >> b;
  int pre[100005], rep[100005];
  for (int i = 0; i < b; ++i)
    {
      cin >> rep[i];
    }
  sort(rep, rep + b);
  pre[0] = 0;
  int j = 0;
  for (int i = 1; i <= n; ++i)
    {
      pre[i] = pre[i - 1];
      if (rep[j] == i)
        {
          pre[i]++;
          j++;
        }
      //cout << pre[i] << " ";
    }
  int minn = 1E7;
  for (int i = k; i <= n; ++i)
    minn = min(minn, pre[i] - pre[i - k]);
  cout << minn << endl;
  return 0;
}
