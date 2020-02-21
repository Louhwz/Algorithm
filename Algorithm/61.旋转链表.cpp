#include "headerfile.h"



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        ListNode* node = new ListNode(0);
        node->next = head;
        int listSize = 0;
        ListNode* p = node;
        while (p->next) {
            listSize++;
            p = p->next;
        }
        k %= listSize;
        //p现在指向next指针
        //0 1 2 3 4  listSize = 5   k = 2
        ListNode* q = node->next;
        ListNode* pre = node;
        for (int i = 0; i < listSize-k; i++) {
            q = q->next;
            pre = pre->next;
        }
        if (q != NULL)
        {
            p->next = node->next;
            node->next = q;
            pre->next = NULL;
        }
        return node->next;

    }
};