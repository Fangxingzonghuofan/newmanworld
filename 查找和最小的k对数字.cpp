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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if(nums1.empty()||nums2.empty()||k==0) return res;
        auto cmp=[&nums1,&nums2](const pair<int,int>& a,const pair<int,int> &b){
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };//匿名函数,其中[]是捕获列表，决定函数cmp能否使用外部变量，此处为空，则不能
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> smallq(cmp);
        /*decltype获得函数cmp的类型
        (cmp)意思是使用函数cmp来初始化这个堆*/
        for (int i = 0; i <k&&i<nums1.size(); i++)
        {
            smallq.emplace(i,0);
        }
        while (k-->0&&!smallq.empty())
        {
            auto top=smallq.top();
            res.push_back({nums1[top.first],nums2[top.second]});//插在末尾，不像emplace函数可以指定插入位置
            //上一句最标准的写法：res.emplace_back(initializer_list<int>{nums1[i], nums2[j]});
            smallq.pop();
            if(top.second+1<nums2.size()) smallq.emplace(top.first,top.second+1);
        }        
        return res;
    }
};//这一版代码还可以在细节上有一些小优化：
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k == 0) return res;

        auto cmp = [&nums1, &nums2](const pair<int,int>& a, const pair<int,int>& b) {
            return nums1[a.first] + nums2[a.second] >
                   nums1[b.first] + nums2[b.second];
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        // ✅ 正确初始化
        for (int i = 0; i < nums1.size() && i < k; i++) {
            pq.emplace(i, 0);
        }

        while (k-- > 0 && !pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();

            res.push_back({nums1[i], nums2[j]});

            // ✅ 防越界
            if (j + 1 < nums2.size()) {
                pq.emplace(i, j + 1);
            }
        }

        return res;
    }
};