/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

#include <iostream>
#include <unordered_map>

struct RandomListNode {
    int label;
    RandomListNode* next;
    RandomListNode* random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode* head) {
        if (!head) {
            return NULL;
        }
        RandomListNode* p = new RandomListNode(head->label);
        std::unordered_map<RandomListNode*, RandomListNode*> dict;
        dict[head] = p;
    
        RandomListNode* src = head;
        RandomListNode* dest = p;
        while (src->next) {
            dest->next = new RandomListNode(src->next->label);
            dict[src->next] = dest->next;
            src = src->next;
            dest = dest->next;
        }
        dest = p;
        while (head) {
            if (head->random) {
                dest->random = dict[head->random];
            } else {
                dest->random = NULL;
            }
            head = head->next;
            dest = dest->next;
        }
        return p;
    }
};

