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
    TreeNode *tail;
    void flatten(TreeNode* root) {
        if (!root)
        {
            return;
        }
        tail=root;
        while (tail->left)
        {
            tail=tail->left;
        }
        makeflatten(root);
        return;
    }
    void makeflatten(TreeNode* root) {
        if (!root)
        {
            return;
        }
        if (root->left)
        {
            if (root->right)
            {
                tail->right=root->right;
            }
            root->right=root->left;
            root->left=nullptr;
            tail=root->right;
            while (tail->right)
            {
                tail=tail->right;
            }
        }
        makeflatten(root->left);
        makeflatten(root->right);
        return;
    }
};//以上是我自己写的，直接超时了，下面是gpt给我的用我的思路写的标准答案，好了我宣布ai比我厉害一万倍
class Solution {
public:
    void flatten(TreeNode* root) {
        makeflatten(root);
        return;
    }
    TreeNode* makeflatten(TreeNode* root) {
        if (!root)
        {
            return nullptr;
        }
        TreeNode *lefttail=makeflatten(root->left);
        TreeNode *righttail=makeflatten(root->right);
        if (lefttail)
        {
            lefttail->right=root->right;
            root->right=root->left;
            root->left=nullptr;
        }
        if (righttail)
        {
            return righttail;
        }
        if (lefttail)
        {
            return lefttail;
        } 
        return root;
    }
};//心好累，这一题O(1)解法思路倒是简单我想出来了，但是用递归写法写出来难度简直堪比脑王，最后让gpt给我写出来了，我自己真的超崩溃，在这一题上写了快俩小时

//二刷了一次，这次思考的比较成熟了，这题其实不难的，主要是还没有理解好递归对于二叉树的拆解，其实这一题之前觉得难是因为想的太多太复杂了，还是基础不牢吧
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *leftTail=root->left;
        if(!leftTail) return;
        while(leftTail->right) leftTail=leftTail->right;
        leftTail->right=root->right;
        root->right=root->left;
        root->left=nullptr;
    }
};
//偷偷记录一下，最近在准备agent开发,一起加油，现在也在尝试用python解题，来吧，走起！
