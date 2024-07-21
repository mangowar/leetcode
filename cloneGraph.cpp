#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        unordered_map<Node*, Node*> old_new;
        queue<Node*> q;
        q.push(node);
        old_new[node] = new Node(q.front()->val);
        while(!q.empty()) {
            Node* curr_node = old_new[q.front()];
            for(auto& ptr: q.front()->neighbors) {
                if(old_new.find(ptr) != old_new.end()) {
                    old_new[ptr] = new Node(ptr->val);
                }
                curr_node->neighbors.push_back(old_new[ptr]);
                if(old_new[ptr]->neighbors.empty())
                    q.push(old_new[ptr]);
            }
            q.pop();
        }
        return old_new[node];
    }
};