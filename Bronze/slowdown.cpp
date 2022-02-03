#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    freopen("slowdown.in", "r", stdin);
    freopen("slowdown.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    priority_queue<int, vi, greater<int>> t, d;
    char c;
    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> c >> x;
        if (c == 'T') t.push(x); else d.push(x);
    }
    double dist = 0, time = 0;
    int speed = 1;
    d.push(1000);
    while (!d.empty() || !t.empty())
    {
        /*
        int next_time = -1;
        if (!t.empty()) next_time = t.top();
        int next_dist = 1000; 
        if (!d.empty()) next_dist = d.top();*/
        if (d.empty() || (!d.empty() && !t.empty() && (t.top() - time) < speed * (d.top() - dist)))
        {
            dist += (t.top() - time) / (double)(speed);
            time = t.top();
            t.pop();
        }
        else
        {
            time += (d.top() - dist) * speed;
            dist = d.top();
            d.pop();
        }
        speed++;
    }
    double decimal = time - (int)time;
    if (decimal < 0.5) cout << (int)(time) << endl;
    else cout << (int)(time) + 1 << endl;
    //cout << fixed << setprecision(5) << time << endl;
    return 0;
}