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
//leetcodetop150已经刷到140多题了，不免还有些感慨
//当初写这一题的时候还是在用c语言的小萌新，在决定转用c++前，还下定了很大决心
//那时候才刷了十几题，也不知道自己能否坚持下来
//不过当初写这一题时候的痛苦还历历在目，今天决定再次挑战一下
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int rowSize=maxWidth;
        int w=words.size();
        int i=0;
        vector<string> res;
        while (i<w)
        {
            string rowWords;
            int p=i;
            while (p<w-1&&rowSize>=words[p].size())
            {
                rowSize-=words[p].size();
                p++;
                if(rowSize==0) break;
                rowSize--;
            }
            rowSize++;
            if(p==w-1&&rowSize>=words[p].size()){
                while (i<=p)
                {
                    rowWords.append(words[i]);
                    rowWords+=" ";
                    i++;
                }
                rowSize-=words[p].size();
                rowSize--;
                rowWords.pop_back();
                rowWords.append(rowSize,' ');
                res.push_back(rowWords);
                return res;
            }
            int wordNum=p-i;
            int spaceArr=0;
            int spaceL=0;
            if(wordNum!=1){
                spaceArr=(rowSize+wordNum-1)/(wordNum-1);
                spaceL=(rowSize+wordNum-1)%(wordNum-1);
            }
            while (i<p-1)
            {
                rowWords.append(words[i]);
                if(spaceL>0){
                    rowWords.append(spaceArr+1,' ');
                    spaceL--;
                }else rowWords.append(spaceArr,' ');  
                i++;
            }
            rowWords.append(words[i++]);
            if(wordNum==1) rowWords.append(rowSize+1,' ');
            res.push_back(rowWords);
            rowSize=maxWidth;
        }
        return res;
    } 
};//放弃了，当初没错怪自己，妈的现在写三个小时还是写不出来，草泥马草泥马草泥马草泥马，草你妈，再也不写这一题了再写我是傻逼