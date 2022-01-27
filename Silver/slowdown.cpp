#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
vector<double> t, d;
int main()
{
    freopen("slowdown.in", "r", stdin);
    freopen("slowdown.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    char ch;
    double num;
    for (int i = 0; i < n; ++i)
    {
        cin >> ch >> num; 
        if (ch == 'T') t.pb(num); 
        else d.pb(num); 
    }
    d.pb(1000.0); 
    sort(t.begin(), t.end());
    sort(d.begin(), d.end()); 
    double tot = 0, cur = 0, time = 0, s = 1;
    int i = 0, j = 0; // keeps track of t 
    while (i < d.size() || j < t.size())
    {
        if (i == d.size())
        {
            double next_loc = cur + (t[j] - time) / s;
            time = t[j++]; 
            cur = next_loc; 
            s++; 
            continue;
        }
        if (j == t.size())
        {
            time += (d[i] - cur) * s; 
            cur = d[i++]; 
            s++;
            continue;
        }
        double next_loc = cur + (t[j] - time) / s;
        if (next_loc < d[i])
        {
            time = t[j++]; 
            cur = next_loc; 
            s++; 
        } 
        else
        {
            time += (d[i] - cur) * s; 
            cur = d[i++]; 
            s++;
        }
    }
    cout << (LL)round(time) << endl;
    return 0;
}