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
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> ch2str;
        unordered_map<string,char>str2ch;
        vector<string> words;
        istringstream SS(s);
        string word;
        while (SS>>word)
        {
            words.push_back(word);
        }
        if (words.size()!=pattern.size())
        {
            return false;
        }
        for (int i = 0; i < pattern.size(); i++)
        {
            char c=pattern[i];
            string w=words[i];
            if ((ch2str.count(c)&&ch2str[c]!=w)||(str2ch.count(w)&&str2ch[w]!=c))
            {
                return false;
            }
            ch2str[c]=w;
            str2ch[w]=c;
        }
        return true;
        
    }
};
