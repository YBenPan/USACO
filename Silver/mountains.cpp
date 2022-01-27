/*#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi = vector<int>;
using namespace std;
pair<int, int> a[100005];
int main()
{
  freopen("mountains.in", "r", stdin);
  freopen("mountains.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> a[i].first >> a[i].second;
  int tot = N;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      if (i != j)
        if (a[i].first - a[i].second >= a[j].first - a[j].second && a[i].first + a[i].second <= a[j].first + a[j].second) {tot--; break;}
  cout << tot << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi = vector<int>;
using namespace std;
pair<int, int> a[100005];
int pos[100005], neg[100005], rep[100005];
bool cmp(int a, int b)
{
  if (neg[a] == neg[b])
    return pos[a] > pos[b];
  return neg[a] < neg[b];
}
int main()
{
  freopen("mountains.in", "r", stdin);
  freopen("mountains.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i)
    {
      cin >> a[i].first >> a[i].second;
      pos[i] = a[i].first + a[i].second;
      neg[i] = a[i].first - a[i].second;
      rep[i] = i;
    }
  sort(rep, rep + N, cmp);
  int ans = 0;
  int maxx = 0;
  for (int i = 0; i < N; ++i)
    {
      if (pos[rep[i]] > maxx)
        {
          ans++;
          maxx = pos[rep[i]];
        }
    }
  cout << ans << endl;
  return 0;
}
