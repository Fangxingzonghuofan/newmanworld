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
    int num=0;
    int sum=0;
    int sumNumbers(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        else num=num*10+root->val;
        if (!root->left&&!root->right)
        {
            sum+=num;
        }
        sumNumbers(root->left);
        sumNumbers(root->right);
        return sum;
    }
};//这里的sum和num使用的是全局变量导致结果出错
class Solution{
public:
    int sumNumbers(TreeNode *root){
        return dfs(root,0);
    }
    int dfs(TreeNode *root,int cur){
        if(!root) return 0;
        cur=cur*10+root->val;
        if (!root->left&&!root->right)
        {
            return cur;
        }
        return dfs(root->left,cur)+dfs(root->right,cur); 
    }
};