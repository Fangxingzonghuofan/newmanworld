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
class MinStack {
    stack<int> xstack;
    stack<int> minstack;
public:
    MinStack() {
        minstack.push(INT_MAX);
    }
    
    void push(int val) {
        xstack.push(val);
        minstack.push(min(minstack.top(),val));
    }
    
    void pop() {
        xstack.pop();
        minstack.pop();
    }
    
    int top() {
        return xstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};//好天才的思路，使用一个辅助栈记录每一个栈顶元素对应的栈最小值。
//下面将栈改用vector <int>可能会更高效
class MinStack {
    vector<int> x;
    vector<int> Min;
public:
    MinStack() {
        Min.push_back(INT_MAX);
    }
    
    void push(int val) {
        x.push_back(val);
        Min.push_back(min(Min.back(),val));
    }
    
    void pop() {
        x.pop_back();
        Min.pop_back();
    }
    
    int top() {
        return x.back();
    }
    
    int getMin() {
        return Min.back();
    }
};//果然使用vector<int> 之后 大大减少了用时和空间
