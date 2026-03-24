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
    ListNode *merge(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode *cur=&dummy;
        while (l1&&l2)
        {
            if (l1->val<l2->val)
            {
                cur->next=l1;
                l1=l1->next;
            }
            else
            {
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        if(l1) cur->next=l1;
        if(l2) cur->next=l2;
        return dummy.next;//借鉴前两题排序链表的思路
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int size=lists.size();
        while (size>1)
        {
            for (int i = 0; i < size/2; i++)
            {
                lists[i]=merge(lists[i],lists[size-1-i]);
            }
            size=(size+1)/2;
        }
        return lists[0];
    }
};