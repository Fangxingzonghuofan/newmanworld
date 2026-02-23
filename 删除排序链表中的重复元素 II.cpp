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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head||!head->next)
        {
            return head;
        }
        ListNode *pre=head;
        ListNode* cur=head->next;
        while (cur)
        {
            if (pre->val==cur->val)
            {
                pre->next=cur->next;
            }
            else{
                pre=cur;
            }
            cur=cur->next;
        }
        return head;
    }
};//题目又看错了
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head||!head->next)
        {
            return head;
        }
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *oknode=dummy;
        ListNode *pre=head;
        ListNode *cur=pre->next;
        while (cur)
        {
            if (pre->val==cur->val)
            {
                cur=cur->next;
            }
            else{
                if (pre->next==cur)
                {
                    oknode->next=pre;
                    oknode=pre;
                }
                pre=cur;
                cur=cur->next;
            }
        }
        if (pre->next==nullptr)
        {
            oknode->next=pre;
            oknode=pre;
        }
        oknode->next=nullptr;
        return dummy->next;
    }
};//贴一份更加规范的代码，看的我头疼，我们写的都没有释放无用的链表节点空间，这点需要注意
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0, head);

        ListNode* cur = dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};