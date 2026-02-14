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
    bool isHappy(int n) {
        unordered_map<int,int> ans;//这里可以使用unordered_set<int> st
        int next=n;
        int count=1;
        while (next!=1)
        {
            if (ans.count(next))
            {
                return false;
            }
            else{
                ans[next]=++count;
            }
            int sum=0;
            while (next!=0)
            {
                sum+=(next%10)*(next%10);
                next/=10;
            }
            next=sum;
        }
        return true;
    }        
};
/*| 函数           | 用在谁     | 作用     |
| ------------ | ------- | ------ |
| push_back    | vector  | 插入已有对象 |
| emplace_back | vector  | 原地构造   |
| insert       | set/map | 插入对象   |
| emplace      | set/map | 原地构造   |*/
