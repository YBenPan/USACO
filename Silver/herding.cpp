#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
  freopen("herding.in", "r", stdin);
  freopen("herding.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  /*int a = 1;
  for (int i = 1; i <= 105; ++i)
    a = (a * 9) % 1000;
  cout << a << endl;*/
  int n, input;
  cin >> n;
  int a[100005];
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  int minn = 0, maxx;
  maxx = max(a[n - 1] - a[1], a[n - 2] - a[0]) - (n - 2);
  if (a[n - 2] - a[0] + 1 == n - 1 && a[n - 1] - a[n - 2] > 2) minn = n - 2;
  else if (a[n - 1] - a[1] + 1 == n - 1 && a[1] - a[0] > 2) minn = n - 2;
  else
  {
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
      while (j < n && a[j] - a[i] <= n - 1) j++;
      minn = max(minn, j - i);
    }
  }
  cout << n - minn << endl;
  cout << maxx << endl;
  return 0;
}