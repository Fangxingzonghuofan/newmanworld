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
    int candy(vector<int>& ratings) {
        int size=ratings.size();
        int kidGets[size];
        kidGets[0]=1;
        for (int i = 1; i < size; i++)
        {
            if(ratings[i]>ratings[i-1]) kidGets[i]=kidGets[i-1]+1;
            else kidGets[i]=1;
        }
        for(int i=size-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1]) kidGets[i]=max(kidGets[i],kidGets[i+1]+1);
        }
        int sum=0;
        for (int i = 0; i <size; i++)
        {
            sum+=kidGets[i];
        }
        return sum;
    }
};//空间复杂度为O(n)的算法，但是还可以继续优化，有空间复杂度为O(1)的算法，看不太懂，但是贴出来
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int up = 0, down = 0, peak = 0;
        int res = 1;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                up++;
                peak = up;
                down = 0;
                res += 1 + up;
            }
            else if (ratings[i] == ratings[i-1]) {
                up = down = peak = 0;
                res += 1;
            }
            else {
                down++;
                up = 0;
                res += 1 + down;
                if (down > peak) res -= 1;
            }
        }
        return res;
    }
};