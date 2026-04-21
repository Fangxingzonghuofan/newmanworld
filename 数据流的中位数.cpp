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
class MedianFinder {
    int count;
    priority_queue<int> pq;
public:
    MedianFinder() {
        count=0;
    }
    void addNum(int num) {
        pq.push(num);
        count++;
    }
    double findMedian() {
        int n=(count+1)/2-1;
        while (n>0)
        {
            pq.pop();
        }
        double mid=pq.top();
        pq.pop();
        if(count%2==1) mid=(mid+pq.top())/2;
        return mid;
    }
};//不仅会超出时间限制，而且思路还是错误的，因为每次都pop掉一半的元素没有恢复
class MedianFinder {
    int total;
    priority_queue<int> bigLeftq;
    priority_queue<int,vector<int>,greater<int>> samllRightq;
public:
    MedianFinder() {
        total=0;
    }
    void addNum(int num) {
        bigLeftq.push(num);
        total++;
        samllRightq.push(bigLeftq.top());
        bigLeftq.pop();
        if(total%2==1){
            bigLeftq.push(samllRightq.top());
            samllRightq.pop();
        }
    }
    double findMedian() {
        double mid=bigLeftq.top();//建议使用 static_cast<double>进行显式类型转换
        if(total%2==0) mid=(mid+samllRightq.top())/2;
        return mid;
    }
};//依旧双堆法，很不错，很天才的思路啊啊啊