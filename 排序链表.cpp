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
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=nullptr;
        while (fast&&fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;
        ListNode *l1=sortList(head);
        ListNode* l2=sortList(slow);
        return merge(l1,l2);
    }
    ListNode*merge(ListNode *l1,ListNode* l2){
        ListNode *dummy=new ListNode(0);
        ListNode *cur=dummy;
        while (l1&&l2)
        {
            if(l1->val<l2->val){
                cur->next=l1;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        if(l1) cur->next=l1;
        if(l2) cur->next=l2;
        return dummy->next;
    }
};//第一次做分治链表排序题，一点思路没有，不知道要用归并排序，照搬的ai的思路和做法，还在学习中.......