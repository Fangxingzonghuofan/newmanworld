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
    priority_queue<int> pq;
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        if(k<=0) return w;
        int p=profits.size();
        for(int i=0;i<p;i++){
            if(w>=capital[i]){
                pq.push(profits[i]);
                capital[i]=INT_MAX;
            }
        }
        if(pq.empty()) return w;
        w+=pq.top();
        pq.pop();
        k--;
        w=findMaximizedCapital(k,w,profits,capital);
        return w;
    }
};//IPO困难题，暴力解法超出时间限制了，但是思路是对的，下面进行修改
class Solution {
    int partition(int l, int r, vector<int>& profits, vector<int>& capital){
        int i=l+rand()%(r-l+1);//此处是r-l+1!!,不是r-l
        swap(capital[i],capital[r]);
        swap(profits[i],profits[r]);
        int povit=capital[r];
        i=l;
        for (int j = l; j < r; j++)
        {
            if(capital[j]<povit)
            {
                swap(capital[i],capital[j]);
                swap(profits[i],profits[j]);
                i++;
            }
        }
        swap(capital[i], capital[r]);
        swap(profits[i], profits[r]);
        //写的时候居然漏了这一步！
        return i;
    }
    void quicksort(int l, int r, vector<int>& profits, vector<int>& capital){
        if(l>=r) return;
        int p=partition(l,r,profits,capital);
        quicksort(l,p-1,profits,capital);
        quicksort(p+1,r,profits,capital);
    }
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        int size=capital.size();
        //在这里对cpatial使用快速排序，同时映射到profits上
        //昨天刚学的快排写法，今天试一下嘿嘿
        quicksort(0,size-1,profits,capital);//我服了，刚刚写的时候一直写的(0,size-1,profits,capital)，导致运行结果一直出错，小细节啊啊啊！！！
        int i=0;
        while (k>0)
        {
            while (i<size&&w>=capital[i])
            {
                pq.push(profits[i]);
                i++;
            }
            if(pq.empty()) break; //防止出现死循环
            w+=pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};//我的思路还是很对的，也确实是最优解了，不过写的时候出现了很多小错误（注释过的基本都是）导致无法正确运行 头疼 
//这一题还有一个很好的解法：双堆法，非常值得学习：
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        // 小顶堆：按 capital 排序
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

        // 大顶堆：按 profit 排序
        priority_queue<int> maxHeap;

        for(int i = 0; i < n; i++){
            minHeap.push({capital[i], profits[i]});
        }

        while(k--){
            // 解锁所有可做项目
            while(!minHeap.empty() && minHeap.top().first <= w){
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }

            // 没项目可做
            if(maxHeap.empty()) break;

            // 选最大利润
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};