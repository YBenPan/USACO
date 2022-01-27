#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
int main()
{
  ifstream fin("haybales.in");
  ofstream fout("haybales.out");
  ios_base::sync_with_stdio(false);
  fin.tie(NULL);
  fout.tie(NULL);
  int N, Q;
  fin >> N >> Q;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) fin >> a[i];
  sort(a.begin(), a.end());
  int q1, q2;
  for (int i = 0; i < Q; ++i)
    {
      fin >> q1 >> q2;
      vector<int>::iterator low = lower_bound(a.begin(), a.end(), q1);
      vector<int>::iterator up = upper_bound(a.begin(), a.end(), q2);
      fout << (up - low) << endl;
    }
  return 0;
}
