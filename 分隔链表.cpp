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
    ListNode* partition(ListNode* head, int x) {
        if (!head||!head->next)
        {
            return head;
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *dummyP=dummy;
        ListNode *middle=new ListNode(-1);
        ListNode *middleP=middle;
        while (head)
        {
            ListNode *next=head->next;
            if (head->val<x)
            {
                dummyP->next=head;
                dummyP=head;
            }
            else {
                middleP->next=head;
                middleP=head;
            }
            head->next=nullptr;
            head=next;
        }
        dummyP->next=middle->next;
        return dummy->next;
    }
};