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
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty())
        {
            return 0;
        }
        sort(points.begin(),points.end(),[](const vector<int>& u,const vector<int>& v)
        {
            return u[1]<v[1];
        });/*
        也可以写成普通函数
        bool cmp(const vector<int>& u, const vector<int>& v)
{
    return u[1] < v[1];
}

sort(points.begin(), points.end(), cmp);
        */
        int pos=points[0][1];
        int ans=1;
        for (const vector<int>& i :points)
        {
            if (i[0]>pos)
            {
                pos=i[1];
                ans++;
            }
        }
        return ans;
    }
};