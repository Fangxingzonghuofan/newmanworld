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
    }//借用上一题逆波兰表达式求值
    int calculate(string s) {
        vector<string> eval;
        vector<char> fuhao;
        long long num=0;
        int flag=0;
        for(const auto &i:s){
            if (i == ' ') continue;
            if(i>='0'&&i<='9'){
                num=num*10+i-'0';
                flag=1;
            }
            else if(flag==1){
                eval.push_back(to_string(num));
                flag=0;
                num=0;
            }//为数字进栈
            if (i=='(')
            {
                fuhao.push_back(i);
            }
            else if(i==')'){
                while (!fuhao.empty() && fuhao.back()!='(')
                {
                    eval.emplace_back(string(1,fuhao.back()));
                    fuhao.pop_back();
                }
                fuhao.pop_back();
            }
            else if(i=='+'||i=='-'){
                while (!fuhao.empty()&&fuhao.back()!='(')
                {
                    eval.emplace_back(string(1,fuhao.back()));
                    fuhao.pop_back();
                }
                fuhao.push_back(i);
            }
            else if(i=='*'||i=='/'){
                while(!fuhao.empty()&&fuhao.back()!='('&&fuhao.back()!='+'&&fuhao.back()!='-'){
                    eval.emplace_back(string(1,fuhao.back()));
                    fuhao.pop_back();
                }
                fuhao.push_back(i);
            }
        }
        if(flag==1){
    eval.push_back(to_string(num));
}

        while(!fuhao.empty()){
            eval.emplace_back(string(1,fuhao.back()));
            fuhao.pop_back();
        }
        return evalRPN(eval);
    }
};//这里的代码问题频频而且通不过leetcode，及其复杂，所以我决定换一种方法
//我去 我完全是瞎子来的吧，题目里只有加减没有乘除啊啊，重写重写
class Solution {
public:
    int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        int sign = 1;

        int ret = 0;
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i++;
            } else if (s[i] == '+') {
                sign = ops.top();
                i++;
            } else if (s[i] == '-') {
                sign = -ops.top();
                i++;
            } else if (s[i] == '(') {
                ops.push(sign);
                i++;
            } else if (s[i] == ')') {
                ops.pop();
                i++;
            } else {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                ret += sign * num;
            }
        }
        return ret;
    }
};//密码的 写不出来 放弃了什么玩意，还真是活到老学到老，码的