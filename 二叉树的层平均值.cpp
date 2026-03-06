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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        queue<int> nodedepth;
        unordered_map<int,int> nodenum;
        unordered_map<int,long> nodeSum;
        int depth=-1;
        nodeQueue.push(root);
        nodedepth.push(0);
        while (!nodeQueue.empty())
        {
            TreeNode*node=nodeQueue.front();nodeQueue.pop();
            depth=nodedepth.front();nodedepth.pop();
            if (node)
            {
                nodenum[depth]++;
                nodeSum[depth]+=node->val;
                nodeQueue.push(node->left);
                nodeQueue.push(node->right);
                nodedepth.push(depth+1);
                nodedepth.push(depth+1);
            }
        }
        vector<double> ans;
        for (int i = 0; i <depth; i++)
        {
            double arr=(double)nodeSum[i]/nodenum[i];//这里需要强制类型转换
            ans.push_back(arr);
        }
        return ans;
    }
};//这是我根据上一题二叉树的右视图而设计的方法（空间消耗很大），有更优的方法
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        vector<double> ans;

        while(!q.empty())
        {
            int size=q.size();
            double sum=0;

            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();

                sum+=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ans.push_back(sum/size);
        }

        return ans;
    }
};
