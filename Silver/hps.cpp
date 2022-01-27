#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
  int n;
	cin >> n;
	int s[100005], p[100005], h[100005];
	char ch;
	for (int i = 1; i <= n; ++i)
	{
		cin >> ch;
		s[i] = s[i - 1];
		p[i] = p[i - 1];
		h[i] = h[i - 1];
		if (ch == 'H') h[i]++;
    else if (ch == 'P') p[i]++;
    else s[i]++;
	}
  int ans = 0;
  for (int i = 0; i < n; ++i)
  {
    int cnt = max(h[i], max(p[i], s[i])) + max(h[n] - h[i], max(p[n] - p[i], s[n] - s[i]));
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}