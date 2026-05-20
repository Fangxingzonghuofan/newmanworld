class Solution {
public:
    bool isValid(string s) {
        stack<char> kuohao;
        for(auto &i:s){
            if(i=='('||i=='['||i=='{') {
                kuohao.push(i);
                continue;
            }
            else if(kuohao.empty()) return false;
            else if(i==')'){
                if(kuohao.top()!='(') return false;
            }
            else if(kuohao.top()+2!=i) return false;
            kuohao.pop();            
        }
        if(!kuohao.empty()) return false;
        return true;
    }
};
