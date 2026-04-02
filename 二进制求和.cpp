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
    string addBinary(string a, string b) {
        int two=1;
        int A=0,B=0;
        int size=a.size();
        for (int i = size-1; i >= 0; i--)
        {
            A+=(a[i]-'0')*two;
            two*=2;
        }
        size=b.size();
        two=1;
        for (int i = size-1; i>=0; i--)
        {
            B+=(b[i]-'0')*two;
            two*=2;
        }
        A+=B;
        string res;
        while (A!=0&&A!=1)
        {
            res.push_back(A%2+'0');
            A/=2;
        }
        res.push_back(A+'0');
        reverse(res.begin(),res.end());
        return res;
    }
};//这个思路在数学上没问题，但是int会溢出，所以这个解法不推荐，正确解法是模拟二进制
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int as=a.size()-1;
        int bs=b.size()-1;
        int carry=0;//进位标识符
        while (as>=0||bs>=0||carry)
        {
            int sum=carry;
            if(as>=0) sum+=a[as--]-'0';
            if(bs>=0) sum+=b[bs--]-'0';
            res.push_back(sum%2+'0');
            carry=sum/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
