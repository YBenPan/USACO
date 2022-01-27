#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int b[200005], bit[200005] = {0}, last[200005], n; 
bool visited[200005]; 
void update(int index, int val)
{
    index++; 
    while (index <= n)
    {
        bit[index] += val;
        index += (index & (-index)); 
    }
}
int get(int index)
{
    int sum = 0;
    index++; 
    while (index > 0)
    {
        sum += bit[index]; 
        index -= (index & (-index)); 
    }
    return sum; 
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    memset(last, -1, sizeof(last)); 
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> b[i]; 
    LL cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        //get range
        bool stop = false;
        //Binary indexed tree
        if (last[b[i]] != -1) 
        {
            update(last[b[i]], -1); 
            stop = true;
        }
        int l = last[b[i]] + 1; 
        last[b[i]] = i; 
        update(i, 1); 
        if (stop)
        {
            cnt += (get(i - 1) - get(l - 1)); 
            //cout << (get(i - 1) - get(l - 1)) << endl;
        }
        else 
        {
            cnt += get(i - 1); 
            //cout << get(i - 1) << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}