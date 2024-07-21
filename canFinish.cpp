#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
        unordered_map<int, vector<int>> pr;
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(const auto& i: prerequisites) {
            pr[i[0]].push_back(i[1]);
        }
        for(int i = 0; i < numCourses; i++) {
            if(pr.find(i) == pr.end() || pr[i].empty())
                continue;
            unordered_set<int> way;
            if(!dfs(i, way))
                return false;
        }
        return true;
    }
    bool dfs(int point, unordered_set<int> way) {
        if(way.contains(point)) 
            return false;
        if(pr.find(i) == pr.end() || pr[i].empty())
            return true;
        way.insert(point);
        for(int i: pr[point]) {
            if(!dfs(i, way))
                return false;
        }
        pr[point].clear();
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> prerequisites = {{1,0},{2,6},{1,7},{6,4},{7,0},{0,5}};
    s.canFinish(2, prerequisites);
    return 0;
}