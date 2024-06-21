#include <iostream>
#include <vector>
#include <unordered_map>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr_l = head, *ptr_r = head;
        for(int i = 0; i < n; i++){
            ptr_r = ptr_r->next;
        }
        if(!ptr_r)
        {
            return head->next;
        }
        while(ptr_r->next) {
            ptr_r = ptr_r->next;
            ptr_l = ptr_l->next;
        }
        ptr_l->next = ptr_l->next->next;
        return head;
    }
};

int main() {
    string s = "qwerty";
    string t = "qwerty1";
    unordered_map<char, int> s_m;
    unordered_map<char, int> t_m;
    for(auto c: s) {
        s_m[c]++;
    }
    for(auto c: t) {
        t_m[c]++;
    }
    cout << (s_m == t_m) << endl;
    return 0;
}