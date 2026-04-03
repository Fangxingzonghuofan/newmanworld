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
    int reverseBits(int n) {
        vector<int> num16;
        while (n!=0)
        {
            num16.push_back(n%16);
            n/=16;
        }
        for (int i = 0; i <8-num16.size(); i++)
        {
            num16.insert(num16.begin(),0);
        }
        int res=0;
        int val=16^7;//这里是异或不是乘方
        for(auto &i:num16){
            switch(i){
            case 1:
            i=8;
            break;
            case 2:
            i=4;
            break;
            case 3:
            i=12;
            break;
            case 4:
            i=2;
            break;
            case 5:
            i=10;
            break;
            case 7:
            i=14;
            break;
            case 8:
            i=1;
            break;
            case 10:
            i=5;
            break;
            case 11:
            i=13;
            break;
            case 12:
            i=3;
            break;
            case 13:
            i=11;
            break;
            case 14:
            i=7;
            break;
            case 15:
            break;
            default:
            break;
        }
        res+=i*val;
        val/=16;
    }  
    return res;                 
    }
};
//没招了写的是屎山代码，完全运行不对的那种，我的血泪，留着吧，不删了，下面给出非常老道的做法
class Solution {
public:
    int reverseBits(int n) {
        int res=0;
        for (int i = 0; i <32; i++)
        {
            res<<=1;
            res|=(n&1);
            n>>=1;
        }
        return res;
    }
};
