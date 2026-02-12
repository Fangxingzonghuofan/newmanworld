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
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size())
        {
            return false;
        }
        unordered_map<char,int> lettercount;
        for (int i = 0; i < s.size(); i++)
        {
            lettercount[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (!lettercount.count(t[i])||--lettercount[t[i]]<0)
            {
                return  false;
            }
        }
        return true;
    }
};
//上面是我根据昨天所学写的，下面是更加规范的写法
class Solution {
public:
    bool isAnagram(const string& s, const string& t) {//不用拷贝，不允许修改，更高效安全
        if (s.size() != t.size())
            return false;

        int count[26] = {0};//使用unordered-map有哈希开销，直接使用数组更简洁

        for (char c : s)//此处循环的改动很重要
            count[c - 'a']++;

        for (char c : t)
            if (--count[c - 'a'] < 0)//lettercount[c] 本身会自动插入默认值 0。
                return false;

        return true;
    }
};
