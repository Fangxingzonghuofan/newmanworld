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
    string simplifyPath(string path) {
        string ans;
        vector<string> st;
        string name;
        for(int i=0;i<path.size();i++)
        {
            if (path[i]!='/')
            {
                name+=path[i];//name.push_back(i);也可以这么写
            }
            if(path[i]=='/'||i==path.size()-1){
                if (name=="..")
                {
                    if(!st.empty()) st.pop_back();
                }
                else if(name!="."&&!name.empty()){
                    st.push_back(name);
                }
                name.clear();//也可以写 name=""或者name=string()或者name=resize(0)
            }
        }
        for(auto &i:st){
            ans+='/';
            ans+=i;//ans.append(i);
        }
        if (ans.empty()) return "/";
        return ans;
    }
};