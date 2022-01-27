#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
bool cmp(const pair<double, int> &a, const pair<double, int> &b)
{
  return a.first > b.first;
}
int main()
{
  freopen("homework.in", "r", stdin);
  freopen("homework.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  multiset<int> num;
  LL suf[100005], a[100005], sum = 0;
  for (int i = 1; i <= n; ++i)
    {
      cin >> a[i];
      if (i > 1) {num.insert(a[i]); sum += a[i];}
    }
  vector<pair<double, int> > ans;
  for (int i = 2; i <= n - 1; ++i)
    {
      double avg = (double)(sum - *num.begin()) / (n - i);
      ans.push_back({avg, i - 1});
      //cout << avg << endl;
      num.erase(num.find(a[i]));
      sum -= a[i];
    }
  sort(ans.begin(), ans.end(), cmp);
  double maxx = ans[0].first;

  for (auto it = ans.begin(); it != ans.end(); ++it)
    {
      if ((*it).first == maxx)
        {
          if ((*next(it)).first == maxx)
            cout << (*it).second << " ";
          else cout << (*it).second << endl;
        }
      else break;
      }
  return 0;
}
