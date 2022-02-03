#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
struct node
{
  int type1, type2, type3;
};
int main()
{
  freopen("bcount.in", "r", stdin);
  freopen("bcount.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q;
  cin >> n >> q;
  int pre[100005][4];
  pre[0][1] = 0;
  pre[0][2] = 0;
  pre[0][3] = 0;
  int input;
  for (int i = 1; i <= n; ++i)
    {
      cin >> input;
      pre[i][1] = pre[i - 1][1];
      pre[i][2] = pre[i - 1][2];
      pre[i][3] = pre[i - 1][3];
      pre[i][input]++;
    }
  int a, b;
  for (int i = 0; i < q; ++i)
    {
      cin >> a >> b;
      int n1 = pre[b][1] - pre[a - 1][1];
      int n2 = pre[b][2] - pre[a - 1][2];
      int n3 = pre[b][3] - pre[a - 1][3];
      cout << n1 << " " << n2 << " " << n3 << endl;
    }
  return 0;
}
