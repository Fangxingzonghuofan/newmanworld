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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* pre=dummy;
        ListNode *cur=pre->next;
        ListNode*next;
        int rec=0;
        while (cur)
        {
            cur=cur->next;
            rec++;
        }
        rec=rec/k;
        cur=head;
        for (int j = 0; j < rec; j++)
        {
            for (int i =0; i <k-1; i++)
        {
            next=cur->next;
            cur->next=next->next;
            next->next=pre->next;
            pre->next=next;
        }
        if (j!=rec-1)
        {
            pre=cur;
            cur=cur->next;
        }
        }
        return dummy->next;     
    }
};