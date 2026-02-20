
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
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==NULL)//用nullptr更好
        {
            return 0;
        }//这一段可以删掉
        ListNode *slow=head;
        ListNode *fast=head;
        while (fast!=NULL&&fast->next!=NULL)//用nullptr更好
        {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast)
            {
                return true;
            }
        }
        return false;
    }
};/*NULL 和 nullptr 的区别？
NULL 本质是 0，是宏定义，没有类型，可能导致函数重载歧义；
nullptr 是 C++11 引入的关键字，类型是 std::nullptr_t，只能转换为指针类型，避免歧义，因此更安全，推荐使用。*/