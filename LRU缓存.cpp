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
struct DlinkedNode
{
    int key,value;
    DlinkedNode *prev;
    DlinkedNode* next;
    DlinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}
    DlinkedNode(int _key,int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
};
class LRUCache {
public:
int cap;
int num=0;
DlinkedNode *head=new DlinkedNode(-1,-1);
DlinkedNode *tail=new DlinkedNode(-1,-1);
unordered_map<int,DlinkedNode*>mp;
    LRUCache(int capacity) {
        head->next=tail;
        tail->prev=head;
        cap=capacity;
        num=0;
    }
    int get(int key) {
        if (mp.count(key))
        {
            DlinkedNode *tmp=mp[key];
            tmp->prev->next=tmp->next;
            tmp->next->prev=tmp->prev;
            tmp->next=head->next;
            head->next->prev=tmp;
            head->next=tmp;
            tmp->prev=head;
            return tmp->value;
        }
        else return -1;
    }
    void put(int key, int value) {
        if (mp.count(key))
        {
            DlinkedNode *tmp=mp[key];
            tmp->value=value;
            tmp->prev->next=tmp->next;
            tmp->next->prev=tmp->prev;
            tmp->next=head->next;
            head->next->prev=tmp;
            head->next=tmp;
            tmp->prev=head;
        }
        else if (num<cap)
        {
            mp[key]=new DlinkedNode(key,value);
            DlinkedNode *tmp=mp[key];
            tmp->next=head->next;
            head->next->prev=tmp;
            head->next=tmp;
            tmp->prev=head;
            num++;
        }
        else if (num>=cap)
        {
            DlinkedNode *tmp=tail->prev;
            tmp->prev->next=tail;
            tail->prev=tmp->prev;//从链表进行移除
            mp.erase(tmp->key);//从哈希表中移除
            delete tmp;
            mp[key]=new DlinkedNode(key,value);
            tmp=mp[key];
            tmp->next=head->next;
            head->next->prev=tmp;
            head->next=tmp;
            tmp->prev=head;
        }
    }
};