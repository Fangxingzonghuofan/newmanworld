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
    int evalRPN(vector<string>& tokens) {
        vector <int> ans_stack;
        for(auto &i:tokens){//这里使用const auto &更加规范
            if (i!="+"&&i!="/"&&i!="*"&&i!="-")
            {
                ans_stack.push_back(stoi(i));
            }
            else if (ans_stack.size()<2) return 0;
            else {
                int ans=ans_stack.back();
                ans_stack.pop_back();
                if (i=="+")
                {
                    ans=ans_stack.back()+ans;
                }
                else if (i=="-")
                {
                    ans=ans_stack.back()-ans;
                }
                else if (i=="*")
                {
                    ans=ans_stack.back()*ans;
                }
                else if (i=="/")
                {
                    ans=ans_stack.back()/ans;
                }
                ans_stack.pop_back();
                ans_stack.push_back(ans);
            }
        }
        return ans_stack.back();
    }
};
