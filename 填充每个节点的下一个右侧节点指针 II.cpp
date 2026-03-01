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
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public://注意如果next为nullptr，则不用做处理，这一题我没有思路，于是选择官方题解时间和空间最优算法
    void handle(Node*&last,Node*&p,Node*&nextstart){
        if (last)
        {
            last->next=p;
        }
        if (!nextstart)
        {
            nextstart=p;
        }
        last=p;
    }
    Node* connect(Node* root) {
        if (!root)
        {
            return nullptr;
        }
        Node *start=root;
        while (start)
        {
            Node*last=nullptr;
            Node*nextstart=nullptr;
            for (Node *p = start; p!=nullptr;p=p->next)
            {
                if (p->left)
                {
                    handle(last,p->left,nextstart);
                }
                if (p->right)
                {
                    handle(last,p->right,nextstart);
                }
            }
            start=nextstart;
        }
        return root;
    }
};