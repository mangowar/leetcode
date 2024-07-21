#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> child;
    bool isLast = false;
};

class Trie {
public:
    Trie() {
        node = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = node;
        for(char c: word) {
            if(!curr->child.contains(c))
                curr->child[c] = new(TrieNode);
            curr = curr->child[c];
        }
        curr->isLast = true;
    }
    
    bool search(string word) {
        TrieNode* curr = node;
        for(char c: word) {
            if(!curr->child.contains(c))
                curr = curr->child[c];
        }
        return curr->isLast;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = node;
        for(char c: prefix) {
            if(!curr->child.contains(c))
                curr = curr->child[c];
            else
                return false;
        }
        return true;
    }
private:
    TrieNode* node;
};

int main() {
    Trie t;
    t.insert("apple");
    t.search("apple");
    return 0;
}
