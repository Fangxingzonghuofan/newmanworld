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
//让我来写一下这一题来复习一下快速排序,每次写快排都要感觉大脑褶皱要被抚平了
class Solution {
    int partition(vector<int> &nums,int l,int r){
        int pivot=nums[r];
        int i=l;
        for (int j = l; j < r;j++)
        {
            if(nums[j]<pivot){
                swap(nums[j],nums[i]);
                i++;
            }
        }
        swap(nums[i],nums[r]);
        return i;
    }
    void quickSort(vector<int> &nums,int l,int r){
        if(l>=r) return;
        int p=partition(nums,l,r);
        quickSort(nums,l,p-1);
        quickSort(nums,p+1,r);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums,0,nums.size()-1);
        return nums[nums.size()-k];
    }
};//一开始就能想到的思路使用快速排序排好数组，再返回标号
//但是这么写会超出时间限制，原因是只需要排序部分即可；下面进行改进
class Solution {
    int partition(vector<int> &nums,int l,int r){
        int randIndex = l + rand() % (r - l + 1);
        swap(nums[randIndex], nums[r]);//随机化pivot，不然很容易超时
        int pivot=nums[r];
        int i=l;
        for (int j = l; j < r;j++)
        {
            if(nums[j]<pivot){
                swap(nums[j],nums[i]);
                i++;
            }
        }
        swap(nums[i],nums[r]);
        return i;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int target=n-k;
        int l=0,r=n-1;
        while (l<r)
        {
            int p=partition(nums,l,r);
            if(p==target) return nums[p];
            else if(p>target) r=p-1;
            else l=p+1;
        }
        return nums[target];
    }
};//运行时间2778ms，我真没招了吧，现在学习大根堆的做法，我觉得我得回趟宿舍拿书
class Solution {
public:
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        } 
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2 - 1; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        } 
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};
//我不行了吧，天才请放过老弟