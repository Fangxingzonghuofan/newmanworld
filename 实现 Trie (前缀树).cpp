#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;
class Trie {
    vector<Trie*> children;
    bool isEnd;
public:
    Trie() {
        children.resize(26);
        isEnd=false;
    }
    void insert(string word) {
        Trie *node=this;
        for(auto i:word){
            i-='a';
            if(node->children[i]==nullptr) node->children[i]=new Trie();
            node=node->children[i];
        }
        node->isEnd=true;
    }
    bool search(string word) {
        Trie *node=this;
        for(auto i:word){
            i-='a';
            if(node->children[i]==nullptr) return false;
            node=node->children[i];
        }
        if(!node->isEnd) return false;//刚刚这里犯了一个小错误
        return true;
    }
    bool startsWith(string prefix) {
        Trie *node=this;
        for(auto i:prefix){
            i-='a';
            if(node->children[i]==nullptr) return false;
            node=node->children[i];
        }
        return true;
    }
};