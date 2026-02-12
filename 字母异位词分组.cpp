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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for (string &str:strs)
        {
            string key=str;
            sort(key.begin(),key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> res;
        for (auto  i = mp.begin(); i !=mp.end(); i++)
        {
            res.emplace_back(i->second);
        }
        return res;
    }
};//emplace_back与之前学过的push_back类似