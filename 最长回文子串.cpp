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
    int palindrome(string &s,int left,int right,int size){
        while (left>=0&&right<size&&s[left]==s[right])
        {
            left--;
            right++;
        }
        return right-left-1;
    }
public:
    string longestPalindrome(string s) {
        int size=s.size();
        int maxLen=1;
        string res(1,s[0]);//这里很重要！！！c++基础不太行啊还是
        for (int i = 0; i <size; i++)
        {
            int len1=palindrome(s,i-1,i+1,size),len2=1;
            if(i+1<size&&s[i]==s[i+1]) len2=palindrome(s,i-1,i+2,size);
            int len=max(len1,len2);
            if(len>maxLen){
                maxLen=len;
                res=s.substr(i-(len-1)/2,len);
            }
        }
        return res;
    }   
};