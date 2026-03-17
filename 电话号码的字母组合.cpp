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
    vector<string>mapping={
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> res;
    void backtrack(string &digits,int index,string &path){
        if(index==digits.size()) {
            res.push_back(path);
            return;
        }
        string letters=mapping[digits[index]-'0'];
        for(auto &l:letters)
        {
            path.push_back(l);
            backtrack(digits,index+1,path);
            path.pop_back();//回溯的精髓，如果没有这一步会污染后面的路径
        }
        return;
}
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return{};
        string path="";
        backtrack(digits,0,path);
        return res;
    }
};