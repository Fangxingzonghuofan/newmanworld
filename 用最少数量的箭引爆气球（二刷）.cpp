class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int pos=points.back()[0];
        int ans=1;
        for(int i=points.size()-2;i>=0;i--){
            if(points[i][1]<pos){
                pos=points[i][0];
                ans++;
            }
        }
        return ans;
    }
};
