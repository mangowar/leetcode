#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<pair<int, int>> points;
    int maxX, minX, x , y;
    cin >> x >> y;
    points.insert({x, y});
    maxX = minX = x;

    for (int i = 1; i < n; i++) 
    {
        cin >> x >> y;
        maxX = max(maxX, x);
        minX = min(minX, x);
        points.insert({x, y});
    }
    int s = maxX + minX;

    for(const auto p: points)
    {
        if(!points.count({s - p.first, p.second}))
        {
            cout << "false\n";
            return 0;
        }
    }
    cout << "true\n";
    return 0;
}