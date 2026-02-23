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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //初看没有什么难度，直接上最简单的解法
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *cur=dummy;
        int rec=-1;
        while (cur)
        {
            rec++;
            cur=cur->next;
        }
        if (rec==1)
        {
            return NULL;
        }
        cur=dummy;
        int num=-1;
        while (cur&&num<rec-n-1)
        {
            num++;
            cur=cur->next;
        }
        cur->next=cur->next->next;
        return dummy->next;
    }
};