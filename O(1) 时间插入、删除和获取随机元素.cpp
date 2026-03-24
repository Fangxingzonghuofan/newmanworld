#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdlib>  // 包含rand()函数
#include <ctime>   

using namespace std;
class RandomizedSet {
    unordered_map<int,int> valToindex;
    vector<int> nums;
public:
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        if(valToindex.count(val)) return false;
        valToindex[val]=nums.size();
        nums.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!valToindex.count(val)) return false;
        int last=nums.back();
        nums[valToindex[val]]=last;
        valToindex[last]=valToindex[val];
        nums.pop_back();
        valToindex.erase(val);
        return true;//这里是重点，将最后一位与目标位互换再进行pop即可实现O(1)时间的删除操作
    }
    
    int getRandom() {
        int index=rand()%nums.size();
        return nums[index];
    }
};