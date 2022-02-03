#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n;
double curx;
struct Point 
{
    LL x, y; int segindex;
};
struct Segment
{
    Point p, q; int index;
}; 
//overload operator for points. Sort by x 
bool operator< (Point p1, Point p2)
{
    return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x; 
}
//Get y position of a segment at x = curx
double getPos(Segment s)
{
    if (s.q.x == s.p.x) return s.p.y;
    return s.p.y + (s.q.y - s.p.y) * (curx - s.p.x) / (s.q.x - s.p.x);
}
//tests for intersection:
int sign(LL x)
{
    //returns the sign
    if (x == 0) return 0; 
    else return x < 0 ? -1 : + 1; 
}
int operator* (Point p1, Point p2) 
{
    //cross product 
    return sign(p1.x * p2.y - p1.y * p2.x);
}
Point operator- (Point p1, Point p2)
{
    Point p = {p1.x - p2.x, p1.y - p2.y};
    return p;
}
bool intersect(Segment &s1, Segment &s2)
{
    Point &p1 = s1.p, &q1 = s1.q, &p2 = s2.p, &q2 = s2.q; 
    return ((q2 - p1) * (q1 - p1)) * ((q1 - p1) * (p2 - p1)) >= 0 && ((q1 - p2) * (q2 - p2)) * ((q2 - p2) * (p1 - p2)) >= 0; 
}
//overload operator for segments. Sort by y of segments when at x = curx
bool operator< (Segment s1, Segment s2)
{
    if (s1.index == s2.index) return false;
    return getPos(s1) < getPos(s2);
}
bool operator== (Segment s1, Segment s2) 
{
    return s1.index == s2.index;
}
vector<Point> vP;
vector<Segment> vS;
int main()
{
    freopen("cowjump.in", "r", stdin);
    freopen("cowjump.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    //Read and initialize points and segments
    for (int i = 0; i < n; ++i)
    {
        Segment input;
        cin >> input.p.x >> input.p.y >> input.q.x >> input.q.y;
        input.index = i; 
        input.p.segindex = i; 
        input.q.segindex = i;
        vS.pb(input);
        vP.pb(input.p);
        vP.pb(input.q);
    }
    sort(vP.begin(), vP.end());
    //cout << vP.size() << endl;
    //initialize set to store all active segments
    
    set<Segment> actives;
    int ans1, ans2;
    for (int i = 0; i < 2 * n; ++i)
    {
        ans1 = vP[i].segindex; 
        curx = vP[i].x; 
        Point cur = vP[i];
        auto it = actives.find(vS[ans1]); // find if current segment is active
        if (it != actives.end()) //It is active and we reached the ending point
        {
            //find neighbors
            auto prev = it, next = it; 
            next++;
            if (next != actives.end() && prev != actives.begin()) //if there are two valid neighbors
            {
                prev--; //get the neighbor below
                if (intersect(vS[prev->index], vS[next->index])) //if neighbors do intersect
                {
                    ans1 = prev->index; ans2 = next->index;
                    break;
                }    
            }
            actives.erase(it);
        }
        else
        {
            //starting point. Make the segment active
            auto it1 = actives.lower_bound(vS[ans1]); //locate where to put the new segment
            //check for intersection of neighbors
            if (it1 != actives.end() && intersect(vS[it1 -> index], vS[ans1]))
            {
                ans2 = it1 -> index; break;
            }
            if (it1 != actives.begin())
            {
                it1--;
                if (intersect(vS[it1 -> index], vS[ans1]))
                {
                    ans2 = it1-> index; break;
                }
            }
            actives.insert(vS[ans1]);
        }
    }
    if (ans1 > ans2) swap(ans1, ans2); 
    int ans2_count = 0;
    for (int i = 0; i < n; ++i)
    {
        //count how many segments vS[ans2] intersects
        if (vS[i].index != ans2 && intersect(vS[i], vS[ans2])) ans2_count++;
    }
    //if ans2 intersect multiple, then output ans2, else output ans1
    cout << (ans2_count > 1 ? ans2 + 1 : ans1 + 1) << endl;
    return 0;
}