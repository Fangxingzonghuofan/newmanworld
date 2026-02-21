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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans;
        while (list1!=nullptr||list2!=nullptr)
        {
            int ansnum;
            if (list1!=nullptr&&list2!=nullptr)
            {
                ansnum=max(list1->val,list2->val);
            }
            else if (list1==nullptr)
            {
                ansnum=list2->val;
            }
            else if (list2==nullptr)
            {
                ansnum=list1->val;
            }
            ListNode *newnode=new ListNode(ansnum);
            ans->next=newnode;
            list1=list1->next;
            list2=list2->next;
        }
        return ans;
    }
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy=new ListNode(0);
        ListNode *ans=dummy;
        while (list1!=nullptr&&list2!=nullptr)
        {
            if (list1!=nullptr&&list2!=nullptr)
            {
                if (list1->val>list2->val)
                {
                    ans->next=list2;
                    list2=list2->next;
                }
                else{
                    ans->next=list1;
                    list1=list1->next;
                }
                ans=ans->next;
            }
        }
        if (list1==nullptr)
            {
                ans->next=list2;
            }
            else ans->next=list1;
        return dummy->next;
    }
};