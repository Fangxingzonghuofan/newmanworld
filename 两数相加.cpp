/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int next=0;
        ListNode* head1=l1;
        int longer=0;
        ListNode* head2=l2;
        ListNode* tmp;
        while (l1!=nullptr||l2!=nullptr)
        {
            if (l1!=nullptr&&l2!=nullptr)
            {
                int sum=l1->val+l2->val+next;
                l1->val=l2->val=sum%10;
                next=sum/10;
                if (l1->next==nullptr&&l2->next==nullptr)
            {
                tmp=l2;
            }
                l1=l1->next;
                l2=l2->next;   
            }
            else if (l1==nullptr)
            {
                longer=2;
                break;
            }
            else if (l2==nullptr)
            {
                longer=1;
                break;
            }
        }
        if(longer==2){
            while (l2!=nullptr)
            {
                int sum=l2->val+next;
                l2->val=sum%10;
                next=sum/10;
                if (l2->next==nullptr)
                {
                    tmp=l2;
                }
                l2=l2->next;
            }
        }
        else if (longer==1)
        {
            while (l1!=nullptr)
            {
                int sum=l1->val+next;
                l1->val=sum%10;
                next=sum/10;
                if (l1->next==nullptr)
                {
                    tmp=l1;
                }
                l1=l1->next;
            }
        }
        if (next>0)
        {
            ListNode *newnode=new ListNode(next);
            if (longer==1)
            {
                tmp->next=newnode;
            }
            else {tmp->next=newnode;}
            newnode->next=nullptr;
        }
        return longer==1?head1:head2;
    }
};
//本来是想直接操作原链表的，但是这个方法一直在错，算了，写新链表吧
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int next=0;
        ListNode* head1=l1;
        int longer=0;
        ListNode* head2=l2;
        ListNode* newhead;
    }
};//重新写个蛋啊！给我改，疯狂改，终于改对了，码的O（1）解法！！！