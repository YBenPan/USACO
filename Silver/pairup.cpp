#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
bool cmp(const pi &a, const pi &b)
{
    return a.second < b.second;
}
int main()
{
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    vector<pi> cow(N);
    for (int i = 0; i < N; ++i) cin >> cow[i].first >> cow[i].second;
    sort(cow.begin(), cow.end(), cmp);
    int i = 0, j = N - 1, maxx = 0;
    while (i <= j)
    {
        if (i == j)
        {
            maxx = max(2 * cow[i].second, maxx);
            break;
        }
        int req = cow[i].first;
        while (req > 0 && i != j)
        {
            maxx = max(maxx, cow[i].second + cow[j].second);
            if (req >= cow[j].first) 
            {
                req -= cow[j].first;
                cow[j].first = 0;
                j--;
            }
            else
            {
                cow[j].first -= req;
                req = 0;
            }
            //cout << i << " " << j << " " << req << endl;
        }
        if (i == j) 
        {
            if (req > 0) maxx = max(maxx, cow[i].second + cow[j].second);
            break;
        }
        i++;
    }
    cout << maxx << endl;
    return 0;
}