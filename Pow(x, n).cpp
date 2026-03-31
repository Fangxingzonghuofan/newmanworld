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
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(n==0) return 1;
        long N=n;
        double X=x;
        //if(n<0)  N=-n;这里也要防止溢出，故N定义为long长整形,但是依旧会报错
        if(n<0)  N=-N;//原因是-n就已经超出了，故改为-N;
        long pow=1;
        while (pow<=N/2)//借用上一题的经验，使用/防止溢出
        {
            x*=x;
            pow+=pow;
        }
        x*=myPow(X,N-pow);
        return n<0?1/x:x;
    }
};//我自己思考出来的算法，但是这个算法其实并不完美，下面给出更好的算法
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double res = 1;
        while (N > 0) {
            if (N & 1) res *= x;  // 当前位是1
            x *= x;               // 平方
            N >>= 1;              // 右移一位
        }
        return res;
    }
};//这个方法简直太天才了！！！二进制无敌！！！