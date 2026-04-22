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
class WordDictionary {
    vector<WordDictionary*> children;
    bool isEnd;
    bool searchHelper(const string& word, int index, WordDictionary* node) {
        // 递归终止条件：到达单词末尾
        if (index == word.size()) {
            return node->isEnd;
        }
        
        char ch = word[index];
        
        if (ch == '.') {
            // 通配符 '.' 可以匹配任意字符
            // 尝试所有可能的子节点
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    // 递归搜索剩余的字符串
                    if (searchHelper(word, index + 1, node->children[i])) {
                        return true;
                    }
                }
            }
            return false;  // 所有可能的路径都失败
        } else {
            // 普通字符
            int idx = ch - 'a';
            if (node->children[idx] == nullptr) {
                return false;  // 字符不存在
            }
            // 递归搜索下一个字符
            return searchHelper(word, index + 1, node->children[idx]);
        }
    }
public:
    WordDictionary():children(26),isEnd(false) {}
    void addWord(string word) {
        WordDictionary *node=this;
        for(auto ch:word){
            ch-='a';
            if(node->children[ch]==nullptr) {
                node->children[ch]=new WordDictionary();
            } 
            node=node->children[ch];           
        }
        node->isEnd=true;
    }
    bool search(string word) {
        return searchHelper(word, 0, this);
    }
};
