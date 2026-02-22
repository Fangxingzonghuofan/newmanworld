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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //这里用栈会很简单，只是空间复杂度为O(n)
        vector<int> stack_val;
        int record=1;
        ListNode *cur=head;
        while (record<=right)
        {
            if (record>=left)
            {
                stack_val.emplace_back(cur->val);
            }
            record++;
            cur=cur->next;
        }
        record=1;
        cur=head;
        while (record<=right)
        {
            if (record>=left)
            {
                cur->val=stack_val.back();
                stack_val.pop_back();
            }
            record++;
            cur=cur->next;
        }
        return head;
    }
};
//下面我将尝试O(1)解法
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* pre=dummy;//设置Dummy就可以统一left==0和>0时对pre的操作
        for (int i = 0; i < left-1; i++)
        {
            pre=pre->next;
        }
        ListNode *cur=pre->next;
        ListNode *next;
        for (int i = left; i <right; i++)
        {
            next=cur->next;
            cur->next=next->next;
            next->next=pre->next;
            pre->next=next;
        }
        return dummy->next;
        
    }
};