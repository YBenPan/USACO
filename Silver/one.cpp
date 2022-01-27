#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
set<int> s[100005]; 
int a[100005]; 
int pa[100005], ht[100005]; 
int get(int x)
{
    return x == pa[x] ? x : get(pa[x]); 
}
void merge(int a, int b)
{
    a = get(a); b = get(b); 
    if (a == b) return; 
    if (ht[a] < ht[b]) swap(a, b); 
    pa[b] = a; 
    ht[a] += ht[b]; 
    s[a].insert(s[b].begin(), s[b].end()); 
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k; 
    for (int i = 1; i <= n; ++i) {a[i] = i; s[i].insert(i);}
    int in1, in2, t;
    for (int i = 0; i < k; ++i)
    {
        cin >> in1 >> in2; 
        s[a[in1]].insert(in2); 
        s[a[in2]].insert(in1); 
        t = a[in1];
        a[in1] = a[in2]; 
        a[in2] = t;
    }
    for (int i = 1; i <= n; ++i)
    {
        pa[i] = i; 
        ht[i] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != i) merge(a[i], i); 
    }
    for (int i = 1; i <= n; ++i)
    {
        int loc = get(i); 
        cout << s[loc].size() << endl;
    }
    return 0;
}