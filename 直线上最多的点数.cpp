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
    int maxPoints(vector<vector<int>>& points) {
        int size=points.size();
        if(size==1) return 1;
        int MAXP=2;
        for (int i = 0; i < size; i++)
        {
            for (int j = i+1; j <size; j++)
            {
                int thread=2;
                double k;
                if(points[j][0]!=points[i][0]) k=(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
                else  k=1;//在这里使用除法会有精度问题，应该改为乘法
                for (int t = j+1; t < size; t++)
                {
                    double k0;
                    if(points[j][0]!=points[t][0])  k0=(points[j][1]-points[t][1])/(points[j][0]-points[t][0]);
                    else  k0=1;
                    if(k==k0) thread++;
                }
                MAXP=max(MAXP,thread);
            }
        }
        return MAXP;
    }
};
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size=points.size();
        if(size==1) return 1;
        int MAXP=2;
        for (int i = 0; i < size; i++)
        {
            for (int j = i+1; j <size; j++)
            {
                int thread=2;
                int dy1=points[j][1]-points[i][1];
                int dx1=points[j][0]-points[i][0];
                for (int t = j+1; t < size; t++)
                {
                    int dy2=points[j][1]-points[t][1];
                    int dx2=points[j][0]-points[t][0];
                    if(dy1*dx2==dy2*dx1) thread++;
                    double k0;
                    //在算法中尽量避免除法，使用乘法
                }
                MAXP=max(MAXP,thread);
            }
        }
        return MAXP;
    }
};
//暴力解法，但是双百了，下面给出更好的解法
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int res = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            int same = 1;     // 与 i 重合的点
            int maxLine = 0;  // 当前 i 的最大共线数

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // ✅ 重合点
                if (dx == 0 && dy == 0) {
                    same++;
                    continue;
                }

                // ✅ 约分（核心）
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // ✅ 统一符号（关键细节！）
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                // 特殊：竖线
                if (dx == 0) dy = 1;
                // 特殊：横线
                if (dy == 0) dx = 1;

                string key = to_string(dx) + "/" + to_string(dy);

                mp[key]++;
                maxLine = max(maxLine, mp[key]);
            }

            res = max(res, maxLine + same);
        }

        return res;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};