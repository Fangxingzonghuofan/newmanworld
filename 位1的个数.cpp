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
    int hammingWeight(int n) {
        int res=0;
        while (n>0)
        {
            if(n&1==1) res++;
            n>>=1;
        }
        return res;
    }
};