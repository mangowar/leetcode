#include <iostream>
#include <vector>
#include <unordered_map>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<TreeNode*> curr_level = {root};
        vector<vector<int>> res;
        int flag = 0;
        while(!curr_level.empty()) {
            vector<int> buf;
            vector<TreeNode*> ptr_buf;
            for(TreeNode* ptr: curr_level) {
                buf.push_back(ptr->val);
                if(ptr->left)
                    ptr_buf.push_back(ptr->left);
                if(ptr->right)
                    ptr_buf.push_back(ptr->right);
            }
            curr_level = ptr_buf;
            if(flag) {
                vector<int> buf_reverse(buf.rbegin(), buf.rend());
                buf = buf_reverse;
            }
            res.push_back(buf);
            flag ^= 1;
        }
        return res;
    }
};