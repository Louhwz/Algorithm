#include "headerfile.h"


 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node = new ListNode(0);
        node->next = head;
        ListNode* p = node->next, * q = node->next;
        while (p != NULL) {
            while (p->next != NULL && p->next->val == p->val)
                p = p->next;
            p = p->next;
            q->next = p;
            q = p;

        }
        return node->next;
    }
};