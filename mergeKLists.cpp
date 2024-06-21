#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new(ListNode);
        ListNode* end = res;
        while(!lists.empty()) {
            ListNode* ptr = lists[0];
            int idx = 0;
            for(int i = 1; i < lists.size(); i++) {
                if(lists[i]->val < ptr->val) {
                    ptr = lists[i];
                    idx = i;
                }
            }
            end->next = ptr;
            end = end->next;
            end->next = nullptr;
            lists[idx] = lists[idx]->next;
            if(!lists[idx]) {
                swap(lists[idx], lists.back());
                lists.pop_back();
            }
        }
        ListNode* del = res;
        res = res->next;
        delete(del);
        return res;
    }
};