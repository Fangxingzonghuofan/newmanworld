class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int size=intervals.size();
        int left=newInterval[0],right=newInterval[1];
        bool flag=false;
        for(int i=0;i<size;i++){
            if(intervals[i][1]<left) res.push_back(intervals[i]);
            else if(intervals[i][0]>right) {
                if(!flag) {
                    res.push_back({left,right});
                    flag=true;
                }
                res.push_back(intervals[i]);
            }
            else{
                left=min(left,intervals[i][0]);
                right=max(right,intervals[i][1]);
            }
        }
        if(!flag) res.push_back({left,right});
        return res;
    }
};
//第一次写出来了，第二次反而呢不会写了，参考官方题解写出来的，思路很不错值得学习
