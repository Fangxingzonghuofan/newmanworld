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
    unordered_map<int,TreeNode*> fa;
    unordered_map<int,bool> visit;
    void dfs(TreeNode* root){
        if(root->left){
            fa[root->left->val]=root;
            dfs(root->left);
        }
        if (root->right)
        {
            fa[root->right->val]=root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val]=nullptr;
        dfs(root);
        while (p)
        {
            visit[p->val]=true;
            p=fa[p->val];
        }
        while (q)
        {
            if (visit[q->val]) return q;
            q=fa[q->val];
        }
        return nullptr;
    }
};//太难了，自己根本就不会写，不过我觉得用哈希表的方法真的很好
//下面贴出递归的方法
class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        } 
        return lson || rson || (root->val == p->val || root->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};
