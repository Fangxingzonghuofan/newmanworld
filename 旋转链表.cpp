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
    ListNode* rotateRight(ListNode* head, int k) {
       ListNode *cur=head;
       int listlen=1;
       if (!cur||!cur->next)
       {
        return head;
       }
       while (cur->next)
       {
        listlen++;
        cur=cur->next;
       }
       k=k%listlen;
       if (k==0)
       {
        return head;
       }
       cur->next=head;
       cur=head;
       for (int i = 1; i < listlen-k; i++)
       {
        cur=cur->next;
       }
       head=cur->next;
       cur->next=nullptr;
       return head;
    }
};
//二刷，依旧链成环
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*cur=head;
        int nodeNum=1;
        while(cur->next){
            nodeNum++;
            cur=cur->next;
        }
        cur->next=head;
        cur=head;
        k=nodeNum-k%nodeNum;
        while(--k>0){
            cur=cur->next;
        }
        dummy->next=cur->next;
        cur->next=nullptr;
        return dummy->next;
    }
};
