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
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy=new Node(0);
        Node* copy=dummy;
        Node*head2=head;
        while (head!=nullptr)
        {
            Node *newnode=new Node(head->val);
            copy->next=newnode;
            copy=copy->next;
            head=head->next;
        }
        copy=dummy->next;
        head=head2;
        while (head!=nullptr)
        {
            copy->random=head->random;
            copy=copy->next;
            head=head->next;
        }
        return dummy->next;
    }
};//天菩萨，把这题想的太简单了，重写！
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* cur=head;
        while (cur)
        {
            mp[cur]=new Node(cur->val);
            cur=cur->next;
        }
        cur=head;
        while (cur)
        {
            mp[cur]->next=mp[cur->next];
            mp[cur]->random=mp[cur->random];
            cur=cur->next;
        }
        return mp[head];
    }
};//哈希表做法 太妙了，下面是O(1)解法
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node *cur = head;

        // 1. 插入复制节点
        while (cur)
        {
            Node *copynode = new Node(cur->val);
            copynode->next = cur->next;
            cur->next = copynode;
            cur = copynode->next;
        }

        // 2. 设置 random
        cur = head;
        while (cur)
        {
            if (cur->random)
                cur->next->random = cur->random->next;

            cur = cur->next->next;
        }

        // 3. 拆分链表
        cur = head;
        Node *newHead = head->next;

        while (cur)
        {
            Node *copy = cur->next;
            cur->next = copy->next;

            if (copy->next)
                copy->next = copy->next->next;

            cur = cur->next;
        }

        return newHead;
    }
};