#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void floodFill1(vector<vector<int>>& image, int sr, int sc, int color, int orig_color) {
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != orig_color)
            return;
        image[sr][sc] = color;
        floodFill1(image, sr-1, sc, color, orig_color);
        floodFill1(image, sr+1, sc, color, orig_color);
        floodFill1(image, sr, sc-1, color, orig_color);
        floodFill1(image, sr-1, sc+1, color, orig_color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        floodFill1(image, sr, sc, color,  image[sr][sc]);
        return image;
    }
};

int main() {
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    Solution s;
    s.floodFill(image, 1, 1, 2);
    return 0;
}