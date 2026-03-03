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
    int maxSum=INT_MIN;
    int maxgain(TreeNode *node){
        if (!node)
        {
            return 0;
        }
        int leftgain=max(maxgain(node->left),0);
        int rightgain=max(maxgain(node->right),0);
        int newPath=node->val+leftgain+rightgain;
        maxSum=max(maxSum,newPath);
        return node->val+max(leftgain,rightgain);
        
    }
    int maxPathSum(TreeNode* root) {
        maxgain(root);
        return maxSum;
    }
};//这一题毫无思路，好难啊，这个二叉树加递归，学的我有点掉头，这是官方题解