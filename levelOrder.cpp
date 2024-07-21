#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            vector<int> buf;
            int size = nodes.size();
            for(int i = 0; i < size; i++) {
                buf.push_back(nodes.front()->val);
                if(nodes.front()->left)
                    nodes.push(nodes.front()->left);
                if(nodes.front()->right)
                    nodes.push(nodes.front()->right);
                nodes.pop();
            }
            res.push_back(buf);
        }
        return res;
    }
};