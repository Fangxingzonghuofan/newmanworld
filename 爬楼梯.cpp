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
    int climbStairs(int n) {
        if(n<1) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};//根据提示写出来的算法：提示是让我思考一下先前的步数
//于是我发现假如要到达第n阶台阶，第一种方法是从第n-1阶台阶迈一步到达，
//第二种方法是从第n-2阶台阶迈两步到达，于是有了这个递归算法，但是超出了时间限制
//接下来采取同样思路，但是不用递归转用迭代器
class Solution {
public:
    int climbStairs(int n) {
        int path2=1,path1=2,tmp;//path1,path2是指到下一阶台阶的距离，path2就是两级，path1指一级
        if(n==1) return path2;
        if(n==2) return path1;
        n=n-2;
        while (n>0)
        {
            tmp=path1;
            path1=path1+path2;
            path2=tmp;
            n--;
        }
        return path1;
    }
};