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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool is1,is2;
        if (p==nullptr&&q==nullptr)
        {
            return true;
        }
        else if (p==nullptr||q==nullptr||p->val!=q->val)
        {
            return false;
        }
        is1=isSameTree(p->left,q->left);
        is2=isSameTree(p->right,q->right);
        return (is1&&is2);
    }
};